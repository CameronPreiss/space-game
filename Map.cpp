#include "Map.h"

Map::Map(int mapSize) {
  this->numObjects = 0;
  this->mapSize = mapSize;
  this->spaceObjects = nullptr;
}
bool Map::addObject(SpaceObject* object) {
  if (this->numObjects < this->mapSize) {
    SpaceObject** tempObjects = new SpaceObject*[this->mapSize];
    for (int i = 0; i < this->numObjects; i++) {
      tempObjects[i] = this->spaceObjects[i];
    }
    tempObjects[this->numObjects] = object;
    delete[] this->spaceObjects;
    this->spaceObjects = tempObjects;
    this->numObjects++;
    return true;
  } else {
    return false;
  }
}
bool Map::destroyObject(int index) {
  if (index >= 0 && index < this->numObjects) {
    SpaceObject** tempObjects = new SpaceObject*[this->mapSize];
    for (int i = 0; i < index; i++) {
      tempObjects[i] = this->spaceObjects[i];
    }
    for (int i = index+1; i < this->numObjects; i++) {
      tempObjects[i-1] = this->spaceObjects[i];
    }
    delete[] this->spaceObjects;
    this->spaceObjects = tempObjects;
    this->numObjects--;
    return true;
  } else {
    return false;
  }
}
int Map::get_mapSize() {
  return this->mapSize;
}
int Map::get_numObjects() {
  return this->numObjects;
}
Map::~Map() {
  delete[] this->spaceObjects;
}
