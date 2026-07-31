#ifndef WOLF3D_FRAMEBUFFER_H
#define WOLF3D_FRAMEBUFFER_H

#include "wolf3d/port.h"

enum { WOLF_SCREEN_WIDTH = 320, WOLF_SCREEN_HEIGHT = 200, WOLF_PALETTE_SIZE = 256 };

typedef struct wolf_framebuffer {
    wolf_u8 pixels[WOLF_SCREEN_WIDTH * WOLF_SCREEN_HEIGHT];
    wolf_u8 palette[WOLF_PALETTE_SIZE][3];
} wolf_framebuffer;

void wolf_fb_clear(wolf_framebuffer *fb, wolf_u8 color);
void wolf_fb_plot(wolf_framebuffer *fb, int x, int y, wolf_u8 color);
void wolf_fb_bar(wolf_framebuffer *fb, int x, int y, int width, int height, wolf_u8 color);
void wolf_fb_set_palette(wolf_framebuffer *fb, const wolf_u8 *vga_palette);
void wolf_fb_to_argb8888(const wolf_framebuffer *fb, wolf_u32 *dest, size_t pixels);

#endif
