CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Source files, object files, and executable name
SOURCES = main.cpp CargoShip.cpp CombatShip.cpp Interface.cpp Map.cpp Planet.cpp Player.cpp Ship.cpp SpaceObject.cpp ItemSet.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = spacegame

# Default rule: build the executable from object files
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: clean

