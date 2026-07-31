#include "wolf3d/framebuffer.h"

#include <string.h>

void wolf_fb_clear(wolf_framebuffer *fb, wolf_u8 color)
{
    memset(fb->pixels, color, sizeof(fb->pixels));
}

void wolf_fb_plot(wolf_framebuffer *fb, int x, int y, wolf_u8 color)
{
    if ((unsigned)x < WOLF_SCREEN_WIDTH && (unsigned)y < WOLF_SCREEN_HEIGHT)
        fb->pixels[y * WOLF_SCREEN_WIDTH + x] = color;
}

void wolf_fb_bar(wolf_framebuffer *fb, int x, int y, int width, int height, wolf_u8 color)
{
    int left = x < 0 ? 0 : x;
    int top = y < 0 ? 0 : y;
    int right = x + width > WOLF_SCREEN_WIDTH ? WOLF_SCREEN_WIDTH : x + width;
    int bottom = y + height > WOLF_SCREEN_HEIGHT ? WOLF_SCREEN_HEIGHT : y + height;
    if (right <= left || bottom <= top)
        return;
    for (int row = top; row < bottom; ++row)
        memset(fb->pixels + row * WOLF_SCREEN_WIDTH + left, color, (size_t)(right - left));
}

void wolf_fb_set_palette(wolf_framebuffer *fb, const wolf_u8 *vga_palette)
{
    for (size_t i = 0; i < WOLF_PALETTE_SIZE; ++i)
        for (size_t component = 0; component < 3; ++component) {
            const unsigned v = vga_palette[i * 3 + component] & 63u;
            fb->palette[i][component] = (wolf_u8)((v << 2) | (v >> 4));
        }
}

void wolf_fb_set_fallback_palette(wolf_framebuffer *fb)
{
    static const wolf_u8 ega[16][3] = {
        {0,0,0},{0,0,42},{0,42,0},{0,42,42},{42,0,0},{42,0,42},{42,21,0},{42,42,42},
        {21,21,21},{21,21,63},{21,63,21},{21,63,63},{63,21,21},{63,21,63},{63,63,21},{63,63,63}
    };
    wolf_u8 palette[WOLF_PALETTE_SIZE * 3];
    for (unsigned i = 0; i < 16; ++i)
        memcpy(palette + i * 3, ega[i], 3);
    for (unsigned i = 16; i < WOLF_PALETTE_SIZE; ++i) {
        palette[i * 3] = (wolf_u8)(((i >> 5) & 7u) * 9u);
        palette[i * 3 + 1] = (wolf_u8)(((i >> 2) & 7u) * 9u);
        palette[i * 3 + 2] = (wolf_u8)((i & 3u) * 21u);
    }
    wolf_fb_set_palette(fb, palette);
}

void wolf_fb_to_argb8888(const wolf_framebuffer *fb, wolf_u32 *dest, size_t pixels)
{
    const size_t count = pixels < sizeof(fb->pixels) ? pixels : sizeof(fb->pixels);
    for (size_t i = 0; i < count; ++i) {
        const wolf_u8 *rgb = fb->palette[fb->pixels[i]];
        dest[i] = UINT32_C(0xff000000) | ((wolf_u32)rgb[0] << 16) |
                  ((wolf_u32)rgb[1] << 8) | rgb[2];
    }
}
