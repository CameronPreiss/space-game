#ifndef MAPTESTS_H
#define MAPTESTS_H

#include "Map.h"
#include <iostream>

class MapTests {
public:
  void runTests() {
    testAddObject();
    testDestroyObject();
    testDestroyEmpty();
    testAddFull();
  }
private:
  void testAddObject() {
    Map map(10);
    SpaceObject testObject;
    map.addObject(&testObject);
    if (map.get_numObjects() == 1) {
      std::cout << "AddObject test passed :)\n";
    } else {
      std::cout << "AddObject test failed :(\n";
    }
  }
  void testDestroyObject() {
    Map map(10);
    SpaceObject testObject;
    map.addObject(&testObject);
    map.destroyObject(0);
    if (map.get_numObjects() == 0) {
      std::cout << "DestroyObject test passed :)\n";
    } else {
      std::cout << "DestroyObject test failed :(\n";
    }
  }
  void testDestroyEmpty() {
    Map map(10);
    if (map.destroyObject(0) == false) {
      std::cout << "DestroyEmpty test passed :)\n";
    } else {
      std::cout << "DestroyEmpty test failed :(\n";
    }
  }
  void testAddFull() {
    Map map(1);
    SpaceObject testObject;
    map.addObject(&testObject);
    if (map.addObject(&testObject) == false) {
      std::cout << "AddFull test passed :)\n";
    } else {
      std::cout << "AddFull test failed :(\n";
    }
  }
};

#endif 
