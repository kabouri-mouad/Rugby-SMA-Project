SRC=Ballon.cpp Joueur.cpp SimulationRugby.cpp main.cpp
#SRC=$(wildcard *.cpp)
EXE=cpp5

CXXFLAGS+=-Wall -Wextra -MMD -g -O2
LDFLAGS=-IC:\SFML-2.6.1\include -LC:\SFML-2.6.1\lib -lsfml-graphics -lsfml-window -lsfml-system

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/mt19937ar.o: mt19937ar.c
	@mkdir -p build
	gcc -o $@ -c $<

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch $(EXE)

-include $(DEP)
