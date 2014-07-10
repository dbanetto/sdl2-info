CC:=gcc
CFLAG:=-Wall
CLIB:=-lSDL2
INCULDE:=

SRCDIR:=src
OBJDIR:=obj
SRC:=$(shell find $(SRCDIR) -type f -name '*.c')
OBJ:=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
EXE:=sdl2-info
all: $(SRC) $(EXE)

run:
	./$(EXE)

$(EXE) : $(OBJ)
	$(CC) $(CFLAG) $(CLIB) $(OBJ) -o $(EXE)

$(OBJ) : $(SRC) dir
	$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

dir:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	rm $(EXE)
