#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "Ship.h"

class Player {
public:
  //default constructor, normal constructors
  Player();
  Player(std::string name, int location[2], int money, int* resources, int speed, int scanRadius, int damage);
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
  std::string get_name();
  int get_health();
  void set_health(int health);
  int get_damage();
  void set_damage(int damage);
  void set_speed(int speed);
  void set_scanRadius(int radius);

  //purchase upgrades function, allows the user to upgrade various stats on their ship
  //no output
  void purchaseUpgrades();

  //repair ship function to return ship to full health at a cost
  void repairShip();

  //player move function, which changes the location of the player to different coordinates, takes an input of the integer array that the player moves to
  //no output
  void move(int coords[2]);

  //adding a resource to the player's resources, takes an integer input of the index of the resource that will be added (i.e. which resource will be added)
  //boolean output whether it was successful
  bool addResource(int index);

  //removing a resource from the player's resources, takes an integer input of the index of the resource that will be removed (i.e. which resource will be removed)
  //boolean output whether it was successful
  bool removeResource(int index, int amount);

  //receive damage function for combat
  void ReceiveDamage(int damageTaken);

  void listInventory();

  //destructor
  ~Player();
private:
  //attributes
  std::string name;
  int location[2];
  int money;
  int* resources;
  int speed;
  int scanRadius;
  int health;
  int damage;
};

#endif // !PLAYER_H
