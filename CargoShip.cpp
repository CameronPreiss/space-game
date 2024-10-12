#include "CargoShip.h"
#include <string>
#include <random>

void CargoShip::shield(int Damage){
  ReceiveDamage(Damage);
  set_health(HealthPoints + Damage);
}

CargoShip::CargoShip() : Ship() {
  this->set_type("CargoShip");
}
CargoShip::CargoShip(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, inventoryCount, name, location, size){
  this->set_type("CargoShip");
}

void CargoShip::AttackShip(Ship& Enemy, int Damage){
  Enemy.ReceiveDamage(Damage);
}

void CargoShip::ReceiveDamage(int damageTaken){
  set_health(get_health()-damageTaken);
}

bool CargoShip::isDestroyed(){
  if (HealthPoints <= 0){
    return true;
  }
  return false;
}

int CargoShip::get_health(){
  return HealthPoints;
}
void CargoShip::set_health(int HealthPoints){
  this->HealthPoints = HealthPoints;
}

int CargoShip::get_damage(){
  return Damage;
}
void CargoShip::set_damage(int Damage){
  this->Damage = Damage;
}

void CargoShip::randomise() {
  this->generateName();
  // std::set up random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribItemCount(20, 40); // for number of items
  std::uniform_int_distribution<> distribItem(0,this->get_inventoryCount()-1); // for items
  std::uniform_int_distribution<> distribHealth(30, 50); // for health
  std::uniform_int_distribution<> distribDamage(2,5); // for damage
  std::uniform_int_distribution<> distribSize(75,150); // for size
  int numItems = distribItemCount(gen); 
  // generate each item randomly
  for (int i = 0; i < numItems; i++) {
    int itemIndex = distribItem(gen);
    this->addItem(itemIndex);
  }
  // std::set health to random number
  int health = distribHealth(gen);
  this->set_health(health);
  // std::set damage to random number
  int damage = distribDamage(gen);
  this->set_damage(damage);
  // std::set size to random number
  int size = distribSize(gen);
  this->set_size(size);
}
