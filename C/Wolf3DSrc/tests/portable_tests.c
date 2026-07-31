#include "wolf3d/assets.h"
#include "wolf3d/framebuffer.h"
#include "wolf3d/persistence.h"
#include "wolf3d/port.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_endian(void)
{
    const wolf_u8 bytes[] = { 0x34, 0x12, 0x56, 0x78 };
    assert(wolf_read_le16(bytes) == 0x1234);
    assert(wolf_read_le24(bytes) == 0x561234);
    assert(wolf_read_le32(bytes) == 0x78561234);
}

static void test_rlew(void)
{
    const wolf_u16 compressed[] = { 1, 0xabcd, 3, 7, 9 };
    wolf_u16 output[5] = {0};
    assert(wolf_rlew_expand(compressed, 5, output, 5, 0xabcd));
    const wolf_u16 expected[] = { 1, 7, 7, 7, 9 };
    assert(memcmp(output, expected, sizeof(expected)) == 0);
    assert(!wolf_rlew_expand(compressed, 4, output, 5, 0xabcd));
}

static void test_carmack(void)
{
    const wolf_u8 compressed[] = {
        1, 0, 2, 0, 2, 0xa7, 2
    };
    wolf_u16 output[4] = {0};
    const wolf_u16 expected[] = { 1, 2, 1, 2 };
    assert(wolf_carmack_expand(compressed, sizeof(compressed), output, 4));
    assert(memcmp(output, expected, sizeof(expected)) == 0);
}

static void test_huffman(void)
{
    wolf_huffnode table[255] = {{0}};
    table[254].bit0 = 256;
    table[254].bit1 = 'B';
    table[0].bit0 = 'A';
    table[0].bit1 = 'C';
    const wolf_u8 compressed[] = { 0x14 };
    wolf_u8 output[4];
    assert(wolf_huff_expand(compressed, sizeof(compressed), output, sizeof(output), table));
    assert(memcmp(output, "ABCA", 4) == 0);
}

static void test_framebuffer(void)
{
    wolf_framebuffer fb = {0};
    wolf_u8 palette[WOLF_PALETTE_SIZE * 3] = {0};
    wolf_u32 converted[1];
    palette[3] = 63;
    wolf_fb_set_palette(&fb, palette);
    wolf_fb_clear(&fb, 0);
    wolf_fb_plot(&fb, 0, 0, 1);
    wolf_fb_to_argb8888(&fb, converted, 1);
    assert(converted[0] == UINT32_C(0xffff0000));
    wolf_fb_bar(&fb, -5, -5, 8, 8, 2);
    assert(fb.pixels[2 * WOLF_SCREEN_WIDTH + 2] == 2);
}

static void test_persistence(void)
{
    const char *path = "portable-test-config.tmp";
    wolf_config first, second;
    wolf_config_defaults(&first);
    first.mouse_sensitivity = 9;
    assert(wolf_config_save(path, &first));
    assert(wolf_config_load(path, &second));
    assert(second.version == WOLF_CONFIG_VERSION);
    assert(second.mouse_sensitivity == 9);
    assert(remove(path) == 0);
}

int main(void)
{
    test_endian();
    test_rlew();
    test_carmack();
    test_huffman();
    test_framebuffer();
    test_persistence();
    puts("portable tests passed");
    return 0;
}
