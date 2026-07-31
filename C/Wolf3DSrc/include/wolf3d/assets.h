#ifndef WOLF3D_ASSETS_H
#define WOLF3D_ASSETS_H

#include "wolf3d/port.h"

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

#endif
