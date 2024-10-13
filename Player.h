#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Ship.h"

class Player {
public:
  //default constructor, normal constructors
  Player();
  Player(std::string name, int location[2], int money, int resourcesArraySize, int* resources, int speed, int scanRadius);
  Player(std::string name);

  //add money function, takes the money that shall be added to the player, no output
  void addMoney(int money);

  //remove money function, takes the money that shall be removed from the player, boolean output which determines whether it was sucessful or not
  bool removeMoney(int money);

  //setters and getters
  int get_money();
  int get_speed();
  int* get_location();
  int get_scanRadius();
  int* get_resources();
  int get_resourcesArraySize();
  std::string get_name();

  //player move function, which changes the location of the player to different coordinates, takes an input of the integer array that the player moves to
  //no output
  void move(int coords[2]);

  //adding a resource to the player's resources, takes an integer input of the index of the resource that will be added (i.e. which resource will be added)
  //boolean output whether it was successful
  bool addResource(int index);

  //removing a resource from the player's resources, takes an integer input of the index of the resource that will be removed (i.e. which resource will be removed)
  //boolean output whether it was successful
  bool removeResource(int index, int amount);

  //destructor
  ~Player();
private:
  //attributes
  std::string name;
  int location[2];
  int money;
  int resourcesArraySize;
  int* resources;
  int speed;
  int scanRadius;
};

#endif // !PLAYER_H
