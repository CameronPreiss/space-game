#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "Map.h"

class Interface {
public:
  Interface();
  void startGame();
  void gameLoop();
private:
  std::vector<Map*> saves;
  Map* map;
};

#endif // !INTERFACE_H
