#include "Map.h"
#include "CargoShip.h"
#include "CombatShip.h"
#include "ItemSet.h"
#include "Planet.h"

#include <cstddef>
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

ItemSet items;
int numItems = items.get_numItems();

//default constructor
Map::Map() {
  this->numObjects = 0;
  this->mapSize = 50;
  this->spaceObjects = nullptr;
  this->player = new Player;
  this->saveIndex = -1;
}

//normal constructor
Map::Map(std::string name) {
  this->numObjects = 0;
  this->mapSize = 50;
  this->spaceObjects = nullptr;
  this->player = new Player(name);
  this->saveIndex = -1;
}

//addObject
void Map::addObject(SpaceObject* object) {
  //creates an array of pointers for the number of spaceObjects that will be placed
  SpaceObject** tempObjects = new SpaceObject*[this->numObjects+1];
  //fills the array
  for (int i = 0; i < this->numObjects; i++) {
    tempObjects[i] = this->spaceObjects[i];
  }
  tempObjects[this->numObjects] = object; delete[] this->spaceObjects;
  this->spaceObjects = tempObjects;
  this->numObjects++;
}

//removes object from map
bool Map::destroyObject(int index) {
  //input validation, ensuring the index is valid
  if (index >= 0 && index < this->numObjects) {
    //reducing the array's size by one
    SpaceObject** tempObjects = new SpaceObject*[this->numObjects-1];
    //moving all the objects in the array to their correct positions
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

//getters
int Map::get_mapSize() {
  return this->mapSize;
}
int Map::get_numObjects() {
  return this->numObjects;
}
Player* Map::get_player() {
  return this->player;
}

//move player
void Map::movePlayer() { 
  // prompting player to choose a direction
  std::cout << "Current location: (" << this->player->get_location()[0] << "," << this->player->get_location()[1] << ")\n";
  std::vector<std::array<int,2>> locations;
  int offsets[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
  char directions[4] = {'N','E','S','W'};
  for (int i = 0; i < 4; i++) {
    std::array<int,2> newLocation;
    // getting valid locations to move to
    newLocation[0] = this->player->get_location()[0] + offsets[i][0] * this->player->get_speed();
    newLocation[1] = this->player->get_location()[1] + offsets[i][1] * this->player->get_speed();
    if (newLocation[0] > -this->mapSize && newLocation[0] < mapSize && newLocation[1] > -this->mapSize && newLocation[1] < this->mapSize) {
      locations.push_back(newLocation);
      std::cout << "[" << locations.size() << "] " << directions[i] << "(" << newLocation[0] << "," << newLocation[1] << ")\n"; 
    } 
  }
  int playerResponse = -1;
  // validating input
  while (playerResponse == -1) {
    std::cin >> playerResponse;
    if (playerResponse < 0 || playerResponse > (int) locations.size() || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      playerResponse = -1;
      std::cout << "Invalid input, please try again.\n";
    }
  }
  // attempt to move player to new location
  if (playerResponse == 0) {
    return;
  } else {
    int moveLocation[2];
    moveLocation[0] = locations[playerResponse-1][0];
    moveLocation[1] = locations[playerResponse-1][1];
    this->player->move(moveLocation);
  }
}
void Map::scan() {
  // creating a vector of nearby objects
  std::vector<SpaceObject*> nearby;
  int size = this->player->get_scanRadius();
  int displaySize = 2 * size + 1;
  bool done = false;
  for (int i = 0; i < this->numObjects; i++) {
    // checking if each object on the map is within the players scan radius
    if (abs(this->player->get_location()[0] - this->spaceObjects[i]->get_location()[0]) <= size && abs(this->player->get_location()[1] - this->spaceObjects[i]->get_location()[1]) <= size) {
      // adding it to the vector if it is
      nearby.push_back(this->spaceObjects[i]);
    }
  }
  // displaying the objects
  // creating array of ascii spaces
  char** displayAscii = new char*[displaySize];
  for (int i = 0; i < displaySize; i++) {
    displayAscii[i] = new char[displaySize];
  }
  for (int i = 0; i < displaySize; i++) {
    for (int j = 0; j < displaySize; j++) {
      displayAscii[i][j] = ' ';
    }
  }
  // setting player
  displayAscii[size][size] = '<';
  // determining each nearby objects coordinate on the display
  for (SpaceObject* object : nearby) {
    int x = object->get_location()[0] - this->player->get_location()[0] + size;
    int y = object->get_location()[1] - this->player->get_location()[1] + size;
    if (object->get_type() == "Planet") {
      displayAscii[x][y] = '(';
    } else {
      displayAscii[x][y] = '*';

    }
  }
  // displaying ascii display with a border
  for (int i = 0; i < displaySize; i++) {
    std::cout << "|";
    if (i == 0) {
      for (int j = 0; j < 2*displaySize; j++) {
        std::cout << "-";
      }
      std::cout << "|\n|";
    }
    for (int j = 0; j < displaySize; j++) {
      if (displayAscii[i][j] == '<') {
        std::cout << displayAscii[i][j] << '>';
      } else if (displayAscii[i][j] == '(') {
        std::cout << displayAscii[i][j] << ')';
      } else {
        std::cout << displayAscii[i][j] << displayAscii[i][j];
      }
    }
    if (i == displaySize-1) {
      std::cout << "|\n|";
      for (int j = 0; j < 2*displaySize; j++) {
        std::cout << "-";
      }
    }
    std::cout << "|\n";
  }
  // legend
  cout << "<> (player), ** (ship), () (planet)\n";
  cout << "[0] Back\n";
  cout << "[1] Interact with object\n";
  // getting player response for if they would like to interact with an object
  int playerResponse = -1;
  while (playerResponse == -1) {
    cin >> playerResponse;
    if (playerResponse < 0 || playerResponse > 1 || cin.fail()) {
      playerResponse = -1;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input, please try again\n";
    }
  }
  if (playerResponse == 0) {
    return;
  } else {
    while (!done) {
      cout << "[0] Back\n";
      // listing available objects to interact with
      for (size_t i = 0; i < nearby.size(); i++) {
        cout << "[" << i+1 << "] " << nearby[i]->get_type() << " " << nearby[i]->get_name() << " at (" << nearby[i]->get_location()[0] << "," << nearby[i]->get_location()[1] << ")\n";
      }
      // getting player response for which object to interact with
      int playerResponse = -1;
      while (playerResponse == -1) {
        cin >> playerResponse;
        if (playerResponse < 0 || playerResponse > (int) nearby.size() || cin.fail()) {
          playerResponse = -1;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input, please try again\n";
        }
      }
      if (playerResponse == 0){
        break;
      } else {
        // interacting with selected object
        done = nearby[playerResponse-1]->interact(*this->player);
      }
    }
  }
}

//loads the map from a previous file
void Map::loadFromFile(int index) {
  ItemSet items;
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
  int speed;
  int scanRadius;
  int damage;
  inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
  getline(inFile, name);
  inFile >> playerPos[0] >> playerPos[1];
  inFile >> money;
  resources = new int[numItems];
  for (int i = 0; i < numItems; i++) {
    inFile >> resources[i];
  }
  inFile >> speed;
  inFile >> scanRadius;
  inFile >> damage;
  this->player = new Player(name, playerPos, money, resources, speed, scanRadius, damage);
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
      this->spaceObjects[i] = new CargoShip(healthPoints, damage, inventory, name, location, size);
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
      this->spaceObjects[i] = new CombatShip(healthPoints, damage, inventory, name, location, size);
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
      this->spaceObjects[i] = new Planet(population, prices, economyStatus, location, name, size);
    }
  }
  inFile.close();
  this->saveIndex = index;
}

//saves the current map to a file
void Map::saveToFile() {
  ItemSet items;
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
  for (int i = 0; i < numItems; i++) {
    outFile << this->player->get_resources()[i] << std::endl;
  }
  outFile << this->player->get_speed() << std::endl;
  outFile << this->player->get_scanRadius() << std::endl;
  outFile << this->player->get_damage() << std::endl;
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

//creates random spaceObjects
void Map::randomise() {
  delete[] this->spaceObjects;
  this->spaceObjects = nullptr;
  this->numObjects = 0;
  for (int i = 0; i < 50; i++) {
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
