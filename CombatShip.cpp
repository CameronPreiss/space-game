#include "CombatShip.h"
#include <string>
#include <random>
#include "ItemSet.h"

// the combatShip's special attack function, where it attacks the enemy ship twice.
void CombatShip::SpecialMove(){
  this->doubleAttack = true;
}

//constructor using the ship constructor for efficiency
CombatShip::CombatShip(int HealthPoints, int Damage, int* inventory, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, name, location, size){
  this->set_type("CombatShip");
  this->doubleAttack = false;
}

//default constructor
CombatShip::CombatShip() : Ship(){
  this->set_type("CombatShip");
  this->doubleAttack = false;
}

// the attack function, taking in the address of the enemy ship object and running the ReceiveDamage function with a specific damage
void CombatShip::AttackShip(Player& Enemy, int Damage){
  Enemy.ReceiveDamage(Damage);
  if (this->doubleAttack == true) {
    Enemy.ReceiveDamage(Damage);
    this->doubleAttack = false;
  }
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
  ItemSet items;
  // generate name
  this->generateName();
  // set up random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribItemCount(10, 20); // for number of items
  std::uniform_int_distribution<> distribItem(0,items.get_numItems()-1);// for items
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
