#include "Ship.h"
#include <string>

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship{

public:

  //the interact function which here has no use (is a child function of Ship)
  void interact() {}

  //default constructor and normal constructor
  CargoShip();
  CargoShip(int HealthPoints, int Damage, int* newInventory, int inventoryCount, std::string name, int* location, int size);

  //the cargo ship's speical attack/defense function, allowing it to take no damage from the player's attack for one round
  void shield(int Damage);

  //The attack and receive damage function, which serve to reduce the health of either the enemy ship, or the cargo ship
  void AttackShip(Ship& Enemy, int Damage) override;
  void ReceiveDamage(int damageTaken) override;

  //the isDestroyed function, determining whether the ship is destroyed and should be removed from the map
  bool isDestroyed() override;

  //setters and getters
  int get_health() override;
  int get_damage() override;

  void set_health(int health) override;
  void set_damage(int damage) override;

  //randomise function, which serves to create multiple CargoShip's once the game starts
  void randomise() override;
};

#endif
