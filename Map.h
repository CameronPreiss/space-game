#ifndef MAP_H
#define MAP_H

#include "SpaceObject.h"

class Map {
public:
  Map(int mapSize);
  bool addObject(SpaceObject* object);
  bool destroyObject(int index);
  int get_mapSize();
  int get_numObjects();
  ~Map();
private:
  int mapSize;
  int numObjects;
  SpaceObject** spaceObjects;
};

#endif 
