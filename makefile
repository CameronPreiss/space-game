CXX = g++
CXXFLAGS = # -I./include -std=c++11 -Wall

# Source files and executable name
SOURCES = main.cpp SpaceObject.cpp Planet.cpp Ship.cpp Player.cpp CombatShip.cpp CargoShip.cpp Map.cpp Ship.cpp Planet.cpp 
EXECUTABLE = spacegame

# Default rule
all: $(EXECUTABLE)

# Link the final executable
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Clean up
clean:
	rm -f $(EXECUTABLE)