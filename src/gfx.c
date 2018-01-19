#include <gfx.h>

context_t* gfx_init(unsigned int width, unsigned int height)
{
    context_t *ctx = malloc(sizeof(context_t));

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &ctx->window, &ctx->renderer);

    return ctx;
}

void gfx_clear(context_t *ctx, SDL_Color color)
{
    SDL_SetRenderDrawColor(ctx->renderer, color.r, color.g, color.b, color.a);
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