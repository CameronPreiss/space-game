#include "MapTests.h"
#include "PlayerTests.h"
#include "Map.h"
#include <iostream>

int main() {
  MapTests mapTests;
  std::cout << "Map tests:\n";
  mapTests.runTests();
  PlayerTests playerTests;
  std::cout << "Player tests:\n";
  playerTests.runTests();
  return 0;
}
