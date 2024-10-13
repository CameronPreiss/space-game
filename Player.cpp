#include "Player.h"

//default constructor
Player::Player() {
  this->name = "";
  this->money = 0;
  this->location[0] = 0;
  this->location[1] = 0;
  this->speed = 5;
  this->scanRadius = 5;
  this->resourcesArraySize = 10;
  this->resources = new int[10];
  for (int i = 0; i < 10; i++) {
    this->resources[i] = 0;
  }
}

//constructor
Player::Player(std::string name, int location[2], int money, int resourcesArraySize, int* resources, int speed, int scanRadius) {
  this->location[0] = location[0];
  this->location[1] = location[1];
  this->money = money;
  this->resources = resources;
  this->resourcesArraySize = resourcesArraySize;
  this->speed = speed;
  this->scanRadius = scanRadius;
  this->name = name;
}
Player::Player(std::string name) {
  this->name = name;
  this->money = 0;
  this->location[0] = 0;
  this->location[1] = 0;
  this->speed = 5;
  this->scanRadius = 5;
}

//adding money to the player
void Player::addMoney(int money) {
  this->money += money;
}

//removing money from the player
bool Player::removeMoney(int money) {
  //if the money given is less than the player's money
  if (this->money >= money) {
    this->money -= money; //that money will be subtracted from the player's total
    return 1;
  } else {
    return 0;
  }
}

//setters and getters
int Player::get_money() {
  return this->money;
}
int Player::get_speed() {
  return this->speed;
}
int* Player::get_location() {
  return this->location;
}
int Player::get_scanRadius() {
  return this->scanRadius;
}
int* Player::get_resources() {
  return this->resources;
}
int Player::get_resourcesArraySize() {
  return this->resourcesArraySize;
}
std::string Player::get_name() {
  return this->name;
}

//the player is moving coordinates from one position to another position, taking an array of size 2, and lets the values in that array equal the new coordinates of the ship
void Player::move(int coords[2]) {
  this->location[0] = coords[0];
  this->location[1] = coords[1];
}

//adding a resource to the player's inventory
bool Player::addResource(int index) {
  if (index >= 0 && index < this->resourcesArraySize) { //if the index is greater than 0, and less than the size of the array
    this->resources[index]++; //increasing the number of that resource
    return true;
  } else {
    return false;
  }
}

//removing a resource from the player's inventory
bool Player::removeResource(int index, int amount) {
  if (index >= 0 && index < this->resourcesArraySize && amount <= this->resources[index]) { //if the index is greater than 0, and less than the size of the array, and less than the number of units the player has
    this->resources[index]--; //decreasing the number of that resource by an amount******
    return true;
  } else {
    return false;
  }
}

//destructor
Player::~Player() {

  delete[] this->resources;
}
