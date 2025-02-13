#ifndef CONFIG_H_
#define CONFIG_H_

typedef enum _color {
    BLANCO,
    NEGRO
} color;

typedef enum _colision {
    NONE,
    ARRIBA,
    ABAJO,
    IZDA,
    DCHA
} colision;

#define ANCHO 600
#define ALTO  600

#define ANCHO_CELDA 60
#define ALTO_CELDA  60


#endif
