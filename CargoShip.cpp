#include "CargoShip.h"
#include <string>
#include <random>
#include "ItemSet.h"
#include "Player.h"

void CargoShip::scanInfo() {
  std::cout << "\nHealth Points: " << get_health() << " Damage: " << get_damage() << std::endl;
}

// The cargo ship, when it uses its shield attribute, extra health from their shield
void CargoShip::SpecialMove(){
  this->set_health(this->get_health() + 10);
}

// ensuring the cargo ship is of type ship
CargoShip::CargoShip() : Ship() {
  this->set_type("CargoShip");
}
// constructor, with use of the ship constructor for efficiency
CargoShip::CargoShip(int HealthPoints, int Damage, int* inventory, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, name, location, size){
  this->set_type("CargoShip");
}

// the attack function, taking in the address of the enemy ship object and running the ReceiveDamage function with a specific damage
void CargoShip::AttackShip(Player& p1, int Damage){
  p1.set_health(p1.get_health() - Damage);
  std::cout << "You have: " << p1.get_health() << " hitpoints left" << std::endl;
}

//the receive damage function reduces the cargo ships health by (damageTaken)
void CargoShip::ReceiveDamage(int damageTaken){
  set_health(get_health()-damageTaken);
  std::cout << "Your opponent has " << get_health() << " hitpoints left" << std::endl;
}

// if the ships health is less than or equal to zero, isDestroyed is set to true
bool CargoShip::isDestroyed(){
  if (HealthPoints <= 0){
    return true;
  }
  return false;
}
 //setters and getters
int CargoShip::get_health() {
  return HealthPoints;
}
void CargoShip::set_health(int HealthPoints){
  this->HealthPoints = HealthPoints;
}

int CargoShip::get_damage() {
  return Damage;
}
void CargoShip::set_damage(int Damage){
  this->Damage = Damage;
}

//randomise function
void CargoShip::randomise() {
  ItemSet items;
  this->generateName();
  // std::set up random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribItemCount(20, 40); // for number of items
  std::uniform_int_distribution<> distribItem(0,items.get_numItems()-1); // for items
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
