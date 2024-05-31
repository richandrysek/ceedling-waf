
CC=gcc
CFLAGS=-I./src

hellomake: src/led.c src/gpio.c src/main.c
	$(CC) -o hellomake src/led.c src/gpio.c src/main.c $(CFLAGS)