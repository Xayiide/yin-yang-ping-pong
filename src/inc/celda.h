#ifndef CELDA_MAIN_H_
#define CELDA_MAIN_H_

#include <SDL2/SDL.h> /* SDL_Renderer */
#include "config.h"

void      celda_init();
void      celda_end();
void      celda_imprimir_celdas(SDL_Renderer *);
colision  celda_comprobar_colision(SDL_Rect *r, color c);



#endif
