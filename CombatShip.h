#include "Ship.h"
#include <string>

#ifndef COMBATSHIP_H
#define COMBATSHIP_H

class CombatShip : public Ship{

    public:
    CombatShip(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size);
    void doubleAttack(Ship& Enemy, int Damage);
    
    void AttackShip(Ship& Enemy, int Damage);
    void ReceiveDamage(int damageTaken);
    bool isDestroyed();

    int get_health();
    int get_damage();

    void set_health(int health);
    void set_damage(int damage);

};

#endif