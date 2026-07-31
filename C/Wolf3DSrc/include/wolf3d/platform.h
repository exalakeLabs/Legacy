#ifndef WOLF3D_PLATFORM_H
#define WOLF3D_PLATFORM_H

#include "wolf3d/framebuffer.h"

typedef struct wolf_platform wolf_platform;

wolf_platform *wolf_platform_create(const char *title, int scale);
void wolf_platform_destroy(wolf_platform *platform);
bool wolf_platform_pump(wolf_platform *platform);
void wolf_platform_present(wolf_platform *platform, const wolf_framebuffer *fb);
wolf_u64 wolf_platform_ticks_ns(void);
void wolf_platform_delay(wolf_u32 milliseconds);

#endif
