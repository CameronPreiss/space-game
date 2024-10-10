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
    testMovePlayer();
    testScan();
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
  void testMovePlayer() {
    Map map(10);
    int direction[2] = {1,0};
    map.movePlayer(direction);
    if (map.get_player()->get_location()[0] == 5 && map.get_player()->get_location()[1] == 0) {
      std::cout << "MovePlayer test passed :)\n";
    } else {
      std::cout << "MovePlayer test failed :(\n";
    }
  }
  void testMoveBorder() {
    Map map(5);
    int direction[2] = {1,0};
    map.movePlayer(direction);
    if (map.movePlayer(direction) == false) {
      std::cout << "MoveBorder test passed :)\n";
    } else {
      std::cout << "MoveBorder test failed :(\n";
    }
  }
  void testScan() {
    Map map(5);
    SpaceObject* spaceObjects[4];
    int coords[4][2] = {{0,0},{0,3},{-3,-3},{10,0}};
    for (int i = 0; i < 4; i++) {
      spaceObjects[i] = new SpaceObject(coords[i]);
      map.addObject(spaceObjects[i]);
    }
    if (map.scan().size() == 3) {
      std::cout << "Scan test passed :)\n";
    } else {
      std::cout << "Scan test failed :(\n";
    }
    for (int i = 0; i < 3; i++) {
      delete spaceObjects[i];
    }
  }
};

#endif 
