#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

typedef struct context
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;
} context_t;

context_t *gfx_init(unsigned int width, unsigned int height);
void gfx_clear(context_t *, SDL_Color);
void gfx_putpixel(context_t *, unsigned int, unsigned int, SDL_Color);
void gfx_update(context_t *);
void gfx_destroy(context_t *);

#define COLOR_BLACK (SDL_Color) { 0, 0, 0, 0 }
#define COLOR_RED (SDL_Color) { 255, 0, 0, 0 }
#define COLOR_GREEN (SDL_Color) { 0, 255, 0, 0 }