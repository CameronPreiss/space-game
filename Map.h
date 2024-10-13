#ifndef MAP_H
#define MAP_H

#include "SpaceObject.h"
#include "Player.h"
#include <vector>

class Map {
public:
  Map();
  Map(std::string name);
  void addObject(SpaceObject* object);
  bool destroyObject(int index);
  int get_mapSize();
  int get_numObjects();
  Player* get_player();
  bool movePlayer(int direction[2]);
  void scan();
  void loadFromFile(int index);
  void saveToFile();
  void randomise();
  ~Map();
private:
  int mapSize;
  int numObjects;
  SpaceObject** spaceObjects;
  Player* player;
  int saveIndex;
};

#endif 
