CC     = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic
LFLAGS = -lSDL2main -lSDL2

.PHONY: all clean re run


TGT  = yin-yang
SRCS = yin-yang.c
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
