#include "inc/errores.h"

#include <stdio.h>    /* fprintf   */
#include <execinfo.h> /* backtrace */
#include <signal.h>   /* signal */
#include <unistd.h>   /* STDERR_FILENO */
#include <stdlib.h>   /* exit */

static void manejador(int sig);

void errores_init() {
    signal(SIGSEGV, manejador);
}

void manejador(int sig) {
    void   *array[10];
    size_t  size;

    size = backtrace(array, 10);

    fprintf(stderr, "Error: señal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}



