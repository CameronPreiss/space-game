#include <iostream>

#ifndef SHIP
#define SHIP

class Ship : public SpaceObject{

protected:
int HealthPoints;
int Damage;
int* Inventory;


public:
void AttackShip()
bool ReceiveDamage()

};

#endif