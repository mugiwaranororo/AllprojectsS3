# Makefile

CC = gcc
CPPFLAGS =
CFLAGS = -Wall -Wextra -O3 `pkg-config --cflags sdl2`
LDFLAGS =
LDLIBS = `pkg-config --libs sdl2` -lm

all: plain plain_dynamic

SRC = plain.c plain_dynamic.c
OBJ = ${SRC:.c=.o}
EXE = ${SRC:.c=}

plain: plain.o
plain_dynamic: plain_dynamic.o

.PHONY: clean

clean:
	${RM} ${OBJ}
	${RM} ${EXE}

# END