#include "Planet.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

Planet::Planet() {
    population = 0;
    prices = nullptr;
    sellableResources = nullptr;
    pricesArraySize = 0;
    resourcesArraySize = 0;
    economyStatus = "Unknown";
}

Planet::Planet(int population, float* prices, int pricesArraySize, float* sellableResources, int resourcesArraySize, std::string economyStatus, int* location, std::string name, int size) : SpaceObject(location, name, size) {
    this->population = population;
    this->pricesArraySize = pricesArraySize;
    this->resourcesArraySize = resourcesArraySize;
    this->prices = new float[pricesArraySize];
    this->sellableResources = new float[resourcesArraySize];
    for (int i = 0; i < pricesArraySize; i++){
        this->prices[i] = prices[i];
    }
    for (int i = 0; i < resourcesArraySize; i++){
        this->sellableResources[i] = sellableResources[i];
    }
    this->economyStatus = economyStatus;
}

Planet::~Planet() {
    delete[] prices; // Free the prices array
    delete[] sellableResources; // Free the sellableResources array
}

void Planet::scanInfo() const {
    std::cout << "SpaceObject: " << get_name() << " at location (" << get_location()[0] << "," << get_location()[1] << ")"
              << " Size: " << get_size() << std::endl;
    std::cout << "Population: " << population << std::endl;
    std::cout << "Economy Status: " << economyStatus << std::endl;
}

void Planet::interact() const {
    std::cout << "Interacting with Planet " << get_name() << " at location (" << get_location()[0] << "," << get_location()[1] << ").\n";
    std::cout << "Population: " << population << ". Economy Status: " << economyStatus << ".\n";
}

void Planet::interact(Player& p1) {
    std::string choice;
    do {
        std::cout << "\nYou are now interacting with the Planet: " << get_name() << std::endl;
        std::cout << "Press 'b' to buy resources, 's' to sell resources, 'q' to quit: ";
        std::cin >> choice;

        if (choice == "b") {
            buy(p1);
        } else if (choice == "s") {
            sell(p1);
        }
        if (choice != "s" && choice != "b" && choice != "q"){
            std::cout << "Not a valid input! " << std::endl;
        }
    } while (choice != "q");
    std::cout << "You are no longer interacting with Planet. " << std::endl;
}

void Planet::buy(Player& p1) {
    std::cout << "\nYour money: $" << p1.money << std::endl;
    std::cout << "\nAvailable resources to buy:" << std::endl;
    for (int i = 0; i < pricesArraySize; i++) {
        std::cout << i + 1 << ". Resource " << i + 1 << " Price: $" << prices[i] << std::endl;
    }
    std::cout << "Enter the index of the resource you want to buy (or '0' to cancel): ";
    int testIndex;
    std::cin >> testIndex;
    while(std::cin.fail()){
        std::cout << "Error, not an integer, enter a new integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> testIndex;
        std::cout << std::endl;
    }
    int resourceIndex = testIndex;

    if (resourceIndex > 0 && resourceIndex <= pricesArraySize) {
        buyingProcess(p1, resourceIndex - 1);
    } else {
        std::cout << "Cancelled buying, not a valid index of the resource." << std::endl;
    }
}

void Planet::buyingProcess(Player& p1, int resourceIndex) {
    std::cout << "How many would you like to buy? ";
    int quantityTest;
    std::cin >> quantityTest;
    while(std::cin.fail() || quantityTest <= 0){
        std::cout << "Error, not a valid integer, enter a new integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> quantityTest;
        std::cout << std::endl;
    }
    int quantity = quantityTest;

    float totalCost = prices[resourceIndex] * quantity;

    if (p1.money >= totalCost) {
        p1.resources[resourceIndex] += quantity;
        p1.money -= totalCost;
        std::cout << "You bought " << quantity << " units of resource " << resourceIndex + 1 << "." << std::endl;
        std::cout << "Money remaining: $" << p1.money << std::endl;
    } else {
        std::cout << "Cancelled selling, not enough money to complete the purchase." << std::endl;
    }
}

void Planet::sell(Player& p1) {
    std::cout << "\nYour resources:" << std::endl;
    for (int i = 0; i < resourcesArraySize; i++){
        std::cout << i + 1 << ". Resource " << i + 1 << " Count: " << p1.resources[i] << std::endl;
    }
    std::cout << "\nAvailable resources to sell:" << std::endl;
    for (int i = 0; i < resourcesArraySize; i++) {
        std::cout << i + 1 << ". Resource " << i + 1 << " Price: $" << sellableResources[i] << std::endl;
    }

    std::cout << "Enter the index of the resource you want to sell (or '0' to cancel): ";
    int testIndex;
    std::cin >> testIndex;
    if (testIndex == 0){
        std::cout << "Cancelling selling." << std::endl;
        return;
    }
    while(std::cin.fail() || testIndex <= 0 || testIndex > resourcesArraySize){
        std::cout << "Error, not a valid integer, enter a new integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> testIndex;
        std::cout << std::endl;
    }
    int resourceIndex = testIndex;

    std::cout << "How many would you like to sell? ";
    int testQuan;
    std::cin >> testQuan;
    while(std::cin.fail() || testQuan <= 0){
        std::cout << "Error, not a valid integer, enter a new integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> testQuan;
        std::cout << std::endl;
    }
    int quantity = testQuan;

    if (p1.resources[resourceIndex - 1] >= quantity) {
        p1.resources[resourceIndex - 1] -= quantity;
        p1.money += sellableResources[resourceIndex - 1] * quantity;
        std::cout << "You sold " << quantity << " units of resource " << resourceIndex << "." << std::endl;
        std::cout << "Money after selling: $" << p1.money << std::endl;
    } else {
        std::cout << "Cancelled selling, not enough resources to sell." << std::endl;
    }
}

void Planet::set_population(int population) {
    this->population = population;
}

void Planet::set_prices(float* prices, int size) {
    this->prices = prices;
    this->pricesArraySize = size;
}

void Planet::set_sellableResources(float* sellableResources, int size) {
    this->sellableResources = sellableResources;
    this->resourcesArraySize = size;
}

void Planet::set_economyStatus(std::string economyStatus) {
    this->economyStatus = economyStatus;
}

int Planet::get_population() const {
    return population;
}

float* Planet::get_prices() const {
    return prices;
}

float* Planet::get_sellableResources() const {
    return sellableResources;
}

std::string Planet::get_economyStatus() const {
    return economyStatus;
}
