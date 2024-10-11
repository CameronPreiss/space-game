#include "Player.h"

Player::Player() {
  this->name = "";
  this->money = 0;
  this->location[0] = 0;
  this->location[1] = 0;
  this->speed = 5;
  this->scanRadius = 5;
}
Player::Player(std::string name, int location[2], int money, int resourcesArraySize, float* resources, int speed, int scanRadius) {
  this->location[0] = location[0];
  this->location[1] = location[1];
  this->money = money;
  this->resources = resources;
  this->resourcesArraySize = resourcesArraySize;
  this->speed = speed;
  this->scanRadius = scanRadius;
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
float* Player::get_resources() {
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
Player::~Player() {
}
