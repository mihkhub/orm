CC=gcc
BIN=add
all: $(BIN)

$(BIN):	$(BIN).c
	$(CC) -std=gnu99 -O0 -Wall -g $^ -o $@

clean:
	$(RM) $(BIN)
