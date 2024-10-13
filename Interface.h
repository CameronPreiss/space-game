#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include "Map.h"

class Interface {
public:
  Interface();
  void startGame();
  void gameLoop();
  void responseReset(int* playerResponse, int min, int max);
  void loadSaves();
private:
  std::vector<Map*> saves;
  Map* map;
  Player* player;
};

#endif // !INTERFACE_H
