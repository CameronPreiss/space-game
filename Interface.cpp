#include "Interface.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

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
void Interface::startGame() {
  cout << "Welcome to Space Explorers!\n";
  cout << "[0] Load game\n";
  cout << "[1] New game\n";
  int playerResponse;
  cin >> playerResponse;
  switch (playerResponse) {
    case 0:
      cout << "Saved games:\n";
      if (saves.size() == 0) {
        cout << "No available saves, creating new save\n";
      } else {
        for (int i = 0; i < saves.size(); i++) {
          cout << "[" << i << "] Name: " << this->saves[i]->get_player()->get_name() << ", Money: " << this->saves[i]->get_player()->get_money() << endl;
        }
        cin >> playerResponse;
        this->map = this->saves[playerResponse];
        break;
      }
    case 1:
      cout << "Creating new game\n";
      std::string name;
      cout << "Enter a name: ";
      cin >> name;
      this->map = new Map(name);
      this->map->randomise();
      break;
  }
  this->gameLoop();
}
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
