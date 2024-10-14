#include "MapTests.h"
#include "PlayerTests.h"
#include "CargoShipUnitTest.h"
#include "CombatShipUnitTest.h"
#include <iostream>

int main() {
  MapTests mapTests;
  std::cout << "Map tests:\n";
  mapTests.runTests();
  PlayerTests playerTests;
  std::cout << "Player tests:\n";
  playerTests.runTests();
  CargoTest cargoTests;
  std::cout << "CargoShip tests:\n";
  cargoTests.runTest();
  std::cout << "CombatShip tests:\n";
  CombatTest combatTests;
  combatTests.runTest();

  return 0;
}
