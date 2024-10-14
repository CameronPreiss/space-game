#ifndef MAPTESTS_H
#define MAPTESTS_H

#include "Map.h"
#include "CombatShip.h"
#include <iostream>

class MapTests {
public:
  void runTests() {
    testAddObject();
    testDestroyObject();
    testDestroyEmpty();
  }
private:
  void testAddObject() {
    Map map("test");
    CombatShip testObject;
    int numObjects = map.get_numObjects();
    map.addObject(&testObject);
    if (map.get_numObjects() == numObjects+1) {
      std::cout << "AddObject test passed ✓\n";
    } else {
      std::cout << "AddObject test failed ✖\n";
    }
  }
  void testDestroyObject() {
    Map map("test");
    CombatShip testObject;
    map.addObject(&testObject);
    map.destroyObject(0);
    if (map.get_numObjects() == 0) {
      std::cout << "DestroyObject test passed ✓\n";
    } else {
      std::cout << "DestroyObject test failed ✖\n";
    }
  }
  void testDestroyEmpty() {
    Map map("test");
    if (map.destroyObject(0) == false) {
      std::cout << "DestroyEmpty test passed ✓\n";
    } else {
      std::cout << "DestroyEmpty test failed ✖\n";
    }
  }
};

#endif 
