#ifndef Planet_H
#define Planet_H

#include <iostream>
#include <string>
#include "SpaceObject.h"
#include "Player.h"

class Planet : public SpaceObject {
private:
  //attributes
  int population;
  int* prices;
  std::string economyStatus;

public:
  //default constructor, normal constructor and destructor
  Planet();
  Planet(int population, int* prices, std::string economyStatus, int* location, std::string name, int size);
  ~Planet();

  //the scanInfo function which displays the information of the Planet to the console, for the user to get an idea of what the planet is like
  void scanInfo() override;

  //altering the interact function from spaceObject, this function, once called, allows the user to buy or sell resources from/with this planet
  //this function takes the player's address as an input
  bool interact(Map* map) override;

  //the buy function allows the user to buy resources from the planet, thus increasing the user's resources and decreasing their money
  //this function takes the player's address as an input
  bool buy(Player& p1);

  //the sell function allows the user to sell their resources to a planet, and thus gain more money
  //this takes the player's address as an input
  bool sell(Player& p1);

  //setters and getters
  void set_population(int population);
  void set_prices(int* prices);
  void set_economyStatus(std::string economyStatus);
  int get_population() override;
  int* get_prices();
  std::string get_economyStatus() override;
  int get_health() override { return 0; }
  int get_damage() override { return 0; }
  int* get_inventory() override;

  //the randomise function allows the creation of multiple planets once the map is generated
  void randomise() override;
};

#endif
