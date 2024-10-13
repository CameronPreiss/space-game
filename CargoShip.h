#include "Ship.h"
#include <string>

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship{

public:

  CargoShip();
  CargoShip(int HealthPoints, int Damage, int* newInventory, std::string name, int* location, int size);
  void shield(int Damage);

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
