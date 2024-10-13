#include "Ship.h"
#include <string>

#ifndef COMBATSHIP_H
#define COMBATSHIP_H

class CombatShip : public Ship{

public:
  CombatShip();
  CombatShip(int HealthPoints, int Damage, int* inventory, std::string name, int* location, int size);
  void doubleAttack(Ship& Enemy, int Damage);

  void AttackShip(Ship& Enemy, int Damage) override;
  void ReceiveDamage(int damageTaken) override;
  bool isDestroyed() override;

  int get_health() override;
  int get_damage() override;

  void set_health(int health) override;
  void set_damage(int damage) override;

  void randomise() override;
};

#endif
