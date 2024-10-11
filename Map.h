#ifndef MAP_H
#define MAP_H

#include "SpaceObject.h"
#include "Player.h"

class Map {
public:
  Map(int mapSize);
  void addObject(SpaceObject* object);
  bool destroyObject(int index);
  int get_mapSize();
  int get_numObjects();
  Player* get_player();
  bool movePlayer(int direction[2]);
  std::vector<SpaceObject*> scan();
  ~Map();
private:
  int mapSize;
  int numObjects;
  SpaceObject** spaceObjects;
  Player* player;
};

#endif 
