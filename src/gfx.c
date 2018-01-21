#include <gfx.h>

context_t* gfx_init(unsigned int width, unsigned int height)
{
    context_t *ctx = malloc(sizeof(context_t));

    if(!ctx)
        return NULL;

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Unable to initialize SDL");
        gfx_destroy(ctx);
        return NULL;
    }

    if (SDL_CreateWindowAndRenderer(width, height, 0, &ctx->window, &ctx->renderer) != 0)
    {
        fprintf(stderr, "Unable to initialize Window or Renderer");
        gfx_destroy(ctx);
        return NULL;
    }

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
    free(ctx);
}