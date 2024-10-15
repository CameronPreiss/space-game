#include "Player.h"
#include <iostream>
#include <limits>
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
Player::Player(std::string name, int location[2], int money, int* resources, int speed, int scanRadius, int) {
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

//receiving damage
void Player::ReceiveDamage(int damageTaken) {
  this->health -= damageTaken;
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
void Player::set_speed(int speed) {
  this->speed = speed;
}
void Player::set_scanRadius(int radius) {
  this->scanRadius = radius;
}

void Player::purchaseUpgrades() {
  bool purchasing = true;
  // prompting user which upgrade to purchase
  while (purchasing) {
    std::cout << "Balance: $" << this->get_money() << ", choose upgrade:\n";
    std::cout << "[0] Back\n";
    std::cout << "[1] Speed | $100\n";
    std::cout << "[2] Damage | $500\n";
    std::cout << "[3] Scan radius | $300\n";
    // validating input
    int playerResponse = -1;
    while (playerResponse == -1) {
      std::cin >> playerResponse;
      if (playerResponse < 0 || playerResponse > 3 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        playerResponse = -1;
        std::cout << "Invalid input, please try again.\n";
      }
    }
    // attempting to remove money then updating player 
    switch (playerResponse) {
      case 0:
        purchasing = false;
        break;
      case 1:
        if (this->removeMoney(100)) {
          this->set_speed(this->get_speed() + 5);
          std::cout << "Transaction successful! Current speed: " << this->get_speed() << std::endl;
        } else { 
          std::cout << "Insufficient funds!\n";
        }
        break;
      case 2:
        if (this->removeMoney(500)) {
          this->set_damage(this->get_damage() + 3);
          std::cout << "Transaction successful! Current damage: " << this->get_damage() << std::endl;
        } else {
          std::cout << "Insufficient funds!\n";
        }
        break;
      case 3:
        if (this->removeMoney(300)) {
          this->set_scanRadius(this->get_scanRadius() + 2);
          std::cout << "Transaction successful! Current scan radius: " << this->get_scanRadius() << std::endl;
        } else {
          std::cout << "Insufficient funds!\n";
        }
        break;
    }
  }
}

void Player::repairShip() {
  // cancelling repair if ship full health
  if (this->get_health() == 100) {
    std::cout << "Ship already full health!\n";
    return;
  }
  std::cout << "Current health: " << this->get_health() << std::endl;
  // calculating cost of repair
  int cost = (100 -this->get_health()) * 10;
  // getting user input for level of repair
  std::cout << "[0] Back\n";
  std::cout << "[1] Partial repair | $" << (int) (cost / 2) << std::endl;
  std::cout << "[2] Full repair | $" << cost << std::endl;
  // validating input
  int playerResponse = -1;
  while (playerResponse == -1) {
    std::cin >> playerResponse;
    if (playerResponse < 0 || playerResponse > 2 || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      playerResponse = -1;
      std::cout << "Invalid input, please try again.\n";
    }
  }
  if (playerResponse == 1) {
    // attempting to remove cost from player money
    if (this->removeMoney((int) (cost / 2))) {
      // setting health to health plus half of difference between current health and full health (100)
      this->set_health(this->get_health() + (0.5 * (100 - this->get_health())));
      std::cout << "Ship partially repaired, current health: " << this->get_health() << std::endl;
    }
  } else if (playerResponse == 2) {
    // attempting to remove cost from player money
    if (this->removeMoney(cost)) {
      // setting health to 100
      this->set_health(100);
      std::cout << "Ship fully repaired, current health: " << this->get_health() << std::endl;
    }
  }
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
