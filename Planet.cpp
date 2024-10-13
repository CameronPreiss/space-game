#include "Planet.h"
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <random>
#include "ItemSet.h"

//default constructor, using the SpaceObject constructor for efficiency
Planet::Planet() : SpaceObject() {
  population = 0;
  prices = nullptr;
  economyStatus = "Unknown";
  this->set_type("Planet");
}

// constructor
Planet::Planet(int population, int* prices, std::string economyStatus, int* location, std::string name, int size) : SpaceObject(location, name, size) {
  ItemSet items;
  this->set_type("Planet");
  this->population = population;
  this->prices = new int[items.get_numItems()];
  for (int i = 0; i < items.get_numItems(); i++){
    this->prices[i] = prices[i];
  }
  this->economyStatus = economyStatus;
}

//desctructor
Planet::~Planet() {
  delete[] prices; // Free the prices array
}

//the scanInfo function, where the information of the Planet is printed to the console for the user
void Planet::scanInfo() {
  std::cout << "Planet: " << get_name() << " at location (" << get_location()[0] << "," << get_location()[1] << ")" << std::endl;
  std::cout << "Size: " << get_size() << std::endl;
  std::cout << "Population: " << this->get_population() << std::endl;
  std::cout << "Economy Status: " << get_economyStatus() << std::endl;
}

//the interact function with the input as the address of the player
bool Planet::interact(Player& p1) {
  bool done = false;
  while (!done) {
    // getting user input
    int playerResponse = -1;
    scanInfo();
    std::cout << "[0] Back\n";
    std::cout << "[1] Buy resources\n";
    std::cout << "[2] Sell resources\n";
    // validating input
    while (playerResponse == -1) {
      std::cin >> playerResponse;
      if (playerResponse < 0 || playerResponse > 2 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        playerResponse = -1;
        std::cout << "Invalid input, please try again.\n";
      }
    }
    switch (playerResponse) {
      case 0:
        return false;
      case 1:
        done = buy(p1);
        break;
      case 2:
        done = sell(p1);
        break;
    }
  }
  return true;
}

bool Planet::buy(Player& p1) {
  ItemSet items;
  // displaying player balance
  std::cout << "Current balance: $" << p1.get_money() << std::endl;
  // displaying available items
  std::cout << "[0] Cancel\n";
  for (int i = 0; i < items.get_numItems(); i++) {
    std::cout << "[" << i + 1 << "] " << items.get_itemName(i) << " | $" << prices[i] << std::endl;
  }
  // getting user input
  int playerResponse = -1;
  while (playerResponse == -1) {
    // validating input
    std::cin >> playerResponse;
    if (playerResponse < 0 || playerResponse > items.get_numItems() || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      playerResponse = -1;
      std::cout << "Invalid input, please try again.\n";
    }
  }
  if (playerResponse == 0) {
    // cancel buying
    return false;
  } else {
    int index = playerResponse - 1;
    int price = this->prices[index];
    // getting quantity
    std::cout << "Enter purchase quantity: ";
    int playerResponse = -1;
    // validating input
    while (playerResponse == -1) {
      std::cin >> playerResponse;
      if (playerResponse < 0 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        playerResponse = -1;
        std::cout << "Invalid input, please try again.\n";
      }
    }
    // attempting to purchase item
    if (p1.removeMoney(playerResponse * price)) {
      for (int i = 0; i < playerResponse; i++) {
        p1.addResource(index);
      }
      std::cout << "Transaction successful, new balance: $" << p1.get_money() << std::endl;
      return true;
    } else {
      std::cout << "Insufficient funds!\n";
      return false;
    }
  }
}

bool Planet::sell(Player& p1) { 
  ItemSet items;
  // displaying items
  std::cout << "[0] Cancel\n";
  for (int i = 0; i < items.get_numItems(); i++) {
    std::cout << "["<< i + 1 << "] " << items.get_itemName(i) << " | $" << 0.75*prices[i] << " | x" << p1.get_resources()[i] << std::endl;
  }
  // getting user input
  int playerResponse = -1;
  // validating input
  while (playerResponse == -1) {
    std::cin >> playerResponse;
    if (playerResponse < 0 || playerResponse > items.get_numItems() || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      playerResponse = -1;
      std::cout << "Invalid input, please try again.\n";
    }
  }
  if (playerResponse == 0) {
    return false;
  } 
  // setting price
  int priceIndex = playerResponse-1;
  int price = 0.75 * prices[priceIndex];
  std::cout << "Enter quantity to sell: ";
  // getting user input
  playerResponse = -1;
  // validating input
  while (playerResponse == -1) {
    std::cin >> playerResponse;
    if (playerResponse < 0 || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      playerResponse = -1;
      std::cout << "Invalid input, please try again.\n";
    }
  }
  // attempting to sell items
  if (p1.removeResource(priceIndex, playerResponse)) {
    p1.addMoney(price * playerResponse);
    std::cout << "Transaction successful, new balance: $" << p1.get_money() << std::endl;
    return true;
  } else {
    std::cout << "Insufficient resources!\n";
    return false;
  }
}

//setters and getters
void Planet::set_population(int population) {
  this->population = population;
}

void Planet::set_prices(int* prices) {
  this->prices = prices;
}

void Planet::set_economyStatus(std::string economyStatus) {
  this->economyStatus = economyStatus;
}

int Planet::get_population() {
  return population;
}

int* Planet::get_prices() {
  return prices;
}

std::string Planet::get_economyStatus() {
  return economyStatus;
}

//randomisation
void Planet::randomise() {
  ItemSet items;
  // name generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribPrefix(0,4);
  std::uniform_int_distribution<> distribSuffix(0,4);
  std::vector<std::string> prefixes = {"Beta","Epsilon","Alpha","Gamma","Delta"};
  std::vector<std::string> suffixes = {"III","IV","Minor","Major","Prime"};
  int prefix = distribPrefix(gen);
  int suffix = distribSuffix(gen);
  std::string name = prefixes[prefix] + "-" + suffixes[suffix];
  this->set_name(name);

  // set up random number generator
  std::uniform_int_distribution<> distribSize(1000,100000); // for size
  std::uniform_int_distribution<> distribPopulation(5000, 2000000); // for population
  std::uniform_real_distribution<> distribPrice(0,100); // for item prices
  std::uniform_int_distribution<> distribEconomy(0,2); // for economy status
  int numItems = items.get_numItems();
  int* prices = new int[numItems];
  // generate each item price randomly
  for (int i = 0; i < numItems; i++) {
    int itemPrice = distribPrice(gen);
    prices[i] = itemPrice;
  }
  this->set_prices(prices);
  // set size to random number
  int size = distribSize(gen);
  this->set_size(size);
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

int* Planet::get_inventory() {
  return this->prices;
}
