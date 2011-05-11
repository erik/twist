CC	:= g++
IFLAGS 	:= -I include/  -IBox2D/Box2D
CFLAGS	:= -Wall -Wextra -Wno-unused-parameter -std=c++98
DFLAGS	:= -g -DDEBUG

BOX2D   := Box2D/Box2D/Build/Box2D/libBox2D.a
LNFLAGS	:= -W,-L/usr/lib/local/ -lsfml-graphics -lsfml-window -lsfml-system $(BOX2D)
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

# fetches and builds box2d
box2d:
	wget http://box2d.googlecode.com/files/Box2D_v2.1.2.zip 
	unzip Box2D_v2.1.2.zip 
	mv Box2D_v2.1.2 Box2D
	cd Box2D/Box2D/Build && cmake  -DBOX2D_INSTALL=ON -DBOX2D_BUILD_SHARED=ON .. && make && \
rm ../../../Box2D_v2.1.2.zip 

.PHONY= clean
