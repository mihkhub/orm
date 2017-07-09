CXXC=g++
CXXFLAGS=-std=gnu++11 -O0 -Wall -g -msse4.2
BIN=$(shell basename `pwd`)
all: $(BIN)

$(BIN):	$(BIN).cc
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(BIN)
