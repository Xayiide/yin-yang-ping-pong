#include <stdlib.h>    /* malloc */
#include <SDL2/SDL.h>  /* SDL_Color */

#include "inc/celda.h"

typedef struct _celda {
    int x;
    int y;
    SDL_Color color;
} celda;

celda **mat_celdas;

static int filas;
static int columnas;


/* Declaración de funciones estáticas */

static void celda_disposicion_inicial();





/* Implementación de funciones de cabecera */

void celda_init(int ancho, int alto) {
    int i;

    filas    = alto;
    columnas = ancho;

    /* Reservar espacio para la matriz de celdas */
    mat_celdas = malloc(sizeof(celda *) * filas);
    for (i = 0; i < filas; i++) {
        mat_celdas[i] = malloc(sizeof(celda) * columnas);
    }

    celda_disposicion_inicial();
}

void celda_end() {
    int i;

    for (i = 0; i < filas; i++)
        free(mat_celdas[i]);
    free(mat_celdas);
}


SDL_Color celda_obtener_color(int x, int y) {
    SDL_Color ret;

    ret.r = mat_celdas[x][y].color.r;
    ret.g = mat_celdas[x][y].color.g;
    ret.b = mat_celdas[x][y].color.b;
    ret.a = mat_celdas[x][y].color.a;

    return ret;
}













/* Implementación de funciones estáticas */
void celda_disposicion_inicial() {
    int x, y;

    SDL_Color blanco = {0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE};
    SDL_Color negro  = {0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE};

    /* La mitad superior de las celdas serán blancas; la inferior, negras */
    for (y = 0; y < columnas; y++) {
        for (x = 0; x < filas; x++) {
            mat_celdas[x][y].x = x;
            mat_celdas[x][y].y = y;
            if (y < (columnas/2)) {
                mat_celdas[x][y].color = blanco;
            }
            else {
                mat_celdas[x][y].color = negro;
            }
        }
    }

}
