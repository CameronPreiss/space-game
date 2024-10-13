#include "Interface.h"
#include <iostream>
#include <limits>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void Interface::responseReset(int* playerResponse, int min, int max)  {
  if (*playerResponse < min || *playerResponse > max || cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    *playerResponse = -1;
    cout << "Invalid input, please try again.\n";
  }
}
//constructor
Interface::Interface() {
  this->map = nullptr;
  this->player = nullptr;
}

//the beginning of game interface
void Interface::startGame() {
  // start main menu loop
  bool running = true;
  while (running) {
    // get user input for load method
    cout << "Welcome to Space Explorers!\n";
    cout << "[0] Exit\n";
    cout << "[1] Load game\n";
    cout << "[2] New game\n";
    int playerResponse = -1;
    // validate input
    while (playerResponse == -1) {
      cin >> playerResponse;
      responseReset(&playerResponse, 0, 2);
    }
    loadSaves();
    switch (playerResponse) {
      case 0:
        // exit game
        running = false;
        return;
      case 1:
        // list saved games
        cout << "Saved games:\n";
        // if no saves, create new save
        if (saves.size() == 0) {
          cout << "No available saves, creating new save\n";
          // no break so will jump to new game condition
        } else {
          // get user input for which save to load
          cout << "[0] Back\n";
          for (int i = 0; i < saves.size(); i++) {
            cout << "[" << i+1 << "] Name: " << this->saves[i]->get_player()->get_name() << ", Balance: $" << this->saves[i]->get_player()->get_money() << endl;
          }
          // validate input
          playerResponse = -1;
          while (playerResponse == -1) {
            cin >> playerResponse;
            responseReset(&playerResponse, 0, saves.size());
          }
          if (playerResponse == 0) {
            // go back to main menu
            break;
          } else {
            // set map to selected save
            this->map = this->saves[playerResponse-1];
          }
          break;
        }
      case 2:
        // create new save
        cout << "Creating new game\n";
        // get users name
        cout << "Enter a name: ";
        std::string name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
        // getline to allow for whitespace
        getline(cin, name);
        // create new save with users name
        this->map = new Map(name);
        // set up random map
        this->map->randomise();
        break;
    }
    // if map loaded or created, start game
    if (this->map != nullptr) {
      this->player = this->map->get_player();
      this->gameLoop();
      running = false;
    }
  }
}

//the interface that will be displayed throughout the game
void Interface::gameLoop() {
  bool active = true;
  while (active) {
    int playerResponse = -1;
    while (playerResponse < 0 || playerResponse > 3) {
      cout << "Player name: " << this->player->get_name() << ", Current location: (" << this->player->get_location()[0] << "," << this->player->get_location()[1] << "), Balance: $" << this->player->get_money() << endl;
      cout << "[0] Exit\n";
      cout << "[1] Move ship\n";
      cout << "[2] Scan for nearby objects\n";
      cout << "[3] View inventory\n";
      cin >> playerResponse;
      responseReset(&playerResponse, 0, 3);
    }
    switch (playerResponse) {
      case 0:
        active = false;
        break;
      case 2: 
        this->map->scan();
        break;
      case 3:
        this->player->listInventory();
        break;
      default:
        cout << "Invalid input\n";
    }
  }
  this->map->saveToFile();
}
void Interface::loadSaves() {
  vector<Map*> newSaves;
  this->saves = newSaves;
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
}
