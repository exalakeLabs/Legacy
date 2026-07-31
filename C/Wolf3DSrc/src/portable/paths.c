#include "wolf3d/paths.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

bool wolf_path_join(char *dest, size_t size, const char *directory, const char *name)
{
    if (!dest || !size || !directory || !name)
        return false;
    const char separator = directory[0] && directory[strlen(directory) - 1] != '/' ? '/' : '\0';
    const int written = separator ? snprintf(dest, size, "%s/%s", directory, name)
                                  : snprintf(dest, size, "%s%s", directory, name);
    return written >= 0 && (size_t)written < size;
}

static bool regular_file(const char *path)
{
    struct stat info;
    return stat(path, &info) == 0 && S_ISREG(info.st_mode);
}

bool wolf_find_data_file(const char *directory, const char *dos_name,
                         char *dest, size_t size)
{
    char candidate[1024], folded[256];
    if (!directory || !dos_name || strlen(dos_name) >= sizeof(folded))
        return false;
    if (wolf_path_join(candidate, sizeof(candidate), directory, dos_name) && regular_file(candidate))
        return snprintf(dest, size, "%s", candidate) >= 0 && strlen(candidate) < size;

    for (int upper = 0; upper < 2; ++upper) {
        for (size_t i = 0; dos_name[i]; ++i)
            folded[i] = (char)(upper ? toupper((unsigned char)dos_name[i])
                                    : tolower((unsigned char)dos_name[i]));
        folded[strlen(dos_name)] = '\0';
        if (wolf_path_join(candidate, sizeof(candidate), directory, folded) && regular_file(candidate))
            return snprintf(dest, size, "%s", candidate) >= 0 && strlen(candidate) < size;
    }
    return false;
}

bool wolf_config_directory(char *dest, size_t size)
{
    const char *base = getenv("XDG_CONFIG_HOME");
    char fallback[1024];
    if (!base || !base[0]) {
        const char *user = getenv("HOME");
        if (!user || snprintf(fallback, sizeof(fallback), "%s/.config", user) < 0)
            return false;
        base = fallback;
    }
    return wolf_path_join(dest, size, base, "wolf3d-port");
}
