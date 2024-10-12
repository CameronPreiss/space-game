#include "Planet.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <set>
#include <tuple>

Planet::Planet() : SpaceObject() {
  population = 0;
  prices = nullptr;
  pricesArraySize = 10;
  economyStatus = "Unknown";
  this->set_type("Planet");
}

Planet::Planet(int population, float* prices, int pricesArraySize, std::string economyStatus, int* location, std::string name, int size) : SpaceObject(location, name, size) {
  this->set_type("Planet");
  this->population = population;
  this->pricesArraySize = pricesArraySize;
  this->prices = new float[pricesArraySize];
  for (int i = 0; i < pricesArraySize; i++){
    this->prices[i] = prices[i];
  }
  this->economyStatus = economyStatus;
}

Planet::~Planet() {
  delete[] prices; // Free the prices array
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
  std::cout << "\nYour money: $" << p1.get_money() << std::endl;
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

  if (p1.get_money() >= totalCost) {
    p1.get_resources()[resourceIndex] += quantity;
    p1.removeMoney(totalCost);
    std::cout << "You bought " << quantity << " units of resource " << resourceIndex + 1 << "." << std::endl;
    std::cout << "Money remaining: $" << p1.get_money() << std::endl;
  } else {
    std::cout << "Cancelled selling, not enough money to complete the purchase." << std::endl;
  }
}

void Planet::sell(Player& p1) {
  std::cout << "\nYour resources:" << std::endl;
  for (int i = 0; i < this->pricesArraySize; i++){
    std::cout << i + 1 << ". Resource " << i + 1 << " Count: " << p1.get_resources()[i] << std::endl;
  }
  std::cout << "\nAvailable resources to sell:" << std::endl;
  for (int i = 0; i < this->pricesArraySize; i++) {
    std::cout << i + 1 << ". Resource " << i + 1 << " Price: $" << 0.75*prices[i] << std::endl;
  }

  std::cout << "Enter the index of the resource you want to sell (or '0' to cancel): ";
  int testIndex;
  std::cin >> testIndex;
  if (testIndex == 0){
    std::cout << "Cancelling selling." << std::endl;
    return;
  }
  while(std::cin.fail() || testIndex <= 0 || testIndex > this->pricesArraySize){
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

  if (p1.get_resources()[resourceIndex - 1] >= quantity) {
    p1.get_resources()[resourceIndex - 1] -= quantity;
    p1.addMoney(0.75*prices[resourceIndex - 1] * quantity);
    std::cout << "You sold " << quantity << " units of resource " << resourceIndex << "." << std::endl;
    std::cout << "Money after selling: $" << p1.get_money() << std::endl;
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

void Planet::set_economyStatus(std::string economyStatus) {
  this->economyStatus = economyStatus;
}

int Planet::get_population() const {
  return population;
}

float* Planet::get_prices() const {
  return prices;
}

std::string Planet::get_economyStatus() const {
  return economyStatus;
}

void Planet::randomise() {
  // name generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribPrefix(0,4);
  std::uniform_int_distribution<> distribSuffix(0,4);
  std::vector<std::string> prefixes = {"Beta","Epsilon","Alpha","Gamma","Delta"};
  std::vector<std::string> suffixes = {"III","IV","Minor","Major","Prime"};
  int prefix = distribPrefix(gen);
  int suffix = distribSuffix(gen);
  std::string name = prefixes[prefix] + " " + suffixes[suffix];
  this->set_name(name);

  // set up random number generator
  std::uniform_int_distribution<> distribPopulation(5000, 2000000); // for population
  std::uniform_real_distribution<> distribPrice(0,100); // for item prices
  std::uniform_int_distribution<> distribEconomy(0,2); // for economy status
  int numItems = this->pricesArraySize;
  float* prices = new float[numItems];
  // generate each item price randomly
  for (int i = 0; i < numItems; i++) {
    int itemPrice = distribPrice(gen);
    prices[i] = itemPrice;
  }
  this->set_prices(prices, numItems);
  // set population to random number
  int population = distribPopulation(gen);
  this->set_population(population);
  // set economy status to random number
  int status = distribEconomy(gen);
  switch (status) {
    case 0:
      this->set_economyStatus("Great");
      break;
    case 1:
      this->set_economyStatus("Okay");
      break;
    case 2:
      this->set_economyStatus("Poor");
      break;
  }
}
