#ifndef MAP_H
#define MAP_H

#include "SpaceObject.h"
#include "Player.h"
#include <vector>

class Map {
public:
  //default constructor and normal constructor
  Map();
  Map(std::string name);

  //addObject, takes a pointer to SpaceObject and adds it to the map
  void addObject(SpaceObject* object);

  //destroyObject, takes an input of the object (in the spaceObjects array) that will be destroyed
  //returns a boolean whether removing was successful or not
  bool destroyObject(SpaceObject* object);

  //getters
  int get_mapSize();
  int get_numObjects();
  Player* get_player();
  int get_saveIndex();

  //moves the player to a different position in the map
  void movePlayer();

  //scans all the nearby spaceObjects within the scanning radius
  void scan();

  //loads an external file that has previous saves, takes the index of the file that will be loaded
  void loadFromFile(int index);

  //saves the current save to a file
  void saveToFile();

  //creates many random spaceObjects at random positions in the map
  void randomise();

  //destructor
  ~Map();
private:
  //attributes
  int mapSize;
  int numObjects;
  SpaceObject** spaceObjects;
  Player* player;
  int saveIndex;
};

#endif 
