#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


#include "inc/config.h"
#include "inc/celda.h"
#include "inc/graficos.h"
#include "inc/bola.h"
#include "inc/errores.h"


int main() {
    SDL_Event e;
    int       run = 1;

    errores_init();
    graficos_init();
    celda_init();
    bola_init(3, 3);

    while (run == 1) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                run = 0;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_q:
                        run = 0;
                        break;
                    default:
                        fprintf(stderr, "CASO DEFAULT en el SWITCH %s:%s:%d\n",
                                __FILE__, __func__, __LINE__);
                        break;
                }
            }
        } /* while (SDL_PollEvent()) */

        graficos_imprime();
        bola_actualizar();
    } /* while (run) */
    
    graficos_end();
    celda_end();

    return 0;
}
