#include <stdlib.h>    /* malloc */
#include <SDL2/SDL.h>  /* SDL_Color */

#include "inc/config.h"
#include "inc/celda.h"

#define FILAS        (ALTO/ALTO_CELDA)
#define COLUMNAS     (ANCHO/ANCHO_CELDA)
#define MAX_COLISION (((FILAS - 1) * COLUMNAS) + ((COLUMNAS - 1) * FILAS))

typedef struct _celda {
    SDL_Rect  rect;
    SDL_Color color;
} celda;

typedef struct _colisionables {
    SDL_Rect arr[MAX_COLISION];
    int      num_col;
} colisionables;

static celda         **mat_celdas;
static colisionables   colision_b;
static colisionables   colision_n;

/* Declaración de funciones estáticas */

static void celda_disposicion_inicial();
static void celda_imprimir_celda(celda c, SDL_Renderer *rnd);
static void inicializar_colisionables();


/* Implementación de funciones de cabecera */

void celda_init() {
    int i;

    /* Reservar espacio para la matriz de celdas */
    mat_celdas = malloc(sizeof(celda *) * FILAS);
    for (i = 0; i < FILAS; i++) {
        mat_celdas[i] = malloc(sizeof(celda) * COLUMNAS);
    }

    celda_disposicion_inicial();
    inicializar_colisionables();
}

void celda_end() {
    int i;

    for (i = 0; i < FILAS; i++)
        free(mat_celdas[i]);
    free(mat_celdas);
}

void celda_imprimir_celdas(SDL_Renderer *rnd) {
    int x, y;

    /* Obtener datos necesarios de celdas */
    for (y = 0; y < COLUMNAS; y++) {
        for (x = 0; x < FILAS; x++) {
            celda_imprimir_celda(mat_celdas[x][y], rnd);
        }
    }

}

colision celda_comprobar_colision(SDL_Rect *r, color c) {
    colision       ret = NONE;
    int            i = 0;
    colisionables *col;
    SDL_Rect       aux;


    if (c == BLANCO)
        col = &colision_b;
    else if (c == NEGRO)
        col = &colision_n;

    while (i < col->num_col && ret != 1) {
        aux = col->arr[i];
        if (SDL_HasIntersection(r, &aux) == SDL_TRUE) {
            if (c == BLANCO)
                ret = ARRIBA; /* TODO: Esto está hardcodeado para la disposición inicial */
            else if (c == NEGRO)
                ret = ABAJO;
        }
        i++;
    }

    return ret;
}

/* Implementación de funciones estáticas */

void celda_disposicion_inicial() {
    int x, y;

    SDL_Color blanco = {0x6B, 0x11, 0x59, SDL_ALPHA_OPAQUE};
    SDL_Color negro  = {0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE};

    /* La mitad superior de las celdas serán blancas; la inferior, negras */
    for (y = 0; y < COLUMNAS; y++) {
        for (x = 0; x < FILAS; x++) {
            mat_celdas[x][y].rect.x = x * ANCHO_CELDA;
            mat_celdas[x][y].rect.y = y * ANCHO_CELDA;
            mat_celdas[x][y].rect.w = ANCHO_CELDA;
            mat_celdas[x][y].rect.h = ALTO_CELDA;
            if (y < (COLUMNAS/2)) {
                mat_celdas[x][y].color = blanco;
            }
            else {
                mat_celdas[x][y].color = negro;
            }
        }
    }
}

void celda_imprimir_celda(celda c, SDL_Renderer *rnd) {
    SDL_SetRenderDrawColor(rnd, c.color.r, c.color.g, c.color.b, c.color.a);
    SDL_RenderFillRect(rnd, &c.rect);
}

/* TODO: esta función está hardcodeada */
void inicializar_colisionables() {
    int x;

    for (x = 0; x < COLUMNAS; x++) {
        colision_b.arr[x] = mat_celdas[x][4].rect;
        colision_b.num_col++;

        colision_n.arr[x] = mat_celdas[x][5].rect;
        colision_n.num_col++;

        //mat_celdas[x][4].color.r = 0xFF;
        //mat_celdas[x][4].color.g = 0x00;
        //mat_celdas[x][4].color.b = 0x00;

        //mat_celdas[x][5].color.r = 0x00;
        //mat_celdas[x][5].color.g = 0xFF;
        //mat_celdas[x][5].color.b = 0x00;
    }
}
