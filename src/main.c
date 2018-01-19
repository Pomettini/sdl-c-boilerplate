#include "gfx.c"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[]) 
{
    context_t *ctx = gfx_init(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (1) 
    {
        if (SDL_PollEvent(ctx->event) && ctx->event->type == SDL_QUIT)
            break;

        gfx_clear(ctx, COLOR_BLACK);
        gfx_putpixel(ctx, 20, 10, COLOR_GREEN);
        gfx_update(ctx);
    }

    gfx_destroy(ctx);

    return 0;
}