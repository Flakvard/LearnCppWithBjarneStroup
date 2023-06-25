SRC = use.cpp my.cpp
OBJ = use.o my.o
BIN := bin
HEADER := my.h
all: OBJ

OBJ: SRC
	g++ $(OBJ) -o $(BIN) -I $(HEADER)

SRC:
	g++ -Wall -c $(SRC)

clean:
	rm -f $(OBJ) $(BIN)