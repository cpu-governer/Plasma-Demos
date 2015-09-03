#ifndef PLASMA_H
#define PLASMA_H


typedef struct Plasma
{
        int* data, w, h;
} Plasma;

float dist(float, float, float, float);
void create_plasma(Plasma* plasma, int w, int h);
void plasma_basic(Plasma* plasma);
void plasma_circle(Plasma* plasma);

#endif // PLASMA_H
