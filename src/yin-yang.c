#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#define ANCHO 600
#define ALTO  600



int main() {
    SDL_Renderer *rnd = NULL;
    SDL_Window   *win = NULL;

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


}
