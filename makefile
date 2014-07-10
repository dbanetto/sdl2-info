CC:=gcc
CFLAG:=-Wall -std=c11
CLIB:=-lSDL2
INCLUDE:=-Isrc

SRCDIR:=src
OBJDIR:=obj
SRC:=$(wildcard $(SRCDIR)/*.c)
OBJ:=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
EXE:=sdl2-info

all: $(SRC) $(EXE)

run:
	./$(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CFLAG) $(CLIB) $(OBJ) -o $(EXE)

$(OBJDIR)/%.o : $(SRCDIR)/%.c | dir
	$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

dir:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	rm $(EXE)
