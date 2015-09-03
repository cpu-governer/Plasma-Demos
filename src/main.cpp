#include <cmath>
#include <cstdlib>
#include <ctime>

#include <iostream>

#include <SDL2/SDL.h>

#include "palette.h"
#include "plasma.h"

#define DEF_LOG_SIZE_X 160
#define DEF_LOG_SIZE_Y 120

#define DEF_SCALE_FAC 4

#define DEF_PHYS_SIZE_X DEF_LOG_SIZE_X * DEF_SCALE_FAC
#define DEF_PHYS_SIZE_Y DEF_LOG_SIZE_Y * DEF_SCALE_FAC

#define torad(x) ( (x) * M_PI / 180.f)

#define sind(x) (sin(torad((x))))
#define cosd(x) (sin(torad((x))))
#define tand(x) (tan(torad((x))))

Palette pal;
Plasma plasma;

float dist(float, float, float, float);

void gen_plasma()
{
        printf("Generating plasma");
        for(int x = 0; x < DEF_LOG_SIZE_X; x++) {
                for(int y = 0; y < DEF_LOG_SIZE_Y; y++) {
                        float mag = 
                                127 + 127 * sin(x / 16.0) +
                                127 + 127 * sin(y / 32.0) +
                                127 + 127 * sin(dist(x, y, 0, 0) / 8.0) +
                                127 + 127 * sin(dist(x, y, 160, 120) / 8.0);

                        plasma.data[x + y * plasma.w] = (int)(mag / 3);
                }
        }
}

void vertical_line(SDL_Surface* surf, int x, int color)
{
        uint32_t *pixels = (uint32_t *) surf -> pixels;

        for(int i = 0; i < surf -> h; i++) {
                pixels[x + i * surf -> w] = color;
        }
}

void draw_plasma1(SDL_Surface* surf, int w, int h, int time)
{
        uint32_t *pixels = (uint32_t *)surf->pixels;

        int paletteShift = (int)(time / 10.f);

        for(int x = 0; x < w; x++) {
                for(int y = 0; y < h; y++) {
                        int pixel = pal.colors[(plasma.data[x + y * plasma.w] + paletteShift) % 256];
                        unsigned char r, g, b;
                        SDL_GetRGB(pixel, surf -> format, &r, &g, &b);
                        pixels[x + y * w] = SDL_MapRGB(surf -> format, (int)r, (int)g, (int)b);
                }
        }
}

int main(int argc, char** argv)
{
        SDL_Window* win = NULL;
        SDL_Surface* winsurf = NULL;
        SDL_Surface* logsurf = NULL;

        win = SDL_CreateWindow("Plasma", 
                        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                        DEF_PHYS_SIZE_X, DEF_PHYS_SIZE_Y, 
                        SDL_WINDOW_SHOWN);

        winsurf = SDL_GetWindowSurface(win);
        logsurf = SDL_CreateRGBSurface(0,
                        DEF_LOG_SIZE_X, DEF_LOG_SIZE_Y,
                        32,
                        0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);

        srand(time(NULL));
        palette_bw(logsurf->format, &pal);
        create_plasma(&plasma, DEF_LOG_SIZE_X, DEF_LOG_SIZE_Y);
        plasma_circle(&plasma);
        bool isRunning = true;
        while(isRunning) {
                SDL_Event ev;
                while(SDL_PollEvent(&ev)) {
                        if(ev.type == SDL_QUIT)
                                isRunning = false;
                }

                SDL_FillRect(logsurf, NULL, SDL_MapRGB(logsurf -> format, 0, 0, 0));
                draw_plasma1(logsurf, DEF_LOG_SIZE_X, DEF_LOG_SIZE_Y, SDL_GetTicks());
                SDL_BlitScaled(logsurf, NULL, winsurf, NULL);
                SDL_UpdateWindowSurface(win);
        }
}

