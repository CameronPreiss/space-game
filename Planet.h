#ifndef Planet_H
#define Planet_H

#include <iostream>
#include <string>
#include "SpaceObject.h"
#include "Player.h"

class Planet : public SpaceObject {
private:
  int population;
  int* prices;
  std::string economyStatus;

public:
  Planet();
  Planet(int population, int* prices, std::string economyStatus, int* location, std::string name, int size);
  ~Planet();
  void scanInfo() override;
  bool interact(Player& p1) override;
  bool buy(Player& p1);
  bool sell(Player& p1);
  void set_population(int population);
  void set_prices(int* prices);
  void set_economyStatus(std::string economyStatus);
  int get_population() override;
  int* get_prices();
  std::string get_economyStatus() override;
  int get_health() override { return 0; }
  int get_damage() override { return 0; }
  int* get_inventory() override;
  void randomise() override;
};

#endif
