#include "Ship.h"
#include <random>
#include "ItemSet.h"
#include "Player.h"
#include "Map.h"

//default constructor
Ship::Ship() : SpaceObject(){
  // setting attributes to their required values
  this->HealthPoints = 0;
  this->Damage = 0;
  int* inventory = new int[10];
  for (int i = 0; i < 10; i++){
    inventory[i] = 0;
  }
  this->inventory = inventory;
}

//constructor
Ship::Ship(int HealthPoints, int Damage, int* inventory, std::string name, int* location, int size) : SpaceObject(location, name, size){
  ItemSet items;
  this->HealthPoints = HealthPoints;
  this->Damage = Damage;
  this->inventory = new int[10];
  for (int i = 0; i < items.get_numItems(); i++){
    this->inventory[i] = inventory[i];
  }
}

// the attack function, taking in the address of the enemy ship object and running the ReceiveDamage function with a specific damage
void Ship::AttackShip(Player& p1, int Damage){
  p1.set_health(p1.get_health() - Damage);
}

//reducing the ships health by (damageTaken)
void Ship::ReceiveDamage(int damageTaken){
  set_health(get_health()-damageTaken);
}

//if the ship's health is less than 0, isDestroyed is set to true
bool Ship::isDestroyed(){
  if (HealthPoints <= 0){
    return true;
  }
  return false;
}

//setters and getters
int Ship::get_health(){
  return HealthPoints;
}
void Ship::set_health(int HealthPoints){
  this->HealthPoints = HealthPoints;
}

int Ship::get_damage(){
  return Damage;
}

void Ship::set_damage(int Damage){
  this->Damage = Damage;
}

int* Ship::get_inventory() {
  return this->inventory;
}
void Ship::addItem(int index) {
  this->inventory[index]++;
}

//randomisation
void Ship::generateName() {
  // name generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribPrefix(0,4);
  std::uniform_int_distribution<> distribFix(0,4);
  std::uniform_int_distribution<> distribSuffix(0,4);
  std::vector<std::string> prefixes = {"SS","MS","USS","HMS","CS"};
  std::vector<std::string> fixes = {"Valiant","Intrepid","Glorious","Powerful","Victorious"};
  std::vector<std::string> suffixes = {"Explorer","Titan","Falcon","Eagle","One"};
  int prefix = distribPrefix(gen);
  int fix = distribFix(gen);
  int suffix = distribSuffix(gen);
  std::string name = prefixes[prefix] + "-" + fixes[fix] + "-" + suffixes[suffix];
  this->set_name(name);
}

bool Ship::interact(Map* map) {
  Player& p1 = *map->get_player();
  // displaying ship information
  std::cout << this->get_type() << " " << this->get_name() << " at location (" << this->get_location()[0] << "," << this->get_location()[1] << ")\n";
  std::cout << "Size: " << this->get_size() << std::endl;
  std::cout << "Damage: " << this->get_damage() << std::endl;
  std::cout << "Health: " << this->get_health() << std::endl;
  std::cout << "Your health: " << p1.get_health() << std::endl;
  std::cout << "Your damage: " << p1.get_damage() << std::endl;
  // prompting user if they want to fight
  std::cout << "[0] Back\n";
  std::cout << "[1] Fight\n";
  // validating user input
  int playerResponse = -1;
  while (playerResponse == -1) {
    std::cin >> playerResponse;
    if (playerResponse < 0 || playerResponse > 1 || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      playerResponse = -1;
      std::cout << "Invalid input, please try again.\n";
    }
  }
  if (playerResponse == 0) {
    return false;
  }
  // creating copy of the health and damage
  int playerHealth = p1.get_health();
  int shipHealth = this->get_health();
  int playerDamage = p1.get_damage();
  int shipDamage = this->get_damage();
  // repeatedly make ships fight each other
  ItemSet items;
  while (true) {
    if (playerHealth < 1) {
      std::cout << "You died in combat! You have lost all your money and items\n";
      p1.removeMoney(p1.get_money()-1);
      for (int i = 0; i < items.get_numItems(); i++) {
        p1.removeResource(i, p1.get_resources()[i]);
      }
      return true;
    } else if (shipHealth < 1) {
      // reward player on ship defeat
      std::cout << "Congratulations! You have bested " << this->get_name() << " in combat\n";
      // calculate bounty based on ship type
      int bounty = (this->get_type() == "CargoShip") ? 100 : 200;
      std::cout << "Money gained: " << bounty << std::endl;
      std::cout << "You also gained any items they had\n";
      p1.addMoney(bounty);
      // adding ship inventory to player
      for (int i = 0; i < items.get_numItems(); i++) {
        p1.addResource(this->get_inventory()[i]);
      }
      // remove ship from map
      map->destroyObject(this);
      return true;
    }
    shipHealth -= playerDamage;
    playerHealth -= shipDamage;
    std::cout << "Your health: " << playerHealth << std::endl;
    std::cout << "Enemy health: " << shipHealth << std::endl;
    std::cout << "[0] Retreat\n";
    std::cout << "[1] Continue\n";
    int playerResponse = -1;
    while (playerResponse == -1) {
      std::cin >> playerResponse;
      if (playerResponse < 0 || playerResponse > 1 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        playerResponse = -1;
        std::cout << "Invalid input, please try again.\n";
      }
    }
    if (playerResponse == 0) {
      return true;
    }
  }
  return true;
}

Ship::~Ship() {
  delete[] this->inventory;
}
