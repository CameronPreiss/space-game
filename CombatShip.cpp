#include "CombatShip.h"
#include <string>

void CombatShip::doubleAttack(Ship& Enemy, int Damage){
    AttackShip(Enemy,Damage);
    AttackShip(Enemy,Damage);
}

CombatShip::CombatShip(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, inventoryCount, name, location, size){}

void CombatShip::AttackShip(Ship& Enemy, int Damage){
    Enemy.ReceiveDamage(Damage);
}

void CombatShip::ReceiveDamage(int damageTaken){
    set_health(get_health()-damageTaken);
}

bool CombatShip::isDestroyed(){
    if (HealthPoints <= 0){
        return true;
    }
return false;
}

int CombatShip::get_health(){
    return HealthPoints;
}
void CombatShip::set_health(int HealthPoints){
    this->HealthPoints = HealthPoints;
}

int CombatShip::get_damage(){
    return Damage;
}
void CombatShip::set_damage(int Damage){
    this->Damage = Damage;
}


