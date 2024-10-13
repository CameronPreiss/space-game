#include "CargoShip.h"
#include <string>
#include <random>
#include "ItemSet.h"
#include "Player.h"

void CargoShip::scanInfo() const {
  std::cout << "\nHealth Points: " << get_health() << " Damage: " << get_damage() << std::endl;
}

//when the player wants to interact with an enemy ship
void CargoShip::interact(Player& p1){
  std::cout << "You are now engaged in a battle with a Cargo Ship! " << std::endl;
  std::cout << "Good luck " << std::endl;
  std::string choice;
  do{   
    std::cout << "\nYour health: " << p1.get_health() << " Your opponents health: " << get_health() << std::endl;
    std::cout << "Do you want to fight? If so press f, if not press q" << std::endl;
    std::cin >> choice;

    //if the user presses f
    if (choice == "f"){
      //attack process
      AttackShip(p1, 10);
      ReceiveDamage(20);
      if (isDestroyed() == true){
        //if the enemy ship is destroyed, rewarding the user
        std::cout << "Congrats, you defeated the ship, enjoy your rewards " << std::endl;
        p1.addMoney(100);
        std::cout << "Your money: " << p1.get_money() << std::endl;
        choice = "q";
      }
    }

    //if the user does not enter a valid input, letting them know and retry
    if (choice != "f" && choice != "q"){
      std::cout << "Not a valid input" << std::endl;
    }
  } while (choice != "q");

}

// The cargo ship, when it uses its shield attribute, receives the damage from the attack lowering its health, then regains that health, blocking the attack.
void CargoShip::shield(int Damage){
  ReceiveDamage(Damage);
  set_health(HealthPoints + Damage);
}

// ensuring the cargo ship is of type ship
CargoShip::CargoShip() : Ship() {
  this->set_type("CargoShip");
}
// constructor, with use of the ship constructor for efficiency
CargoShip::CargoShip(int HealthPoints, int Damage, int* inventory, std::string name, int* location, int size)
: Ship(HealthPoints, Damage, inventory, name, location, size){
  this->set_type("CargoShip");
}

// the attack function, taking in the address of the enemy ship object and running the ReceiveDamage function with a specific damage
void CargoShip::AttackShip(Player& p1, int Damage){
  p1.set_health(p1.get_health() - Damage);
  std::cout << "You have: " << p1.get_health() << " hitpoints left" << std::endl;
}

//the receive damage function reduces the cargo ships health by (damageTaken)
void CargoShip::ReceiveDamage(int damageTaken){
  set_health(get_health()-damageTaken);
  std::cout << "Your opponent has " << get_health() << " hitpoints left" << std::endl;
}

// if the ships health is less than or equal to zero, isDestroyed is set to true
bool CargoShip::isDestroyed(){
  if (HealthPoints <= 0){
    return true;
  }
  return false;
}
 //setters and getters
int CargoShip::get_health() const{
  return HealthPoints;
}
void CargoShip::set_health(int HealthPoints){
  this->HealthPoints = HealthPoints;
}

int CargoShip::get_damage() const{
  return Damage;
}
void CargoShip::set_damage(int Damage){
  this->Damage = Damage;
}

//randomise function
void CargoShip::randomise() {
  ItemSet items;
  this->generateName();
  // std::set up random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribItemCount(20, 40); // for number of items
  std::uniform_int_distribution<> distribItem(0,items.get_numItems()-1); // for items
  std::uniform_int_distribution<> distribHealth(30, 50); // for health
  std::uniform_int_distribution<> distribDamage(2,5); // for damage
  std::uniform_int_distribution<> distribSize(75,150); // for size
  int numItems = distribItemCount(gen); 
  // generate each item randomly
  for (int i = 0; i < numItems; i++) {
    int itemIndex = distribItem(gen);
    this->addItem(itemIndex);
  }
  // std::set health to random number
  int health = distribHealth(gen);
  this->set_health(health);
  // std::set damage to random number
  int damage = distribDamage(gen);
  this->set_damage(damage);
  // std::set size to random number
  int size = distribSize(gen);
  this->set_size(size);
}
