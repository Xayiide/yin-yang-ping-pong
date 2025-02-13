CC     = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic
LFLAGS = -lSDL2 -lSDL2_gfx

.PHONY: all clean re run


TGT  = yin-yang
SRCS = yin-yang.c celda.c graficos.c bola.c animacion.c errores.c
OBJS = $(SRCS:.c=.o)

all: $(TGT)

$(TGT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(TGT)

%.o: %.c
	$(CC) $(CFLAGS) $(LFLAGS) -c $^ -o $@


clean:
	@rm -f $(TGT) $(OBJS)
	@echo "limpio"

re: clean all

run: all
	./$(TGT)
