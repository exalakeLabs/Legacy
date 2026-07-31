#include "wolf3d/framebuffer.h"
#include "wolf3d/paths.h"
#include "wolf3d/platform.h"

#include <stdio.h>
#include <string.h>

static const char *required_data[] = {
    "VSWAP", "VGAGRAPH", "VGAHEAD", "VGADICT",
    "GAMEMAPS", "MAPHEAD", "AUDIOT", "AUDIOHED"
};

static bool verify_data_variant(const char *directory, const char *extension, bool quiet)
{
    bool complete = true;
    char path[1024], name[64];
    for (size_t i = 0; i < sizeof(required_data) / sizeof(required_data[0]); ++i) {
        snprintf(name, sizeof(name), "%s.%s", required_data[i], extension);
        if (!wolf_find_data_file(directory, name, path, sizeof(path))) {
            if (!quiet)
                fprintf(stderr, "missing data file: %s\n", name);
            complete = false;
        }
    }
    return complete;
}

static bool verify_data(const char *directory)
{
    if (verify_data_variant(directory, "WL6", true)) {
        fprintf(stderr, "found Wolfenstein 3D registered data (.WL6)\n");
        return true;
    }
    if (verify_data_variant(directory, "WL1", true)) {
        fprintf(stderr, "found Wolfenstein 3D shareware data (.WL1)\n");
        return true;
    }
    fprintf(stderr, "no complete .WL6 or .WL1 data set found\n");
    verify_data_variant(directory, "WL6", false);
    return false;
}

int main(int argc, char **argv)
{
    const char *data_directory = ".";
    bool smoke_test = false;
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--data-dir") && i + 1 < argc)
            data_directory = argv[++i];
        else if (!strcmp(argv[i], "--verify-data"))
            return verify_data(data_directory) ? 0 : 2;
        else if (!strcmp(argv[i], "--smoke-test"))
            smoke_test = true;
        else {
            fprintf(stderr, "usage: %s [--data-dir PATH] [--verify-data] [--smoke-test]\n", argv[0]);
            return 2;
        }
    }
    verify_data(data_directory);

    wolf_platform *platform = wolf_platform_create("Wolfenstein 3D portable", 4);
    if (!platform) {
        fprintf(stderr, "could not initialize SDL3\n");
        return 1;
    }
    wolf_framebuffer fb = {0};
    for (unsigned i = 0; i < WOLF_PALETTE_SIZE; ++i) {
        fb.palette[i][0] = (wolf_u8)i;
        fb.palette[i][1] = (wolf_u8)(i / 2);
        fb.palette[i][2] = (wolf_u8)(255 - i);
    }

    const wolf_u64 tick_period = UINT64_C(1000000000) / 70;
    wolf_u64 previous = wolf_platform_ticks_ns();
    wolf_u64 accumulator = 0;
    unsigned ticks = 0;
    bool running = true;
    while (running) {
        const wolf_u64 now = wolf_platform_ticks_ns();
        accumulator += now - previous;
        previous = now;
        while (accumulator >= tick_period) {
            accumulator -= tick_period;
            ++ticks;
        }
        wolf_fb_clear(&fb, (wolf_u8)(ticks / 2));
        wolf_fb_bar(&fb, 32, 76, 256, 48, (wolf_u8)(ticks + 64));
        running = wolf_platform_pump(platform);
        wolf_platform_present(platform, &fb);
        if (smoke_test)
            running = false;
        wolf_platform_delay(1);
    }
    wolf_platform_destroy(platform);
    return 0;
}
