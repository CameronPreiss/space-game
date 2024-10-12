#ifndef Planet_H
#define Planet_H

#include <iostream>
#include <string>
#include "SpaceObject.h"
#include "Player.h"

class Planet : public SpaceObject {
private:
  int population;
  int pricesArraySize;
  int* prices;
  std::string economyStatus;

public:
  Planet();
  Planet(int population, int* prices, int pricesArraySize, std::string economyStatus, int* location, std::string name, int size);
  ~Planet();
  void scanInfo() const override;
  void interact() const override;
  void interact(Player& p1);
  void buy(Player& p1);
  void buyingProcess(Player& p1, int resourceIndex);
  void sell(Player& p1);
  void set_population(int population);
  void set_prices(int* prices, int size);
  void set_economyStatus(std::string economyStatus);
  int get_population() const;
  int* get_prices() const;
  std::string get_economyStatus() const;
  int get_health() override { return 0; }
  int get_damage() override { return 0; }
  int get_inventoryCount() override;
  int* get_inventory() override;
  void randomise() override;
};

#endif
