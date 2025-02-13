#include <SDL2/SDL.h>
#include <stdlib.h> /* abs */
#include <stdio.h> /* fprintf */

#include "inc/config.h"
#include "inc/animacion.h"
#include "inc/celda.h"
#include "inc/bola.h"

/* Declaración de funciones estáticas */

static int      color_es_blanco(SDL_Color c);
static void     mover_bola(bola *b, color c);
static colision comprobar_colisiones_paredes(bola b);
void            corregir_vel_y_pos_bola(bola *b, colision col);

/* Implementación de funciones de cabecera */

void anim_mover_bola(bola *b) {
    if (color_es_blanco(b->color) == 1) { /* Bola blanca */
        mover_bola(b, BLANCO);
    }
    else {
        mover_bola(b, NEGRO);
    }
}


/* Implementación de funciones estáticas */

int color_es_blanco(SDL_Color c) {
    int ret = 0;

    if (c.r == 0x6B && c.g == 0x11 && c.b == 0x59 && c.a == 0xFF)
        ret = 1;

    return ret;
}

void mover_bola(bola *b, color c) {
    colision col;
    bola     aux;

    /* Me creo una nueva bola con la posicion hipotetica de haber movido */
    aux.color  = b->color;
    aux.rect.h = b->rect.h;
    aux.rect.w = b->rect.w;
    aux.rect.x = b->rect.x + b->vx;
    aux.rect.y = b->rect.y + b->vy;
    aux.vx     = b->vx;
    aux.vy     = b->vy;

    /* Sólo comprobar colisiones de paredes si no ha habido de celda:
     * Puede que comprobar ambas colisiones en el mismo tick provoque que la
     * bola que colisiona en las esquinas se mueva el doble que las demás
     */
    col = celda_comprobar_colision(&aux.rect, c);
    if (col != NONE) {
        corregir_vel_y_pos_bola(b, col);
    }
    else { /* No hemos chocado con una celda */
        col = comprobar_colisiones_paredes(aux);
        if (col != NONE) {
            corregir_vel_y_pos_bola(b, col);
        }
        else { /* No hemos chocado ni con una celda ni con una pared */
            /* Asentamos el movimiento */
            b->rect.x = aux.rect.x;
            b->rect.y = aux.rect.y;
        }
    }
}

colision comprobar_colisiones_paredes(bola b) {
    colision ret = NONE;

    int izq, dch;
    int arr, abj;

    /* Las coordenadas x, y de SDL_Rect lo son de su vértice sup. izq */
    izq = b.rect.x;
    arr = b.rect.y;
    dch = b.rect.x + b.rect.w;
    abj = b.rect.y + b.rect.h;

    if (izq < 0) { /* Hemos chocado por la izquierda */
        ret = IZDA;
    }
    else if (dch > ANCHO) { /* Hemos chocado por la derecha */
        ret = DCHA;
    }
    else if (arr < 0) {
        ret = ARRIBA;
    }
    else if (abj > ALTO) { /* Hemos chocado por abajo */
        ret = ABAJO;
    }

    return ret;
}

void corregir_vel_y_pos_bola(bola *b, colision col) {

    /* TODO: Aquí surge un problema: Calculo la colisión con la nueva posición
     * hipotética. Si *habría* colisión, actúo como si ya la hubiera habido,
     * es decir, aunque la bola no haya tocado la pared (y dependiendo de la
     * velocidad puede estar más lejos o más cerca), voy a cambiar su dirección
     * y moverla en la otra. Esto va a poder verse con más claridad cuanto
     * mayor sea la velocidad.
     * Para corregir este problema habría que ver cuánto avanzaría y cuánto
     * rebotaría y ajusta la posición de acuerdo a esas distancias DESDE
     * EL PUNTO DONDE COLISIONARÍA
     * */

    /* No invertimos la velocidad para evitar aquellos casos en los que el
     * rectángulo ha entrado mucho dentro de la pared. Si en cada tick
     * invertimos la velocidad en lugar de poner la dirección correcta usando
     * abs(), corremos el riesgo de que el rectángulo quede atrapado en la
     * colisión, cambiando de dirección constantemente */

    switch (col) {
    case IZDA:
        /* Velocidad hacia la derecha */
        b->vx = abs(b->vx);
        b->rect.x += b->vx;
        break;
    case DCHA:
        /* Velocidad hacia la izquierda */
        b->vx = -abs(b->vx);
        b->rect.x += b->vx;
        break;
    case ARRIBA:
        /* Velocidad hacia abajo */
        b->vy = abs(b->vy);
        b->rect.y += b->vy;
        break;
    case ABAJO:
        /* Velocidad hacia arriba */
        b->vy = -abs(b->vy);
        b->rect.y += b->vy;
        break;
    case NONE:
        break;
    default:
        fprintf(stderr, "CASO DEFAULT en el SWITCH %s:%s:%d\n",
                __FILE__, __func__, __LINE__);
        break;
    }

}
