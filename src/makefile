# List of source files
SRC = Ballon.cpp Joueur.cpp EquipeRugby.cpp SimulationRugby.cpp main.cpp

# Declaration of variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SFML_INCLUDE = -IC:\SFML-2.6.1\include
SFML_LIB = -LC:\SFML-2.6.1\lib -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = mt19937ar.o

# Compilation rules
all: main

main: $(OBJECTS) $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(OBJECTS) -o main $(SFML_INCLUDE) $(SFML_LIB)
	@echo "Utilisez 'make run' pour executer l'application."

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

run: main
	./main

clean:
	del main.exe

	