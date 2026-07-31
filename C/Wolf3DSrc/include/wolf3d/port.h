#ifndef WOLF3D_PORT_H
#define WOLF3D_PORT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t  wolf_u8;
typedef int8_t   wolf_i8;
typedef uint16_t wolf_u16;
typedef int16_t  wolf_i16;
typedef uint32_t wolf_u32;
typedef int32_t  wolf_i32;
typedef uint64_t wolf_u64;
typedef wolf_i32 wolf_fixed;

_Static_assert(sizeof(wolf_u8) == 1, "8-bit byte required");
_Static_assert(sizeof(wolf_u16) == 2, "16-bit word required");
_Static_assert(sizeof(wolf_u32) == 4, "32-bit dword required");
_Static_assert(sizeof(wolf_u64) == 8, "64-bit timing value required");

static inline wolf_u16 wolf_read_le16(const void *address)
{
    const wolf_u8 *p = address;
    return (wolf_u16)((wolf_u16)p[0] | ((wolf_u16)p[1] << 8));
}

static inline wolf_u32 wolf_read_le24(const void *address)
{
    const wolf_u8 *p = address;
    return (wolf_u32)p[0] | ((wolf_u32)p[1] << 8) | ((wolf_u32)p[2] << 16);
}

static inline wolf_u32 wolf_read_le32(const void *address)
{
    const wolf_u8 *p = address;
    return (wolf_u32)p[0] | ((wolf_u32)p[1] << 8) |
           ((wolf_u32)p[2] << 16) | ((wolf_u32)p[3] << 24);
}

#endif
