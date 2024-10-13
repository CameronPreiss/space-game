#include "Player.h"
#include "ItemSet.h"

Player::Player() {
  ItemSet items;
  this->name = "";
  this->money = 0;
  this->location[0] = 0;
  this->location[1] = 0;
  this->speed = 5;
  this->scanRadius = 5;
  this->resources = new int[items.get_numItems()];
  for (int i = 0; i < items.get_numItems(); i++) {
    this->resources[i] = 0;
  }
}
Player::Player(std::string name, int location[2], int money, int* resources, int speed, int scanRadius) {
  this->location[0] = location[0];
  this->location[1] = location[1];
  this->money = money;
  this->resources = resources;
  this->speed = speed;
  this->scanRadius = scanRadius;
  this->name = name;
}
Player::Player(std::string name) {
  ItemSet items;
  this->name = name;
  this->money = 0;
  this->location[0] = 0;
  this->location[1] = 0;
  this->speed = 5;
  this->scanRadius = 10;
  this->resources = new int[items.get_numItems()];
  for (int i = 0; i < items.get_numItems(); i++) {
    this->resources[i] = 0;
  }
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
std::string Player::get_name() {
  return this->name;
}
void Player::move(int coords[2]) {
  this->location[0] = coords[0];
  this->location[1] = coords[1];
}
bool Player::addResource(int index) {
  ItemSet items;
  if (index >= 0 && index < items.get_numItems()) {
    this->resources[index]++;
    return true;
  } else {
    return false;
  }
}
bool Player::removeResource(int index, int amount) {
  ItemSet items;
  if (index >= 0 && index < items.get_numItems() && amount <= this->resources[index]) {
    this->resources[index]--;
    return true;
  } else {
    return false;
  }
}
void Player::listInventory() {
  ItemSet items;
  for (int i = 0; i < items.get_numItems(); i++) {
    std::cout << items.get_itemName(i);
    std::cout << ": " << this->resources[i] << ", ";
  }
  std::cout << "\b\b  \n";
}
Player::~Player() {
  delete[] this->resources;
}
