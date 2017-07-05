CC=gcc
CFLAGS=-O3 -Wall -g -std=gnu99
LDLIBS=
BIN=$(shell basename `pwd`)
all: $(BIN)

$(BIN):	$(BIN).c
	$(CC) $(CFLAGS)  $^ -o $@ $(LDLIBS)

clean:
	$(RM) $(BIN)

