#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player {
public:
  Player();
  void addMoney(int money);
  bool removeMoney(int money);
  int get_money();
  Ship** get_combatLog();
  int get_numCombats();
  int get_speed();
  int* get_location();
  void addCombat(Ship* ship);
  void move(int coords[2]);
  Ship* scan();
  ~Player();
private:
  int location[2];
  int money;
  int fuel;
  int speed;
  Ship** combatLog;
  int numCombats;
};

#endif // !PLAYER_H
