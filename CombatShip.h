#include "Ship.h"
#include <string>

#ifndef COMBATSHIP_H
#define COMBATSHIP_H

class CombatShip : public Ship{

public:

  //default constructor and normal constructor
  CombatShip();
  CombatShip(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size);

  //the combat ship's special attack/defense function, allowing it to attack the enemy ship twice
  void doubleAttack(Ship& Enemy, int Damage);

  //the attack and receive damage functions which serve to reduce the enemy ships health or the combat ship's health during battle
  void AttackShip(Ship& Enemy, int Damage) override;
  void ReceiveDamage(int damageTaken) override;

  //the isDestroyed function serves to determine whether the ship has no health left and whether it should be removed from the map
  bool isDestroyed() override;

  //setters and getters
  int get_health() override;
  int get_damage() override;

  void set_health(int health) override;
  void set_damage(int damage) override;

  //randomise function which serves to create many random combat ships when the map is generated
  void randomise() override;
};

#endif
