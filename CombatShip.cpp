#include "CombatShip.h"
#include <string>
#include <random>

// the combatShip's special attack function, where it attacks the enemy ship twice.
void CombatShip::doubleAttack(Ship& Enemy, int Damage){
  AttackShip(Enemy,Damage);
  AttackShip(Enemy,Damage);
}

//constructor using the ship constructor for efficiency
CombatShip::CombatShip(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, inventoryCount, name, location, size){
  this->set_type("CombatShip");
}

//default constructor
CombatShip::CombatShip() : Ship(){
  this->set_type("CombatShip");
}

// the attack function, taking in the address of the enemy ship object and running the ReceiveDamage function with a specific damage
void CombatShip::AttackShip(Ship& Enemy, int Damage){
  Enemy.ReceiveDamage(Damage);
}

// reducing the ship's health by (damageTaken)
void CombatShip::ReceiveDamage(int damageTaken){
  set_health(get_health()-damageTaken);
}

// if the ship's health is less than or equal to 0, isDestroyed is set to true
bool CombatShip::isDestroyed(){
  if (HealthPoints <= 0){
    return true;
  }
  return false;
}

// setters and getters
int CombatShip::get_health(){
  return HealthPoints;
}
void CombatShip::set_health(int HealthPoints){
  this->HealthPoints = HealthPoints;
}

int CombatShip::get_damage(){
  return Damage;
}
void CombatShip::set_damage(int Damage){
  this->Damage = Damage;
}

//randomisation
void CombatShip::randomise() {
  // generate name
  this->generateName();
  // set up random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribItemCount(10, 20); // for number of items
  std::uniform_int_distribution<> distribItem(0,this->get_inventoryCount()); // for items
  std::uniform_int_distribution<> distribHealth(20, 40); // for health
  std::uniform_int_distribution<> distribDamage(5,10); // for damage
  std::uniform_int_distribution<> distribSize(50,100); // for size
  int numItems = distribItemCount(gen); 
  // generate each item randomly
  for (int i = 0; i < numItems; i++) {
    int itemIndex = distribItem(gen);
    this->addItem(itemIndex);
  }
  // set health to random number
  int health = distribHealth(gen);
  this->set_health(health);
  // set damage to random number
  int damage = distribDamage(gen);
  this->set_damage(damage);
  // set size to random number
  int size = distribSize(gen);
  this->set_size(size);
}
