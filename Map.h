#ifndef MAP_H
#define MAP_H

#include "SpaceObject.h"
#include "Player.h"
#include <vector>

class Map {
public:
  Map();
  void addObject(SpaceObject* object);
  bool destroyObject(int index);
  int get_mapSize();
  int get_numObjects();
  Player* get_player();
  bool movePlayer(int direction[2]);
  std::vector<SpaceObject*> scan();
  void loadFromFile(int index);
  void saveToFile();
  ~Map();
private:
  int mapSize;
  int numObjects;
  SpaceObject** spaceObjects;
  Player* player;
  int saveIndex;
};

#endif 
