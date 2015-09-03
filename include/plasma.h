#ifndef PLASMA_H
#define PLASMA_H


typedef struct Plasma
{
        int* data, w, h;
} Plasma;

void create_plasma(Plasma* plasma, int w, int h);
void plasma_basic(Plasma* plasma);

#endif // PLASMA_H
