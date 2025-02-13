
# Yin-Yang Ping Pong

Proyecto inspirado por [este](https://steamcommunity.com/app/3117780) juego
que encontré navegando por internet.

# Instrucciones de uso
## Ejecutar

```bash
make
make run
```

## Parar

La tecla <kbd>q</kbd> finaliza el programa.

# Requisitos/dependencias
## SDL2

Utilizaré la librería `SDL2` para los gráficos. Además, utilizaré también
`SDL2_gfx`, que aporta primitivas de `SDL2` para dibujar círculos, entre
otras tantas cosas.

### Instalar SDL2

Las instrucciones están en la
[Wiki de SDL2](https://wiki.libsdl.org/SDL2/Installation) aunque para Linux
se resume en hacer:

`sudo apt-get install libsdl2-dev`


### Instalar SDL2\_gfx

Las instrucciones están en la
[Wiki de SDL2\_gfx](https://www.ferzkopp.net/Software/SDL2_gfx/Docs/html/index.html)
aunque para linux se resume en hacer:

`sudo apt install libsdl2-gfx-dev`


### Incluir y enlazar SDL2 y SDL2\_gfx

incluir:  
```c
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
```

enlazar:  
`-lSDL2 -lSDL2_gfx`
