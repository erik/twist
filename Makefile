CC	:= g++
IFLAGS 	:= -I include/
CFLAGS	:= -Wall -Wextra -Wno-unused-parameter -std=c++98
DFLAGS	:= -g -DDEBUG

LNFLAGS	:= -W,-L/usr/lib/local/ -lsfml-graphics -lsfml-window -lsfml-system
EXE 	:= twist-bin

.SUFFIXES=.cpp

SRC 	:= $(shell find 'src' -name '*.cpp' )
OBJ 	:= $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(IFLAGS) $(LNFLAGS) -o$(EXE)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXE)

debug:
	@$(MAKE) $(MFLAGS) CFLAGS="$(CFLAGS) $(DFLAGS)"

.PHONY= clean
