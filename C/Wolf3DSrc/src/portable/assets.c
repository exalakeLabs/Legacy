#include "wolf3d/assets.h"

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
