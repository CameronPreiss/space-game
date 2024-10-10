#include "Map.h"
#include <cstdlib>
#include <algorithm>
#include <vector>

Map::Map(int mapSize) {
  this->numObjects = 0;
  this->mapSize = mapSize;
  this->spaceObjects = nullptr;
  this->player = new Player;
}
void Map::addObject(SpaceObject* object) {
  SpaceObject** tempObjects = new SpaceObject*[this->numObjects+1];
  for (int i = 0; i < this->numObjects; i++) {
    tempObjects[i] = this->spaceObjects[i];
  }
  tempObjects[this->numObjects] = object;
  delete[] this->spaceObjects;
  this->spaceObjects = tempObjects;
  this->numObjects++;
}
bool Map::destroyObject(int index) {
  if (index >= 0 && index < this->numObjects) {
    SpaceObject** tempObjects = new SpaceObject*[this->numObjects-1];
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
Player* Map::get_player() {
  return this->player;
}
bool Map::movePlayer(int direction[2]) {
  int tempLocation[2] = {this->player->get_location()[0] + direction[0] * this->player->get_speed(), this->player->get_location()[1] + direction[1] * this->player->get_speed()};
  if (abs(tempLocation[0]) < this->mapSize && abs(tempLocation[1]) < this->mapSize) {
    this->player->move(tempLocation);
    return true;
  } else {
    return false;
  }
}
std::vector<SpaceObject*> Map::scan() {
  std::vector<SpaceObject*> nearby;
  for (int i = 0; i < this->numObjects; i++) {
    if (abs(this->player->get_location()[0] - this->spaceObjects[i]->get_location()[0]) <= this->player->get_scanRadius() && abs(this->player->get_location()[1] - this->spaceObjects[i]->get_location()[1]) <= this->player->get_scanRadius()) {
      nearby.push_back(this->spaceObjects[i]);
    }
  }
  return nearby;
}
Map::~Map() {
  delete[] this->spaceObjects;
  delete this->player;
}
