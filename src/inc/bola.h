#ifndef BOLA_H_
#define BOLA_H_

#include <SDL2/SDL.h> /* SDL_Renderer */

typedef struct _bola {
    int       vx, vy; /* velocidad (píxeles) */
    SDL_Rect  rect;
    SDL_Color color;
} bola;

void bola_init(int n_blancas, int n_negras);
void bola_imprimir_bolas(SDL_Renderer *rnd);
void bola_actualizar();

#endif
