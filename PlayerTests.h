#ifndef PLAYERTESTS_H
#define PLAYERTESTS_H

#include "Player.h"
#include <iostream>

class PlayerTests {
public:
  void runTests() {
    testAddMoney();
    testRemoveMoney();
    testAddCombat();
    testRemoveMoneyEmpty();
  }
private:
  void testAddMoney() {
    Player player;
    player.addMoney(5);
    if (player.get_money() == 5) {
      std::cout << "AddMoney test passed :)\n";
    } else {
      std::cout << "AddMoney test failed :(\n";
    }
  }
  void testRemoveMoney() {
    Player player;
    player.addMoney(5);
    if (player.removeMoney(2) == true) {
      std::cout << "RemoveMoney test passed :)\n";
    } else {
      std::cout << "RemoveMoney test failed :(\n";
    }
  }
  void testAddCombat() {
    Player player;
    Ship testShip;
    player.addCombat(&testShip);
    if (player.get_numCombats() == 1) {
      std::cout << "AddCombat test passed :)\n";
    } else {
      std::cout << "AddCombat test failed :(\n";
    }
  }
  void testRemoveMoneyEmpty() {
    Player player;
    if (player.removeMoney(1) == false) {
      std::cout << "RemoveMoneyEmpty test passed :)\n";
    } else {
      std::cout << "RemoveMoneyEmpty test failed :(\n";
    }
  }
};

#endif // !PLAYERTESTS_H
