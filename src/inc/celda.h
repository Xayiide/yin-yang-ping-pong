#ifndef CELDA_MAIN_H_
#define CELDA_MAIN_H_

#include <SDL2/SDL.h>

void      celda_init(int ancho, int alto);
void      celda_end();
SDL_Color celda_obtener_color(int x, int y);

#endif
