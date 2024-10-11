#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Ship.h"

class Player {
public:
  Player();
  Player(std::string name, int location[2], int money, int resourcesArraySize, float* resources, int speed, int scanRadius);
  void addMoney(int money);
  bool removeMoney(int money);
  int get_money();
  int get_speed();
  int* get_location();
  int get_scanRadius();
  float* get_resources();
  int get_resourcesArraySize();
  std::string get_name();
  void move(int coords[2]);
  ~Player();
private:
  std::string name;
  int location[2];
  int money;
  int resourcesArraySize;
  float* resources;
  int speed;
  int scanRadius;
};

#endif // !PLAYER_H
