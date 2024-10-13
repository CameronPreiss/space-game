#include "Interface.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

//constructor
Interface::Interface() {
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
  for (int i = 0; i < numSaves; i++) {
    this->saves.push_back(new Map);
    this->saves[i]->loadFromFile(i);
  }
  this->map = nullptr;
}

//the beginning of game interface
void Interface::startGame() {
  //letting the user choose whether they want to load a game, or create a new game
  cout << "Welcome to Space Explorers!\n";
  cout << "[0] Load game\n";
  cout << "[1] New game\n";
  int playerResponse;
  cin >> playerResponse;
  switch (playerResponse) {
    //if the user enters 0
    case 0:
      cout << "Saved games:\n";

      //if there are no available saves, a new save will be created
      if (saves.size() == 0) {
        cout << "No available saves, creating new save\n";
      } else {

        //all the available saves are listed as per the player's name and money
        for (int i = 0; i < saves.size(); i++) {
          cout << "[" << i << "] Name: " << this->saves[i]->get_player()->get_name() << ", Money: " << this->saves[i]->get_player()->get_money() << endl;
        }
        //the user's response is taken, and a map is developed
        cin >> playerResponse;
        this->map = this->saves[playerResponse];
        break;
      }

    //if the user enters 1
    case 1:
      //a new game is created, where the user is prompted to enter a name
      cout << "Creating new game\n";
      std::string name;
      cout << "Enter a name: ";
      cin >> name;
      //a map will be created, along with combatShips and cargoShips and Planets randomly created around the map
      this->map = new Map(name);
      this->map->randomise();
      break;
  }
  this->gameLoop();
}

//the interface that will be displayed throughout the game
void Interface::gameLoop() {
  bool active = true;
  while (active) {
    cout << "Player name: " << this->map->get_player()->get_name() << ", Current location: (" << this->map->get_player()->get_location()[0] << "," << this->map->get_player()->get_location()[1] << ")\n";
    cout << "[0] Move ship\n";
    cout << "[1] Scan for nearby objects\n";
    cout << "[2] View inventory\n";
    cout << "[4] Exit game\n";
    int playerResponse;
    cin >> playerResponse;
    //if the player enters '4' the game will be exited, and the map will be saved
    switch (playerResponse) { 
      case 4:
        active = false;
        break;
      default:
        cout << "Invalid input\n";
    }
  }
  this->map->saveToFile();
}
