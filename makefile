CC:=gcc
CFLAG:=-Wall
CLIB:=-lSDL2
INCULDE:=

SRC:=main.c
OBJ:=$(SRC:.c=.o)

EXE:=sdl2-info

all: $(SRC) $(EXE)

run:
	./$(EXE)
	
$(EXE) : $(OBJ)
	$(CC) $(CFLAG) $(CLIB) $(OBJ) -o $(EXE)

$(OBJ) : $(SRC)
	$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

clean:
	rm $(OBJ)
	rm $(EXE)