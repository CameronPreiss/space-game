#include "Ship.h"
#include <string>

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

class CargoShip : public Ship{

public:

  //the interact function which here has no use (is a child function of Ship)
  void interact() {}

  //the menu and interface that allows the user to interact with a cargoShip
  // bool interact(Player& p1) override;

  //displaying the information of the cargoship
  void scanInfo() override;

  //default constructor and normal constructor 
  CargoShip();
  CargoShip(int HealthPoints, int Damage, int* newInventory, std::string name, int* location, int size);

  //the cargo ship's speical attack/defense function, allowing it to take no damage from the player's attack for one round
  //its input is the damage that it is dealt
  //takes no ouput
  void SpecialMove() override;

  //The attack and receive damage function, which serve to reduce the health of either the enemy ship, or the cargo ship
  //the attack ship function takes the enemy ship as an input, along with the damage that it will deal
  //the receive damage function takes an integer input of the damage that it will be dealt
  //both take no output
  void AttackShip(Player& p1, int Damage) override;
  void ReceiveDamage(int damageTaken) override;

  //the isDestroyed function, determining whether the ship is destroyed and should be removed from the map
  // this function takes a boolean output, with no inputs
  bool isDestroyed() override;

  //setters and getters
  int get_health() const;
  int get_damage() const;

  void set_health(int health) override;
  void set_damage(int damage) override;

  //randomise function, which serves to create multiple CargoShip's once the game starts
  //taking no inputs or outputs
  void randomise() override;
};

#endif
