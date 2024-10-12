#include "Ship.h"
#include <random>

Ship::Ship() : SpaceObject(){
  this->HealthPoints = 0;
  this->Damage = 0;
  this->inventoryCount = 10;
  int inventory[10];
  for (int i = 0; i < 10; i++){
    inventory[i] = 0;
  }
  this->inventory = inventory;
}

Ship::Ship(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size) : SpaceObject(location, name, size){
  this->HealthPoints = HealthPoints;
  this->Damage = Damage;
  for (int i = 0; i < inventoryCount; i++){
    this->inventory[i] = inventory[i];
  }
}

void Ship::AttackShip(Ship& Enemy, int Damage){
  Enemy.ReceiveDamage(Damage);
}

void Ship::ReceiveDamage(int damageTaken){
  set_health(get_health()-damageTaken);
}

bool Ship::isDestroyed(){
  if (HealthPoints <= 0){
    return true;
  }
  return false;
}

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
  std::string name = prefixes[prefix] + " " + fixes[fix] + " " + suffixes[suffix];
  this->set_name(name);
}
