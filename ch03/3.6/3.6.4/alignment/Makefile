CXXC=g++
BIN=$(shell basename `pwd`)
CXXFLAGS=-std=gnu++11 -O0 -Wall -g 
all: $(BIN)

$(BIN):	$(BIN).cc
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(BIN)
