#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Ship.h"

class Player {
public:
  Player();
  Player(std::string name, int location[2], int money, int* resources, int speed, int scanRadius);
  Player(std::string name);
  void addMoney(int money);
  bool removeMoney(int money);
  int get_money();
  int get_speed();
  int* get_location();
  int get_scanRadius();
  int* get_resources();
  std::string get_name();
  void move(int coords[2]);
  bool addResource(int index);
  bool removeResource(int index, int amount);
  void listInventory();
  ~Player();
private:
  std::string name;
  int location[2];
  int money;
  int* resources;
  int speed;
  int scanRadius;
};

#endif // !PLAYER_H
