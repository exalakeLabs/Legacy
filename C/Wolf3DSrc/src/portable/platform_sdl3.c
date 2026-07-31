#include "wolf3d/platform.h"

#include <SDL3/SDL.h>
#include <stdlib.h>

struct wolf_platform {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    wolf_u32 argb[WOLF_SCREEN_WIDTH * WOLF_SCREEN_HEIGHT];
};

wolf_platform *wolf_platform_create(const char *title, int scale)
{
    wolf_platform *platform = calloc(1, sizeof(*platform));
    if (!platform || !SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD))
        goto failed;
    if (!SDL_CreateWindowAndRenderer(title, WOLF_SCREEN_WIDTH * scale,
                                     WOLF_SCREEN_HEIGHT * scale, 0,
                                     &platform->window, &platform->renderer))
        goto failed;
    platform->texture = SDL_CreateTexture(platform->renderer, SDL_PIXELFORMAT_ARGB8888,
                                          SDL_TEXTUREACCESS_STREAMING,
                                          WOLF_SCREEN_WIDTH, WOLF_SCREEN_HEIGHT);
    if (!platform->texture)
        goto failed;
    SDL_SetTextureScaleMode(platform->texture, SDL_SCALEMODE_NEAREST);
    SDL_SetRenderLogicalPresentation(platform->renderer, WOLF_SCREEN_WIDTH,
                                     WOLF_SCREEN_HEIGHT,
                                     SDL_LOGICAL_PRESENTATION_LETTERBOX);
    return platform;
failed:
    wolf_platform_destroy(platform);
    return NULL;
}

void wolf_platform_destroy(wolf_platform *platform)
{
    if (!platform)
        return;
    SDL_DestroyTexture(platform->texture);
    SDL_DestroyRenderer(platform->renderer);
    SDL_DestroyWindow(platform->window);
    SDL_Quit();
    free(platform);
}

bool wolf_platform_pump(wolf_platform *platform)
{
    (void)platform;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT ||
            (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE))
            return false;
    }
    return true;
}

void wolf_platform_present(wolf_platform *platform, const wolf_framebuffer *fb)
{
    wolf_fb_to_argb8888(fb, platform->argb, WOLF_SCREEN_WIDTH * WOLF_SCREEN_HEIGHT);
    SDL_UpdateTexture(platform->texture, NULL, platform->argb,
                      WOLF_SCREEN_WIDTH * (int)sizeof(platform->argb[0]));
    SDL_RenderClear(platform->renderer);
    SDL_RenderTexture(platform->renderer, platform->texture, NULL, NULL);
    SDL_RenderPresent(platform->renderer);
}

wolf_u64 wolf_platform_ticks_ns(void)
{
    return SDL_GetTicksNS();
}

void wolf_platform_delay(wolf_u32 milliseconds)
{
    SDL_Delay(milliseconds);
}
