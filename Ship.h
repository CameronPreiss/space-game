#include <iostream>
#include "SpaceObject.h"

#ifndef SHIP_H
#define SHIP_H

class Ship : public SpaceObject {
protected:
  int HealthPoints;
  int Damage;
  int* inventory;
public:
  Ship();
  Ship(int HealthPoints, int Damage, int* newInventory, std::string name, int* location, int size);

  virtual void AttackShip(Ship& Enemy, int Damage);
  virtual void ReceiveDamage(int damageTaken);
  virtual bool isDestroyed();

  virtual int get_health();
  virtual int get_damage();

  virtual void set_health(int health);
  virtual void set_damage(int damage);

  virtual int* get_inventory();
  virtual void addItem(int index);

  bool interact(Player& p1);

  virtual void randomise() {};
  void generateName();

  ~Ship();
};

#endif
