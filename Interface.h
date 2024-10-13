#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "Map.h"

class Interface {
public:
  //constructor
  Interface();

  //the interface that will be displayed when the user enters the game
  void startGame();

  //the interface that will be displayed throughout the game to the user
  void gameLoop();
  void responseReset(int* playerResponse, int min, int max);
  void loadSaves();
private:
  //attributes
  std::vector<Map*> saves;
  Map* map;
  Player* player;
};

#endif // !INTERFACE_H
