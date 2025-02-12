#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


#include "inc/config.h"
#include "inc/celda.h"
#include "inc/graficos.h"
#include "inc/bola.h"


int main() {
    SDL_Event e;
    int       run = 1;

    graficos_init();
    celda_init(ANCHO/ANCHO_CELDA, ALTO/ALTO_CELDA);
    bola_init(1, 1);

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
                }
            }
        } /* while (SDL_PollEvent()) */

        graficos_imprime();

        //SDL_SetRenderDrawColor(rnd, 0, 0, 0, SDL_ALPHA_OPAQUE);
        //SDL_RenderClear(rnd);

        //filledCircleColor(rnd, 300, 300, 20, 0xFFFFFFFF);

        //SDL_RenderPresent(rnd);
        //SDL_Delay(10);

    } /* while (run) */
    
    graficos_end();
    celda_end();

    return 0;
}
