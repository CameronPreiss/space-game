#include <iostream>
#include "CargoShip.h"
#include "Player.h"

int main() {
    // Initialize player
    int playerLocation[2] = {0, 0};
    int playerResources[10] = {0};  // Starting with empty resources
    Player player1("Captain", playerLocation, 100, 10, playerResources, 5, 5, 100);
    
    // Print initial player stats
    std::cout << "Welcome, " << player1.get_name() << "!" << std::endl;
    std::cout << "Your starting money: " << player1.get_money() << std::endl;
    std::cout << "Your starting health: " << player1.get_health() << std::endl;

    // Create a cargo ship and randomize its stats
    int cargoShipLocation[2] = {5, 5};
    int cargoShipInventory[10] = {0};  // Starting with an empty inventory
    CargoShip cargoShip1(50, 10, cargoShipInventory, 10, "CargoTitan", cargoShipLocation, 100);

    //cargoShip1.randomise(); *********SEG FAULT SOMEWHERE HERE*************

    cargoShip1.scanInfo();
    // Engage in battle between player and cargo ship
    cargoShip1.interact(player1);


    return 0;
}
