CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Source files, object files, and executable name
SOURCES = CargoShip.cpp CombatShip.cpp Interface.cpp Map.cpp Planet.cpp Player.cpp Ship.cpp SpaceObject.cpp ItemSet.cpp
MAINFILE = main.cpp
TESTFILE = testMain.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = spacegame
TESTEXECUTABLE = unitTests

# Default rule: build the executable from object files
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(MAINFILE) $(OBJECTS) -o $(EXECUTABLE)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Run unit tests
test:
	$(CXX) $(CXXFLAGS) $(TESTFILE) -o $(TESTEXECUTABLE) $(SOURCES)
	./unitTests

# Phony targets
.PHONY: clean
