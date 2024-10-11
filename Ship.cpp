#include "Ship.h"
Ship::Ship() : SpaceObject(){
    this->HealthPoints = 0;
    this->Damage = 0;
    for (int i = 0; i < inventoryCount; i++){
        this->inventory[i] = 0;
    }
}

Ship::Ship(int HealthPoints, int Damage, int* inventory, int inventoryCount, std::string name, int* location, int size) : SpaceObject(location, name, size){
    this->HealthPoints = HealthPoints;
    this->Damage = Damage;
    for (int i = 0; i < inventoryCount; i++){
        this->inventory[i] = inventory[i];
    }
}

void Ship::AttackShip(Ship& Enemy, int Damage){
    Enemy.ReceiveDamage(Damage);
}

void Ship::ReceiveDamage(int damageTaken){
    set_health(get_health()-damageTaken);
}

bool Ship::isDestroyed(){
    if (HealthPoints <= 0){
        return true;
    }
return false;
}

int Ship::get_health(){
    return HealthPoints;
}
void Ship::set_health(int HealthPoints){
    this->HealthPoints = HealthPoints;
}

int Ship::get_damage(){
    return Damage;
}
void Ship::set_damage(int Damage){
    this->Damage = Damage;
}