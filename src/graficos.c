#include <SDL2/SDL.h>
#include <stdio.h>            /* fprintf */
#include <stdlib.h>           /* exit    */

#include "inc/config.h"
#include "inc/graficos.h"
#include "inc/celda.h"

static SDL_Renderer *rnd;
static SDL_Window   *win;

/* Declaración de funciones estáticas */

static void graficos_imprime_celdas();
static void graficos_imprime_celda(int x, int y, SDL_Color c);



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

    /* Imprime las celdas */
    graficos_imprime_celdas();
    /* Imprime las bolas */


    SDL_RenderPresent(rnd);
    SDL_Delay(10);
}



/* Implementación de funciones estáticas */

void graficos_imprime_celdas() {
    int       x, y;
    int       filas    = ALTO/ALTO_CELDA;
    int       columnas = ANCHO/ANCHO_CELDA;
    SDL_Color color;

    /* Obtener datos necesarios de celdas */
    for (y = 0; y < columnas; y++) {
        for (x = 0; x < filas; x++) {
            color = celda_obtener_color(x, y);
            graficos_imprime_celda(x, y, color);
        }
    }

}


void graficos_imprime_celda(int x, int y, SDL_Color color) {
    SDL_Rect rct;

    rct.x = x * ANCHO_CELDA;
    rct.y = y * ANCHO_CELDA;
    rct.w = ANCHO_CELDA;
    rct.h = ALTO_CELDA;

    SDL_SetRenderDrawColor(rnd, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(rnd, &rct);
}
