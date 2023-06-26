OBJ = calculator_exercise.o
SRC = calculator_exercise.cpp
BIN := calc
all:OBJ

OBJ:SRC
	g++ $(OBJ) -o $(BIN)

SRC:
	g++ -Wall -c $(SRC)

clean:
	rm -f $(OBJ) $(BIN)