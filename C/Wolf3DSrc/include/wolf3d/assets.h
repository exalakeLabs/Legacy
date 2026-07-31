#ifndef WOLF3D_ASSETS_H
#define WOLF3D_ASSETS_H

#include "wolf3d/port.h"
#include "wolf3d/framebuffer.h"

typedef struct wolf_huffnode {
    wolf_u16 bit0;
    wolf_u16 bit1;
} wolf_huffnode;

bool wolf_huff_expand(const wolf_u8 *source, size_t source_size,
                      wolf_u8 *dest, size_t dest_size,
                      const wolf_huffnode table[255]);
bool wolf_carmack_expand(const wolf_u8 *source, size_t source_size,
                        wolf_u16 *dest, size_t dest_words);
bool wolf_rlew_expand(const wolf_u16 *source, size_t source_words,
                     wolf_u16 *dest, size_t dest_words, wolf_u16 tag);

typedef struct wolf_graphics {
    wolf_huffnode dictionary[255];
    wolf_u32 *offsets;
    size_t offset_count;
    wolf_u8 *archive;
    size_t archive_size;
} wolf_graphics;

bool wolf_graphics_open(wolf_graphics *graphics, const char *directory,
                        const char *extension);
void wolf_graphics_close(wolf_graphics *graphics);
bool wolf_graphics_load_screen(const wolf_graphics *graphics, size_t chunk,
                               wolf_framebuffer *framebuffer);
bool wolf_graphics_find_screen(const wolf_graphics *graphics, size_t first_chunk,
                               size_t *chunk);

#endif
