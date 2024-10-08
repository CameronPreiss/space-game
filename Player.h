#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player {
public:
  Player();
  void addMoney(int money);
  bool removeMoney(int money);
  int get_money();
  Ship* get_combatLog();
  int get_numCombats();
  void addCombat(Ship* ship);
  ~Player();
private:
  int money;
  Ship** combatLog;
  int numCombats;
}

#endif // !PLAYER_H
