#include "plasma.h"

#include <cmath>
#include <cstdlib>

void create_plasma(Plasma* plasma, int w, int h)
{
        plasma->w = w;
        plasma->h = h;

        plasma->data = (int *) malloc(sizeof(int) * w * h);
}

void plasma_basic(Plasma* plasma)
{
        for(int x = 0; x < plasma->w; x++) {
                for(int y = 0; y < plasma->h; y++) {
                        float value = 
                                127.0 + 127.0 * sin(M_PI * x / 32.0) +
                                127.0 + 127.0 * sin(M_PI * y / 32.0);
                        plasma->data[x + y * plasma->w] = (int)value / 2;
                }
        }
}

