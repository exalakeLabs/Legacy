#include "wolf3d/persistence.h"

#include <stdio.h>
#include <string.h>

void wolf_config_defaults(wolf_config *config)
{
    *config = (wolf_config){ WOLF_CONFIG_VERSION, 19, 5, 8, 8, false };
}

bool wolf_config_save(const char *path, const wolf_config *config)
{
    FILE *file = fopen(path, "wb");
    if (!file)
        return false;
    const int result = fprintf(file,
        "version=%u\nview_size=%d\nmouse_sensitivity=%d\nsound_volume=%d\n"
        "music_volume=%d\nfullscreen=%d\n",
        config->version, config->view_size, config->mouse_sensitivity,
        config->sound_volume, config->music_volume, config->fullscreen ? 1 : 0);
    return fclose(file) == 0 && result > 0;
}

bool wolf_config_load(const char *path, wolf_config *config)
{
    FILE *file = fopen(path, "rb");
    char line[128];
    wolf_config loaded;
    if (!file)
        return false;
    wolf_config_defaults(&loaded);
    while (fgets(line, sizeof(line), file)) {
        unsigned version;
        int value;
        if (sscanf(line, "version=%u", &version) == 1) loaded.version = version;
        else if (sscanf(line, "view_size=%d", &value) == 1) loaded.view_size = value;
        else if (sscanf(line, "mouse_sensitivity=%d", &value) == 1) loaded.mouse_sensitivity = value;
        else if (sscanf(line, "sound_volume=%d", &value) == 1) loaded.sound_volume = value;
        else if (sscanf(line, "music_volume=%d", &value) == 1) loaded.music_volume = value;
        else if (sscanf(line, "fullscreen=%d", &value) == 1) loaded.fullscreen = value != 0;
    }
    fclose(file);
    if (loaded.version != WOLF_CONFIG_VERSION)
        return false;
    *config = loaded;
    return true;
}
