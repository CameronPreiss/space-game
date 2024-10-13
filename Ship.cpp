#include "Ship.h"
#include <random>
#include "Player.h"

//default constructor
Ship::Ship() : SpaceObject(){
  // setting attributes to their required values
  this->HealthPoints = 0;
  this->Damage = 0;
  this->inventoryCount = 10;
  //deep construction of inventory (ensuring every value is 0)
  int* inventory = new int[10];
  for (int i = 0; i < 10; i++){
    inventory[i] = 0;
  }
  this->inventory = inventory;
}

//constructor
Ship::Ship(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size) : SpaceObject(location, name, size){
  this->HealthPoints = HealthPoints;
  this->Damage = Damage;
  this->inventory = new int[10];
  for (int i = 0; i < inventoryCount; i++){
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

int Ship::get_inventoryCount() {
  return this->inventoryCount;
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

Ship::~Ship() {
  delete[] this->inventory;
}
