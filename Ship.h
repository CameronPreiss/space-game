#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "SpaceObject.h"
class Player;

//abstract class, inherits from spaceObject, and will be inherited by combatShip and cargoShip
class Ship : public SpaceObject {
protected:
  //attributes of each ship
  int HealthPoints;
  int Damage;
  int* inventory;
public:
  //default constructor and normal constructor
  Ship();
  Ship(int HealthPoints, int Damage, int* newInventory, std::string name, int* location, int size);

  //the attack and receive damage functions which serve to reduce the enemy ships health or the combat ship's health during battle
  //the attack ship function takes the inputs of the enemy ship and the damage it will deal
  //the receive damage function will take the input of the damage dealt to the combat ship
  //both take no output
  virtual void AttackShip(Player& p1, int Damage);
  virtual void ReceiveDamage(int damageTaken);

  //special move (shield for cargo, double attack for combat)
  virtual void SpecialMove() {};

  //the isDestroyed function serves to determine whether the ship has no health left and whether it should be removed from the map
  //the isDestroyed function takes no inputs, but does return a boolean
  virtual bool isDestroyed();

  //setters and getters
  virtual int get_health();
  virtual int get_damage();

  virtual void set_health(int health);
  virtual void set_damage(int damage);

  virtual int* get_inventory();

  //adding an item to the ship's inventory taking an input of what the index of the item that will be added is
  virtual void addItem(int index);
  
  //the interact function (child function of spaceObject)
  bool interact(Player& p1);

  //randomise function, which takes further use in the combatShip and cargoShip classes
  virtual void randomise() {};
  void generateName();

  //destructor
  ~Ship();
};

#endif
