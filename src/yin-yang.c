#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define ANCHO 600
#define ALTO  600

#define ANCHO_CELDA 60
#define ALTO_CELDA  60


int main() {
    SDL_Event     e;
    SDL_Renderer *rnd = NULL;
    SDL_Window   *win = NULL;

    int run = 1;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        fprintf(stderr, "Error en la inicialización de SDL.\n");
        exit(EXIT_FAILURE);
    }

    win = SDL_CreateWindow("Yin-Yang Ping Pong",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            ANCHO, ALTO, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        fprintf(stderr, "Error en la creación de la ventana.\n");
        exit(EXIT_FAILURE);
    }

    rnd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (rnd == NULL) {
        fprintf(stderr, "Error en la creación del render.\n");
        exit(EXIT_FAILURE);
    }

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

        SDL_SetRenderDrawColor(rnd, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(rnd);

        filledCircleColor(rnd, 300, 300, 20, 0xFFFFFFFF);

        SDL_RenderPresent(rnd);
        SDL_Delay(10);

    } /* while (run) */
    
    SDL_DestroyRenderer(rnd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
