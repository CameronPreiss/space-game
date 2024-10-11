#include "CargoShip.h"
#include <string>

void CargoShip::shield(int Damage){
    ReceiveDamage(Damage);
    set_health(HealthPoints + Damage);
}

CargoShip::CargoShip(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, inventoryCount, name, location, size){}

void CargoShip::AttackShip(Ship& Enemy, int Damage){
    Enemy.ReceiveDamage(Damage);
}

void CargoShip::ReceiveDamage(int damageTaken){
    set_health(get_health()-damageTaken);
}

bool CargoShip::isDestroyed(){
    if (HealthPoints <= 0){
        return true;
    }
return false;
}

int CargoShip::get_health(){
    return HealthPoints;
}
void CargoShip::set_health(int HealthPoints){
    this->HealthPoints = HealthPoints;
}

int CargoShip::get_damage(){
    return Damage;
}
void CargoShip::set_damage(int Damage){
    this->Damage = Damage;
}


