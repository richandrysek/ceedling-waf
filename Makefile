
CC=gcc
CFLAGS=-I./src
BUILD_DIR = build

all: checkdirs $(BUILD_DIR)/hellomake

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

$(BUILD_DIR)/hellomake: src/led.c src/gpio.c src/main.c
	$(CC) -o $@ $^ $(CFLAGS)