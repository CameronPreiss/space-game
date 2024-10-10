#include "Player.h"

Player::Player() {
  this->money = 0;
  this->numCombats = 0;
  this->combatLog = nullptr;
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
Ship** Player::get_combatLog() {
  return this->combatLog;
}
int Player::get_numCombats() {
  return this->numCombats;
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
void Player::addCombat(Ship* ship) {
  Ship** tempCombatLog = new Ship*[this->numCombats+1];
  for (int i = 0; i < this->numCombats; i++) {
    tempCombatLog[i] = this->combatLog[i];
  }
  tempCombatLog[this->numCombats] = ship;
  delete[] this->combatLog;
  this->combatLog = tempCombatLog;
  this->numCombats++;
}
void Player::move(int coords[2]) {
  this->location[0] = coords[0];
  this->location[1] = coords[1];
}
Player::~Player() {
  delete[] this->combatLog;
}
