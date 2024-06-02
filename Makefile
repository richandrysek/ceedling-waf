
CC=gcc
CFLAGS=-I./src
BUILD_DIR = build
SOURCES = components/mcal/src/led.c \
	components/mcal/src/gpio.c \
	components/app/src/main.c

all: checkdirs $(BUILD_DIR)/hellomake

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

$(BUILD_DIR)/hellomake: $(SOURCES)
	$(CC) -o $@ $^ $(CFLAGS)