#include "Player.h"
#include "ItemSet.h"

//default constructor
Player::Player() {
  ItemSet items;
  this->name = "";
  this->health = 100;
  this->money = 0;
  this->location[0] = 0;
  this->location[1] = 0;
  this->speed = 5;
  this->scanRadius = 5;
  this->resources = new int[items.get_numItems()];
  for (int i = 0; i < items.get_numItems(); i++) {
    this->resources[i] = 0;
  }
  this->damage = 20;
}

//constructor
Player::Player(std::string name, int location[2], int money, int* resources, int speed, int scanRadius, int damage) {
  this->location[0] = location[0];
  this->location[1] = location[1];
  this->money = money;
  this->resources = resources;
  this->speed = speed;
  this->scanRadius = scanRadius;
  this->name = name;
  this->damage = 20;
}
Player::Player(std::string name) {
  ItemSet items;
  this->name = name;
  this->damage = 20;
  this->health = 100;
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
std::string Player::get_name() {
  return this->name;
}
int Player::get_health(){
  return health;
}
void Player::set_health(int health){
  this->health = health;
}
int Player::get_damage() {
  return this->damage;
}
void Player::set_damage(int damage) {
  this->damage = damage;
}

//the player is moving coordinates from one position to another position, taking an array of size 2, and lets the values in that array equal the new coordinates of the ship
void Player::move(int coords[2]) {
  this->location[0] = coords[0];
  this->location[1] = coords[1];
}

//adding a resource to the player's inventory
bool Player::addResource(int index) {
  ItemSet items;
  if (index >= 0 && index < items.get_numItems()) { //if the index is greater than 0, and less than the size of the array
    this->resources[index]++; //increasing the number of that resource
    return true;
  } else {
    return false;
  }
}

//removing a resource from the player's inventory
bool Player::removeResource(int index, int amount) {
  ItemSet items;
  if (index >= 0 && index < items.get_numItems() && amount <= this->resources[index]) { //if the index is greater than 0, and less than the size of the array, and less than the number of units the player has
    this->resources[index]-= amount; //decreasing the number of that resource by an amount******
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

//destructor
Player::~Player() {
  delete[] this->resources;
}
