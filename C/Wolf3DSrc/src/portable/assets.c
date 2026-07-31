#include "wolf3d/assets.h"

#include "wolf3d/paths.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool wolf_huff_expand(const wolf_u8 *source, size_t source_size,
                      wolf_u8 *dest, size_t dest_size,
                      const wolf_huffnode table[255])
{
    size_t source_pos = 0;
    wolf_u8 mask = 1;
    wolf_u8 value = 0;

    if ((!source && source_size) || (!dest && dest_size) || !table)
        return false;

    for (size_t out = 0; out < dest_size; ++out) {
        unsigned node = 254;
        for (;;) {
            if (mask == 1) {
                if (source_pos >= source_size)
                    return false;
                value = source[source_pos++];
            }
            const wolf_u16 code = (value & mask) ? table[node].bit1 : table[node].bit0;
            mask = (wolf_u8)(mask << 1);
            if (mask == 0)
                mask = 1;
            if (code < 256) {
                dest[out] = (wolf_u8)code;
                break;
            }
            node = (unsigned)(code - 256);
            if (node >= 255)
                return false;
        }
    }
    return true;
}

bool wolf_carmack_expand(const wolf_u8 *source, size_t source_size,
                        wolf_u16 *dest, size_t dest_words)
{
    enum { NEAR_TAG = 0xa7, FAR_TAG = 0xa8 };
    size_t in = 0, out = 0;

    while (out < dest_words) {
        if (in + 2 > source_size)
            return false;
        wolf_u16 value = wolf_read_le16(source + in);
        in += 2;
        const wolf_u8 tag = (wolf_u8)(value >> 8);
        const size_t count = value & 0xffu;

        if ((tag == NEAR_TAG || tag == FAR_TAG) && count == 0) {
            if (in >= source_size)
                return false;
            dest[out++] = (wolf_u16)((value & 0xff00u) | source[in++]);
            continue;
        }
        if (tag != NEAR_TAG && tag != FAR_TAG) {
            dest[out++] = value;
            continue;
        }
        if (count > dest_words - out)
            return false;

        size_t copy;
        if (tag == NEAR_TAG) {
            if (in >= source_size || source[in] == 0 || source[in] > out)
                return false;
            copy = out - source[in++];
        } else {
            if (in + 2 > source_size)
                return false;
            copy = wolf_read_le16(source + in);
            in += 2;
            if (copy >= out)
                return false;
        }
        for (size_t i = 0; i < count; ++i)
            dest[out++] = dest[copy++];
    }
    return true;
}

bool wolf_rlew_expand(const wolf_u16 *source, size_t source_words,
                     wolf_u16 *dest, size_t dest_words, wolf_u16 tag)
{
    size_t in = 0, out = 0;
    while (out < dest_words) {
        if (in >= source_words)
            return false;
        const wolf_u16 value = source[in++];
        if (value != tag) {
            dest[out++] = value;
            continue;
        }
        if (in + 2 > source_words)
            return false;
        const size_t count = source[in++];
        const wolf_u16 repeated = source[in++];
        if (count > dest_words - out)
            return false;
        for (size_t i = 0; i < count; ++i)
            dest[out++] = repeated;
    }
    return true;
}

static bool read_file(const char *path, wolf_u8 **data, size_t *size)
{
    FILE *file = fopen(path, "rb");
    long length;
    if (!file || fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) < 0 ||
        fseek(file, 0, SEEK_SET) != 0) {
        if (file) fclose(file);
        return false;
    }
    *data = malloc((size_t)length ? (size_t)length : 1);
    if (!*data || fread(*data, 1, (size_t)length, file) != (size_t)length) {
        free(*data);
        *data = NULL;
        fclose(file);
        return false;
    }
    fclose(file);
    *size = (size_t)length;
    return true;
}

bool wolf_graphics_open(wolf_graphics *graphics, const char *directory,
                        const char *extension)
{
    char name[64], path[1024];
    wolf_u8 *dictionary = NULL, *header = NULL;
    size_t dictionary_size = 0, header_size = 0;
    memset(graphics, 0, sizeof(*graphics));

    snprintf(name, sizeof(name), "VGADICT.%s", extension);
    if (!wolf_find_data_file(directory, name, path, sizeof(path)) ||
        !read_file(path, &dictionary, &dictionary_size) || dictionary_size < 255 * 4)
        goto failed;
    for (size_t i = 0; i < 255; ++i) {
        graphics->dictionary[i].bit0 = wolf_read_le16(dictionary + i * 4);
        graphics->dictionary[i].bit1 = wolf_read_le16(dictionary + i * 4 + 2);
    }

    snprintf(name, sizeof(name), "VGAHEAD.%s", extension);
    if (!wolf_find_data_file(directory, name, path, sizeof(path)) ||
        !read_file(path, &header, &header_size) || header_size % 3 != 0)
        goto failed;
    graphics->offset_count = header_size / 3;
    graphics->offsets = malloc(graphics->offset_count * sizeof(*graphics->offsets));
    if (!graphics->offsets)
        goto failed;
    for (size_t i = 0; i < graphics->offset_count; ++i)
        graphics->offsets[i] = wolf_read_le24(header + i * 3);

    snprintf(name, sizeof(name), "VGAGRAPH.%s", extension);
    if (!wolf_find_data_file(directory, name, path, sizeof(path)) ||
        !read_file(path, &graphics->archive, &graphics->archive_size))
        goto failed;
    free(dictionary);
    free(header);
    return true;
failed:
    free(dictionary);
    free(header);
    wolf_graphics_close(graphics);
    return false;
}

void wolf_graphics_close(wolf_graphics *graphics)
{
    if (!graphics) return;
    free(graphics->offsets);
    free(graphics->archive);
    memset(graphics, 0, sizeof(*graphics));
}

bool wolf_graphics_load_screen(const wolf_graphics *graphics, size_t chunk,
                               wolf_framebuffer *framebuffer)
{
    enum { PLANAR_SCREEN_SIZE = WOLF_SCREEN_WIDTH * WOLF_SCREEN_HEIGHT };
    wolf_u8 *planar = NULL;
    size_t next = chunk + 1;
    if (!graphics || !framebuffer || chunk >= graphics->offset_count ||
        graphics->offsets[chunk] == UINT32_C(0xffffff))
        return false;
    while (next < graphics->offset_count && graphics->offsets[next] == UINT32_C(0xffffff))
        ++next;
    if (next >= graphics->offset_count)
        return false;
    const size_t start = graphics->offsets[chunk];
    const size_t end = graphics->offsets[next];
    if (start + 4 > end || end > graphics->archive_size ||
        wolf_read_le32(graphics->archive + start) != PLANAR_SCREEN_SIZE)
        return false;
    planar = malloc(PLANAR_SCREEN_SIZE);
    if (!planar || !wolf_huff_expand(graphics->archive + start + 4, end - start - 4,
                                     planar, PLANAR_SCREEN_SIZE, graphics->dictionary)) {
        free(planar);
        return false;
    }
    for (size_t y = 0; y < WOLF_SCREEN_HEIGHT; ++y)
        for (size_t x = 0; x < WOLF_SCREEN_WIDTH; ++x)
            framebuffer->pixels[y * WOLF_SCREEN_WIDTH + x] =
                planar[(x & 3u) * (PLANAR_SCREEN_SIZE / 4) + y * 80 + (x >> 2)];
    free(planar);
    return true;
}

bool wolf_graphics_find_screen(const wolf_graphics *graphics, size_t first_chunk,
                               size_t *chunk)
{
    const wolf_u32 screen_size = WOLF_SCREEN_WIDTH * WOLF_SCREEN_HEIGHT;
    if (!graphics || !chunk) return false;
    for (size_t i = first_chunk; i < graphics->offset_count; ++i) {
        const wolf_u32 offset = graphics->offsets[i];
        if (offset != UINT32_C(0xffffff) && offset + 4 <= graphics->archive_size &&
            wolf_read_le32(graphics->archive + offset) == screen_size) {
            *chunk = i;
            return true;
        }
    }
    return false;
}
