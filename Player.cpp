#include "Player.h"

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
Player::Player(std::string name, int location[2], int money, int resourcesArraySize, int* resources, int speed, int scanRadius) {
  this->location[0] = location[0];
  this->location[1] = location[1];
  this->money = money;
  this->resources = resources;
  this->resourcesArraySize = resourcesArraySize;
  this->speed = speed;
  this->scanRadius = scanRadius;
}
Player::Player(std::string name) {
  this->name = name;
  this->money = 0;
  this->location[0] = 0;
  this->location[1] = 0;
  this->speed = 5;
  this->scanRadius = 5;
}
void Player::addMoney(int money) {
  this->money += money;
}
bool Player::removeMoney(int money) {
  if (this->money >= money) {
    this->money -= money;
    return 1;
  } else {
    return 0;
  }
}
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
void Player::move(int coords[2]) {
  this->location[0] = coords[0];
  this->location[1] = coords[1];
}
bool Player::addResource(int index) {
  if (index >= 0 && index < this->resourcesArraySize) {
    this->resources[index]++;
    return true;
  } else {
    return false;
  }
}
bool Player::removeResource(int index, int amount) {
  if (index >= 0 && index < this->resourcesArraySize && amount <= this->resources[index]) {
    this->resources[index]--;
    return true;
  } else {
    return false;
  }
}
Player::~Player() {

  delete[] this->resources;
}
