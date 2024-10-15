#include "MapTests.h"
#include "PlayerTests.h"
#include "CargoShipUnitTest.h"
#include "CombatShipUnitTest.h"
#include "ReadWriteUnitTest.h"
#include <iostream>

int main() {
  MapTests mapTests;
  std::cout << "- Map tests:\n";
  mapTests.runTests();
  PlayerTests playerTests;
  std::cout << "- Player tests:\n";
  playerTests.runTests();
  CargoTest cargoTests;
  std::cout << "- CargoShip tests:\n";
  cargoTests.runTest();
  std::cout << "- CombatShip tests:\n";
  CombatTest combatTests;
  combatTests.runTest();
  std::cout << "- Read/Write tests:\n";
  ReadWriteUnitTest readWrite;
  readWrite.runTest();

  return 0;
}
