#ifndef PLAYERTESTS_H
#define PLAYERTESTS_H

#include "Player.h"
#include <iostream>

class PlayerTests {
public:
  void runTests() {
    testAddMoney();
    testRemoveMoney();
    testRemoveMoneyEmpty();
    testMove();
    testAddItem();
    testRemoveItem();
    testRemoveItemEmpty();
  }
private:
  void testAddMoney() {
    Player player;
    player.addMoney(5);
    if (player.get_money() == 5) {
      std::cout << "AddMoney test passed ✔\n";
    } else {
      std::cout << "AddMoney test failed ✖\n";
    }
  }
  void testRemoveMoney() {
    Player player;
    player.addMoney(5);
    if (player.removeMoney(2) == true) {
      std::cout << "RemoveMoney test passed ✔\n";
    } else {
      std::cout << "RemoveMoney test failed ✖\n";
    }
  }
  void testRemoveMoneyEmpty() {
    Player player;
    if (player.removeMoney(1) == false) {
      std::cout << "RemoveMoneyEmpty test passed ✔\n";
    } else {
      std::cout << "RemoveMoneyEmpty test failed ✖\n";
    }
  }
  void testMove() {
    Player player;
    int tempCoords[2] = {2,3};
    player.move(tempCoords);
    if (player.get_location()[0] == 2 && player.get_location()[1] == 3) {
      std::cout << "Move test passed ✔\n";
    } else {
      std::cout << "Move test failed :(\n";
    }
  }
  void testAddItem() {
    Player player;
    player.addResource(0);
    if (player.get_resources()[0] == 1) {
      std::cout << "AddItem test passed ✔\n";
    } else {
      std::cout << "AddItem test failed :(\n";
    }
  }
  void testRemoveItem() {
    Player player;
    player.addResource(0);
    player.removeResource(0, 1);
    if (player.get_resources()[0] == 0) {
      std::cout << "RemoveItem test passed ✔\n";
    } else {
      std::cout << "RemoveItem test failed :(\n";
    }
  }
  void testRemoveItemEmpty() {
    Player player;
    if (player.removeResource(0, 1) == false) {
      std::cout << "RemoveItemEmpty test passed ✔\n";
    } else {
      std::cout << "RemoveItemEmpty test failed :(\n";
    }
    player.removeResource(0, 1);
  }
};

#endif // !PLAYERTESTS_H
