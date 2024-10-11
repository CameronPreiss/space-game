#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

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
  int get_scanRadius();
  void addCombat(Ship* ship);
  void move(int coords[2]);
  ~Player();
private:
  int location[2];
  int money;
  int fuel;
  float* resources;
  int resourcesArraySize;
  int speed;
  int scanRadius;
  Ship** combatLog;
  int numCombats;
};

#endif // !PLAYER_H