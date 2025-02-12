#include <SDL2/SDL.h>

#include "inc/bola.h"

typedef struct _bola {
    int px, py;   /* posición (píxeles) */
    int pdx, pdy; /* velocidad (píxeles) */
    int pr;       /* radio (píxeles */
    SDL_Color color;
} bola;

typedef enum _color_bola {
    BLANCA,
    NEGRA
} color_bola;

static bola array_bolas[BOLA_NMAX_BOLAS];
static int  num_bolas = 0;


/* Declaración de funciones esticas */

static void bola_crear_bola(color_bola c);



void bola_init(int n_blancas, int n_negras) {
    int i;

    while (n_blancas + n_negras > BOLA_NMAX_BOLAS) {
        if ((n_blancas > 1) && (n_blancas >= n_negras))
            n_blancas--;
        else if ((n_negras > 1) && (n_negras >= n_blancas))
            n_negras--;
    }

    for (i = 0; i < n_blancas; i++) {
        bola_crear_bola(BLANCA);
    }

    for (i = 0; i < n_negras; i++) {
        bola_crear_bola(NEGRA);
    }
}

int bola_obtener_num_bolas() {
    return num_bolas;
}

SDL_Color bola_obtener_color(int i) {
    return array_bolas[i].color;
}

void bola_obtener_posiciones(int i, int *px, int *py) {
    *px = array_bolas[i].px;
    *py = array_bolas[i].py;
}

void bola_obtener_velocidad(int i, int *pdx, int *pdy) {
    *pdx = array_bolas[i].pdx;
    *pdy = array_bolas[i].pdy;
}

int bola_obtener_radio(int i) {
    return array_bolas[i].pr;
}

/* Implementación de funciones estáticas */

void bola_crear_bola(color_bola c) {
    SDL_Color blanco = {0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE};
    SDL_Color negro  = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};

    bola b;
    b.pr = BOLA_DEF_RAD;

    if (num_bolas >= BOLA_NMAX_BOLAS)
        return;

    if (c == BLANCA) {
        b.px    = BOLA_B_DEF_PX;
        b.py    = BOLA_B_DEF_PY;
        b.color = blanco;
    }
    else if (c == NEGRA) {
        b.px    = BOLA_N_DEF_PX;
        b.py    = BOLA_N_DEF_PY;
        b.color = negro;
    }

    array_bolas[num_bolas] = b;

    num_bolas++;
}
