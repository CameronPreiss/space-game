#include "Ship.h"
#include "Player.h"
#include <string>
#include "Player.h"

#ifndef COMBATSHIP_H
#define COMBATSHIP_H

class CombatShip : public Ship{

public:
  //displaying the information of the cargoship
  void scanInfo() override;

  //default constructor and normal constructor
  CombatShip();
  CombatShip(int HealthPoints, int Damage, int* inventory, std::string name, int* location, int size);

  //the combat ship's special attack/defense function, allowing it to attack the enemy ship twice
  //takes no inputs
  //takes no outputs
  void SpecialMove() override;

  //the attack and receive damage functions which serve to reduce the enemy ships health or the combat ship's health during battle
  //the attack ship function takes the inputs of the enemy ship and the damage it will deal
  //the receive damage function will take the input of the damage dealt to the combat ship
  //both take no output
  void AttackShip(Player& Enemy, int Damage) override;
  void ReceiveDamage(int damageTaken) override;

  //the isDestroyed function serves to determine whether the ship has no health left and whether it should be removed from the map
  //the isDestroyed function takes no inputs, but does return a boolean
  bool isDestroyed() override;

  //setters and getters
  int get_health() override;
  int get_damage() override;
  bool get_doubleAttack();

  void set_health(int health) override;
  void set_damage(int damage) override;
  void set_doubleAttack(bool doubleAttack);

  
  

  //randomise function which serves to create many random combat ships when the map is generated
  //takes no inputs or outputs
  void randomise() override;

private:
  
  //variable to track whether the special double attack move is active
  bool doubleAttack;
};

#endif
