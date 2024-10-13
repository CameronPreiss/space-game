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
private:
  //attributes
  std::vector<Map*> saves;
  Map* map;
};

#endif // !INTERFACE_H
