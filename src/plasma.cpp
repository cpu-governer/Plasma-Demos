#include "plasma.h"

#include <cmath>
#include <cstdlib>

float dist(float x1, float y1, float x2, float y2)
{
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void create_plasma(Plasma* plasma, int w, int h)
{
        plasma->w = w;
        plasma->h = h;

        plasma->data = (int *) malloc(sizeof(int) * w * h);
}

void plasma_circle(Plasma* plasma)
{
        for(int x = 0; x < plasma->w; x++) {
                for(int y = 0; y < plasma->h; y++) {
                        float value = 
                                127.0 + 127.0 * sin(dist(x, y, plasma->w / 2, plasma->h / 2) / 16.0);
                        plasma->data[x + y * plasma->w] = (int)value;
                }
        }
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

