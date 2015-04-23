include .knightos/variables.make

HEADERS:=$(wildcard *.h)
IMAGES:=$(wildcard img/*.png)
OBJECTS=$(OUT)crt0.o $(patsubst src/%.c,$(OUT)src/%.o,$(wildcard src/*.c))
OBJECTS+=$(patsubst img/%.png,$(OUT)img/%.o, $(IMAGES))
INCLUDE:=$(INCLUDE) -I include/

ALL_TARGETS:=$(BIN)pong

$(OUT)img/%.bin: img/%.png
	mkdir -p $(OUT)img
	kimg -m -b $< $@

$(OUT)img/%.o: $(OUT)img/%.bin
	scwrap $< $@ $$(basename -s .bin $<)_sprite

$(BIN)pong: $(OBJECTS)
	mkdir -p $(BIN)
	scas $(ASFLAGS) $(OBJECTS) $(LIBRARIES) -o $(BIN)pong

include .knightos/sdk.make
