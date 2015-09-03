#ifndef PALETTE_H
#define PALETTE_H

#include <SDL2/SDL.h>

#define PAL_SIZE 256

typedef struct Palette
{
        uint32_t colors[PAL_SIZE];
} Palette;

void palette_bw(SDL_PixelFormat *fmt, Palette *pal);
void palette_rainbow(SDL_PixelFormat *fmt, Palette *pal);
bool palette_rainbow_rand(SDL_PixelFormat* fmt, Palette* pal);

#endif // PALETTE_H
