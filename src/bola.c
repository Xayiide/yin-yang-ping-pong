#include <SDL2/SDL.h>
#include <stdio.h>  /* NULL      */
#include <time.h>   /* time      */
#include <stdlib.h> /* rand, abs */

#include "inc/config.h"
#include "inc/bola.h"
#include "inc/animacion.h"

#define BOLA_NMAX_BOLAS  10
#define BOLA_DEF_TAMANIO 20

/* TODO: Estos valores dependenrán del tamaño de la ventana */
#define BOLA_B_DEF_PX   ANCHO/2
#define BOLA_B_DEF_PY   ALTO - 50
#define BOLA_N_DEF_PX   ANCHO/2
#define BOLA_N_DEF_PY   ALTO - (ALTO - 50)
#define BOLA_B_DEF_VX      -1
#define BOLA_B_DEF_VY      -1
#define BOLA_N_DEF_VX       1
#define BOLA_N_DEF_VY       1


static bola array_bolas[BOLA_NMAX_BOLAS];
static int  num_bolas = 0;


/* Declaración de funciones esticas */

static void bola_crear_bola(color c);
static void bola_imprimir_bola(bola b, SDL_Renderer *rnd);
static void bola_velocidad_aleatoria(int *vx, int *vy);

/* Implementación de funciones de cabecera */

void bola_init(int n_blancas, int n_negras) {
    int i;
    srand(time(NULL));

    while (n_blancas + n_negras > BOLA_NMAX_BOLAS) {
        if ((n_blancas > 1) && (n_blancas >= n_negras))
            n_blancas--;
        else if ((n_negras > 1) && (n_negras >= n_blancas))
            n_negras--;
    }

    for (i = 0; i < n_blancas; i++) {
        bola_crear_bola(BLANCO);
    }

    for (i = 0; i < n_negras; i++) {
        bola_crear_bola(NEGRO);
    }
}

void bola_imprimir_bolas(SDL_Renderer *rnd) {
    int i;

    for (i = 0; i < num_bolas; i++) {
        bola_imprimir_bola(array_bolas[i], rnd);
    }
}

void bola_actualizar() {
    int i;

    for (i = 0; i < num_bolas; i++) {
        anim_mover_bola(&array_bolas[i]);
    }
}

/* Implementación de funciones estáticas */

void bola_crear_bola(color c) {
    SDL_Color blanco = {0x6B, 0x11, 0x59, SDL_ALPHA_OPAQUE};
    SDL_Color negro  = {0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE};

    bola b;
    b.rect.w = BOLA_DEF_TAMANIO;
    b.rect.h = BOLA_DEF_TAMANIO;

    if (num_bolas >= BOLA_NMAX_BOLAS)
        return;

    if (c == BLANCO) {
        b.rect.x = BOLA_B_DEF_PX;
        b.rect.y = BOLA_B_DEF_PY;
        bola_velocidad_aleatoria(&b.vx, &b.vy);
        b.color = blanco;
    }
    else if (c == NEGRO) {
        b.rect.x = BOLA_N_DEF_PX;
        b.rect.y = BOLA_N_DEF_PY;
        bola_velocidad_aleatoria(&b.vx, &b.vy);
        b.color = negro;
    }

    array_bolas[num_bolas] = b;

    num_bolas++;
}

void bola_imprimir_bola(bola b, SDL_Renderer *rnd) {
    SDL_SetRenderDrawColor(rnd, b.color.r, b.color.g, b.color.b, b.color.a);
    SDL_RenderFillRect(rnd, &b.rect);
}

void bola_velocidad_aleatoria(int *vx, int *vy) {

    /* Velocidad en x */
    if (rand() % 2 == 0) {
       *vx = (rand() % 2) + 1;
    }
    else {
       *vx = -(rand() % 2) - 1;
    }

    /* Velocidad en y */
    if (rand() % 2 == 0) {
        *vy = (rand() % 2) + 1;
    }
    else {
        *vy = -(rand() % 2) - 1;
    }

}
