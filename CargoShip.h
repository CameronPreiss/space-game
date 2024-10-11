#include "Ship.h"
#include <string>

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship{

public:

  void interact() {}

  CargoShip(int HealthPoints, int Damage, int* newInventory, int inventoryCount, std::string name, int* location, int size);
  void shield(int Damage);

  void AttackShip(Ship& Enemy, int Damage);
  void ReceiveDamage(int damageTaken);
  bool isDestroyed();

  int get_health();
  int get_damage();

  void set_health(int health);
  void set_damage(int damage);

};

#endif
