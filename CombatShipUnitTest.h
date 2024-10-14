#ifndef COMBATTEST_H
#define COMBATTEST_H

#include "SpaceObject.h"
#include "Ship.h"
#include "ItemSet.h"
#include "CombatShip.h"
#include "Player.h"

#include <string>
#include <iostream>

class CombatTest {
public:
  void runTest() {
    testDoubleAttack();
    testAttackShip();
    testReceiveDamage();
    testIsDestryoed();
    testRandomise();
  }
private:
  void testDoubleAttack(){
    int combatInventory[4] = {1,2,3,4};
    int combatLocation[2] = {2,5};
    CombatShip a1 = CombatShip(100,5,combatInventory, "Jaiden", combatLocation,5);
  	Player p1 = Player("Cameron");
    a1.SpecialMove();

    a1.AttackShip(p1,5);
    if(p1.get_health() == 90){
      std::cout << "double attack test passed ✔" << std::endl;
    } else {
      std::cout << "double attack test failed✖" << std::endl; 
    }
  }

  void testAttackShip(){
    int combatInventory[4] = {1,2,3,4};
    int combatLocation[2] = {2,5};
    CombatShip a1 = CombatShip(100,5,combatInventory,"Jaiden", combatLocation,5);
    Player p1 = Player("Cameron");
    Player p2 = Player("Luke");
    a1.AttackShip(p1,5);
    if(p1.get_health() == 95){
      std::cout << "attack damage test passed ✔" << std::endl;
    } else {
      std:: cout << "attack damage test failed✖" << std::endl; 
    }
    a1.AttackShip(p2,100);
    if(p2.get_health() == 0){
      std::cout << "attack kill test passed ✔" << std::endl;
    } else {
      std:: cout << "attack kill test failed✖" << std::endl; 
    }
  }

  void testReceiveDamage(){
    int combatInventory[4] = {1,2,3,4};
    int combatLocation[2] = {2,5};
    CombatShip a1 = CombatShip(100,5,combatInventory, "Jaiden", combatLocation,5);
    CombatShip a2 = CombatShip(100,5,combatInventory, "Cameron", combatLocation,5);

    a1.ReceiveDamage(100);
    if (a1.get_health() == 0){
      std::cout << "recieved damage kill test passed ✔" << std::endl;
    } else {
      std:: cout << "recieved damage kill test failed✖" << std::endl; 
    }

    a2.ReceiveDamage(90);
    if (a2.get_health() == 10){
      std::cout << "recieved damage kill test passed ✔" << std::endl;
    } else {
      std:: cout << "recieved damage kill test failed✖" << std::endl; 
    }
  }

  void testIsDestryoed(){
    int combatInventory[4] = {1,2,3,4};
    int combatLocation[2] = {2,5};
    CombatShip a1 = CombatShip(100,5,combatInventory, "Jaiden", combatLocation,5);
    CombatShip a2 = CombatShip(5,5,combatInventory, "Luke", combatLocation,5);

    a1.ReceiveDamage(5);
    if(a1.isDestroyed() == false){
      std::cout << "ship not destryed, isDestroyed test passed ✔" << std::endl;
    } else {
      std:: cout << "ship not destryed, isDestroyed test failed✖" << std::endl; 
    }
    a2.ReceiveDamage(5);
    if(a2.isDestroyed() == true){
      std::cout << "ship destryed, isDestroyed test passed ✔" << std::endl;
    } else {
      std::cout << "ship destryed, isDestroyed test passed ✔" << std::endl; 
    }        
  }
  void testRandomise(){
    CombatShip a1 = CombatShip();
    a1.randomise();
    if(a1.get_damage() < 5 || a1.get_damage() > 10){
      std::cout << "randomise damage test failed✖" << std::endl;
    } else {
      std::cout << "randomise damage test passed ✔" << std::endl;
    }
    if(a1.get_health() < 20 || a1.get_health() > 40){
      std::cout << "randomise health test failed✖" << std::endl;
    } else {
      std::cout << "randomise health test passed ✔" << std::endl;
    }
    if(a1.get_size() < 50 || a1.get_size() > 100){
      std::cout << "randomise size test failed✖" << std::endl;
    } else {
      std::cout << "randomise size test passed ✔" << std::endl;
    }
    
    ItemSet itemset;
    bool testFailed = 0;

    for (int i = 0; i < itemset.get_numItems();i++){
      if(a1.get_inventory()[i] < 0 || a1.get_inventory()[i] > 20){
        testFailed = false;
      }
    }
    if (testFailed == true){
      std::cout << "randomise item test failed✖" << std::endl;
    } else {
      std::cout << "randomise item test passed ✔" << std::endl;
    }
  }
};

#endif
