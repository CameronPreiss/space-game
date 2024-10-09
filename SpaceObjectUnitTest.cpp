#include <iostream>
#include "Planet.h"
#include "Player.h"

int main() {
    // Set player location and resource capacity
    int playerLocation[] = {1, 2};
    float playerMoney = 1000.0;
    int playerResourcesArraySize = 3;
    float playerResources[] = {10, 5, 0}; // Initial resources: 10 of resource 1, 5 of resource 2, none of resource 3

    // Create a player object
    Player player1(playerLocation, "Explorer1", 10, playerMoney, playerResourcesArraySize);
    player1.set_resources(playerResources, playerResourcesArraySize);

    // Display player info
    player1.scanInfo();

    // Set up planet with resources to buy and sell
    int planetLocation[] = {5, 6};
    int planetPopulation = 1000000;
    int planetPricesArraySize = 3;
    float planetPrices[] = {50.0, 30.0, 20.0}; // Prices of resources on the planet
    float planetSellableResources[] = {40.0, 25.0, 10.0}; // Resources the planet is willing to buy

    Planet planet1(planetPopulation, planetPrices, planetPricesArraySize, planetSellableResources, planetPricesArraySize, "Stable", planetLocation, "Planet Alpha", 1000);

    // Planet interaction
    planet1.scanInfo();
    planet1.interact(player1);

    return 0;
}
