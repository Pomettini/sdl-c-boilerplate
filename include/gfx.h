typedef struct context
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} context_t;

context_t *gfx_init();
void gfx_clear(context_t *);
void gfx_putpixel(context_t *, unsigned int, unsigned int, SDL_Color);
void gfx_update(context_t *);
void gfx_destroy(context_t *);