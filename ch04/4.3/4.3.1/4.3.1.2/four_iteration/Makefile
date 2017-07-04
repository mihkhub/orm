CC=gcc
CFLAGS=-O0 -Wall -g -std=gnu99 -msse4.2
LDLIBS=
BIN=$(shell basename `pwd`)
all: $(BIN)

$(BIN):	$(BIN).c util.o 
	$(CC) $(CFLAGS)  $^ -o $@ $(LDLIBS)

clean:
	$(RM) $(BIN) *.o

