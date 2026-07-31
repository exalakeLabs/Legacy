#ifndef WOLF3D_PATHS_H
#define WOLF3D_PATHS_H

#include "wolf3d/port.h"

bool wolf_path_join(char *dest, size_t size, const char *directory, const char *name);
bool wolf_find_data_file(const char *directory, const char *dos_name,
                         char *dest, size_t size);
bool wolf_config_directory(char *dest, size_t size);

#endif
