#include "CombatShip.h"
#include <string>
#include <random>
#include "ItemSet.h"

void CombatShip::doubleAttack(Ship& Enemy, int Damage){
  AttackShip(Enemy,Damage);
  AttackShip(Enemy,Damage);
}

CombatShip::CombatShip(int HealthPoints, int Damage, int* inventory, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, name, location, size){
  this->set_type("CombatShip");
}
CombatShip::CombatShip() : Ship(){
  this->set_type("CombatShip");
}

void CombatShip::AttackShip(Ship& Enemy, int Damage){
  Enemy.ReceiveDamage(Damage);
}

void CombatShip::ReceiveDamage(int damageTaken){
  set_health(get_health()-damageTaken);
}

bool CombatShip::isDestroyed(){
  if (HealthPoints <= 0){
    return true;
  }
  return false;
}

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
