#include "Player.h"

Player::Player() {
  this->money = 0;
  this->numCombats = 0;
  this->combatLog = nullptr;
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
Player::~Player() {
  delete[] this->combatLog;
}
