#ifndef WOLF3D_PERSISTENCE_H
#define WOLF3D_PERSISTENCE_H

#include "wolf3d/port.h"

enum { WOLF_CONFIG_VERSION = 1 };

typedef struct wolf_config {
    wolf_u32 version;
    wolf_i32 view_size;
    wolf_i32 mouse_sensitivity;
    wolf_i32 sound_volume;
    wolf_i32 music_volume;
    bool fullscreen;
} wolf_config;

void wolf_config_defaults(wolf_config *config);
bool wolf_config_load(const char *path, wolf_config *config);
bool wolf_config_save(const char *path, const wolf_config *config);

#endif
