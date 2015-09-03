#include "palette.h"

#include <cmath>
#include <cstdlib>

#define SCL_COL(x) (127.0 + 127.0 * (x))

void palette_bw(SDL_PixelFormat *fmt, Palette *pal)
{
        for(int x = 0; x < PAL_SIZE; x++) {
                float grey = SCL_COL(sin(M_PI * x / 16.0));
                pal->colors[x] = SDL_MapRGB(fmt, (int)grey, (int)grey, (int)grey);
        }
}

bool palette_rainbow_rand(SDL_PixelFormat* fmt, Palette* pal)
{
        int rr = 3 + (rand() % 5),
            rg = 3 + (rand() % 5),
            rb = 3 + (rand() % 5);

        for(int x = 0; x < PAL_SIZE; x++) {
                float red =     SCL_COL(sin(M_PI * x / pow(rr, 2))),
                      green =   SCL_COL(sin(M_PI * x / pow(rg, 2))),
                      blue =    SCL_COL(sin(M_PI * x / pow(rb, 2)));

                pal->colors[x] = SDL_MapRGB(fmt, (int)red, (int)green, (int)blue);
        }

        return true;
}

void palette_rainbow(SDL_PixelFormat* fmt, Palette* pal)
{
        for(int x = 0; x < PAL_SIZE; x++) {
                float red =     SCL_COL(sin(M_PI * x / 16.0)),
                      green =   SCL_COL(sin(M_PI * x / 32.0)),
                      blue =    SCL_COL(sin(M_PI * x / 128.0));
                pal->colors[x] = SDL_MapRGB(fmt, (int)red, (int)green, (int)blue);
        }
}


