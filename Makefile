CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: lucky-doors

lucky-doors: main.c
	$(CC) $(CFLAGS) main.c -o lucky-doors $(LIBS)

clean:
	rm -f lucky-doors
