#ifndef BOLA_H_
#define BOLA_H_

#include "config.h"

#define BOLA_NMAX_BOLAS 10
#define BOLA_DEF_RAD    20

/* TODO: Estos valores dependenrán del tamaño de la ventana */
#define BOLA_B_DEF_PX   ANCHO/2
#define BOLA_B_DEF_PY   ALTO - 50
#define BOLA_N_DEF_PX   ANCHO/2
#define BOLA_N_DEF_PY   ALTO - (ALTO - 50)

void      bola_init(int n_blancas, int n_negras);
int       bola_obtener_num_bolas();
SDL_Color bola_obtener_color(int i);
void      bola_obtener_posiciones(int i, int *px, int *py);
int       bola_obtener_radio(int i);

#endif
