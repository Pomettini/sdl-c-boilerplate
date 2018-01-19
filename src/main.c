#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <gfx.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define COLOR_RED (SDL_Color) { 255, 0, 0, 0 }

int main(int argc, char *argv[]) 
{
    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *renderer;

    context_t *ctx = gfx_init();

    while (1) 
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

        gfx_clear(ctx);
        gfx_putpixel(ctx, 20, 10, COLOR_RED);
        gfx_update(ctx);
    }

    gfx_destroy(ctx);

    return 0;
}

context_t* gfx_init()
{
    context_t *ctx = malloc(sizeof(context_t));

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &ctx->window, &ctx->renderer);

    return ctx;
}

void gfx_clear(context_t *ctx)
{
    SDL_SetRenderDrawColor(ctx->renderer, 0, 0, 0, 0);
    SDL_RenderClear(ctx->renderer);
}

void gfx_putpixel(context_t *ctx, unsigned int x, unsigned int y, SDL_Color color)
{
    SDL_SetRenderDrawColor(ctx->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(ctx->renderer, x, y);
}

void gfx_update(context_t *ctx)
{
    SDL_RenderPresent(ctx->renderer);
}

void gfx_destroy(context_t *ctx)
{
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    SDL_Quit();
}