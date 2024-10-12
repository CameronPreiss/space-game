#include "Map.h"
#include "CargoShip.h"
#include "CombatShip.h"
#include "Planet.h"

#include <cstdlib>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <random>
#include <set>
#include <tuple>

namespace fs = std::filesystem;
using namespace std;

int numItems = 10;

Map::Map() {
  this->numObjects = 0;
  this->mapSize = 50;
  this->spaceObjects = nullptr;
  this->player = new Player;
  this->saveIndex = -1;
}
Map::Map(std::string name) {
  this->numObjects = 0;
  this->mapSize = 50;
  this->spaceObjects = nullptr;
  this->player = new Player(name);
  this->saveIndex = -1;
}
void Map::addObject(SpaceObject* object) {
  SpaceObject** tempObjects = new SpaceObject*[this->numObjects+1];
  for (int i = 0; i < this->numObjects; i++) {
    tempObjects[i] = this->spaceObjects[i];
  }
  tempObjects[this->numObjects] = object; delete[] this->spaceObjects;
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
void Map::loadFromFile(int index) {
  std::string filename = "./savefiles/savefile";
  filename += std::to_string(index);
  filename += ".txt";
  std::ifstream inFile(filename);
  if (!inFile) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return;
  }
  inFile >> this->mapSize;
  inFile >> this->numObjects;
  std::string name;
  int playerPos[2];
  int money;
  int* resources;
  int resourcesArraySize;
  int speed;
  int scanRadius;
  inFile >> name;
  inFile >> playerPos[0] >> playerPos[1];
  inFile >> money;
  inFile >> resourcesArraySize;
  resources = new int[resourcesArraySize];
  for (int i = 0; i < resourcesArraySize; i++) {
    inFile >> resources[i];
  }
  inFile >> speed;
  inFile >> scanRadius;
  this->player = new Player(name, playerPos, money, resourcesArraySize, resources, speed, scanRadius);
  this->spaceObjects = new SpaceObject*[this->numObjects];
  for (int i = 0; i < this->numObjects; i++) {
    std::string type;
    int location[2];
    std::string name;
    int size;
    inFile >> type;
    inFile >> location[0] >> location[1];
    inFile >> name;
    inFile >> size;
    if (type == "CargoShip") {
      int healthPoints;
      int damage;
      int* inventory;
      inFile >> healthPoints >> damage ;
      inventory = new int[numItems];
      for (int j = 0; j < numItems; j++) {
        inFile >> inventory[j];
      }
      this->spaceObjects[i] = new CargoShip(healthPoints, damage, inventory, numItems, name, location, size);
    }
    if (type == "CombatShip") {
      int healthPoints;
      int damage;
      int* inventory;
      inFile >> healthPoints >> damage;
      inventory = new int[numItems];
      for (int j = 0; j < numItems; j++) {
        inFile >> inventory[j];
      }
      this->spaceObjects[i] = new CombatShip(healthPoints, damage, inventory, numItems, name, location, size);
    }
    if (type == "Planet") {
      int population;
      int* prices = new int[numItems];
      std::string economyStatus;
      inFile >> population;
      prices = new int[numItems];
      for (int j = 0; j < numItems; j++) {
        inFile >> prices[j];
      }
      inFile >> economyStatus;
      this->spaceObjects[i] = new Planet(population, prices, numItems, economyStatus, location, name, size);
    }
  }
  inFile.close();
  this->saveIndex = index;
}
void Map::saveToFile() {
  if (this->saveIndex == -1) {
    int numSaves = 0;
    for (const auto& entry : fs::directory_iterator("./savefiles")) {
      // Check if the file follows the pattern "savefileX.txt"
      if (entry.is_regular_file()) {
        std::string filename = entry.path().filename().string();
        if (filename.find("savefile") == 0 && filename.find(".txt") == filename.length() - 4) {
          numSaves++;
        }
      }
    }
    this->saveIndex = numSaves;
  }
  std::string filename = "./savefiles/savefile";
  filename += std::to_string(this->saveIndex);
  filename += ".txt";
  std::ofstream outFile(filename);
  outFile << this->mapSize << std::endl;
  outFile << this->numObjects << std::endl;
  outFile << this->player->get_name() << std::endl;
  outFile << this->player->get_location()[0] << std::endl << this->player->get_location()[1] << std::endl;
  outFile << this->player->get_money() << std::endl;
  outFile << this->player->get_resourcesArraySize() << std::endl;
  for (int i = 0; i < this->player->get_resourcesArraySize(); i++) {
    outFile << this->player->get_resources()[i] << std::endl;
  }
  outFile << this->player->get_speed() << std::endl;
  outFile << this->player->get_scanRadius() << std::endl;
  for (int i = 0; i < this->numObjects; i++) {
    outFile << this->spaceObjects[i]->get_type() << std::endl;
    outFile << this->spaceObjects[i]->get_location()[0] << std::endl;
    outFile << this->spaceObjects[i]->get_location()[1] << std::endl;
    outFile << this->spaceObjects[i]->get_name() << std::endl;
    outFile << this->spaceObjects[i]->get_size() << std::endl;
    if (this->spaceObjects[i]->get_type() == "Planet") {
      outFile << this->spaceObjects[i]->get_population() << std::endl;
      for (int j = 0; j < numItems; j++) {
        outFile << this->spaceObjects[i]->get_inventory()[j] << std::endl;
      }
      outFile << this->spaceObjects[i]->get_economyStatus() << std::endl;
    } else {
      outFile << this->spaceObjects[i]->get_health() << std::endl;
      outFile << this->spaceObjects[i]->get_damage() << std::endl;
      for (int j = 0; j < numItems; j++) {
        outFile << this->spaceObjects[i]->get_inventory()[j] << std::endl;
      }
    }
  }
  outFile.close();
}
void Map::randomise() {
  delete[] this->spaceObjects;
  this->spaceObjects = nullptr;
  this->numObjects = 0;
  for (int i = 0; i < 20; i++) {
    // set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2); // for object type
    int randomValue = distrib(gen);    
    std::uniform_int_distribution<> distribCoord(-this->mapSize, this->mapSize); // For object coordinates
    // choose location
    // Use a set to store coordinates and avoid duplicates
    std::set<tuple<int, int>> usedCoordinates;
    int location[2];
    do {
      location[0] = distribCoord(gen);
      location[1] = distribCoord(gen);
    } while(usedCoordinates.find(make_tuple(location[0], location[1])) != usedCoordinates.end());
    usedCoordinates.insert(make_tuple(location[0], location[1]));
    // create object
    SpaceObject* nextObject;
    switch (randomValue) {
      case 0:
        nextObject = new Planet;
        break;
      case 1:
        nextObject = new CargoShip;
        break;
      case 2:
        nextObject = new CombatShip;
        break;
    }
    // call randomise function of object
    nextObject->randomise();
    // set location of object
    nextObject->set_location(location);
    // add object to map
    this->addObject(nextObject);
  }
}
Map::~Map() {
  delete[] this->spaceObjects;
  delete this->player;
}
