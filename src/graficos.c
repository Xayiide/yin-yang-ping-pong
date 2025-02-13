#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h> /* filledCirclecolor */
#include <stdio.h>                   /* fprintf */
#include <stdlib.h>                  /* exit    */

#include "inc/config.h"
#include "inc/graficos.h"
#include "inc/celda.h"
#include "inc/bola.h"

static SDL_Renderer *rnd;
static SDL_Window   *win;

/* Declaración de funciones estáticas */

static void graficos_imprime_celdas();
static void graficos_imprime_bolas();


/* Implementación de funciones de cabecera */

void graficos_init() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        fprintf(stderr, "Error al inicializar SDL.\n");
        exit(EXIT_FAILURE);
    }

    win = SDL_CreateWindow("Yin-Yang Ping Pong",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            ANCHO, ALTO, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        fprintf(stderr, "Error al crear la ventana.\n");
        exit(EXIT_FAILURE);
    }

    rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (rnd == NULL) {
        fprintf(stderr, "Error al crear el renderizador.\n");
        exit(EXIT_FAILURE);
    }

}

void graficos_end() {
    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void graficos_imprime() {
    SDL_SetRenderDrawColor(rnd, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(rnd);

    graficos_imprime_celdas();
    graficos_imprime_bolas();

    SDL_RenderPresent(rnd);
    SDL_Delay(10);
}



/* Implementación de funciones estáticas */

void graficos_imprime_celdas() {
    celda_imprimir_celdas(rnd);
}

void graficos_imprime_bolas() {
    bola_imprimir_bolas(rnd);
}
