#ifndef CARGOTEST_H
#define CARGOTEST_H

#include "SpaceObject.h"
#include "Ship.h"
#include "ItemSet.h"
#include "CargoShip.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <sstream>

class CargoTest {
public:
  void runTest() {
    testShield();
    testAttackShip();
    testReceiveDamage();
    testIsDestryoed();
    testRandomise();
  }
private:
  void testShield(){
    int cargoInventory[4] = {1,2,3,4};
    int cargoLocation[2] = {2,5};
    CargoShip a1 = CargoShip(100,5,cargoInventory, "Jaiden", cargoLocation,5);

    a1.SpecialMove();
    if(a1.get_health() == 110){
      std::cout << "shield test passed" << std::endl;
    } else {
      std::cout << "shield test failed" << std::endl; 
    }
  }

  void testAttackShip(){
    // setting up buffers to redirect cout stream
    std::streambuf* orig_buf = std::cout.rdbuf();
    std::ostringstream null_stream;

    int cargoInventory[4] = {1,2,3,4};
    int cargoLocation[2] = {2,5};
    CargoShip a1 = CargoShip(100,5,cargoInventory,"Jaiden", cargoLocation,5);
    Player p1 = Player("Cameron");
    Player p2 = Player("Luke");
    std::cout.rdbuf(null_stream.rdbuf());
    a1.AttackShip(p1,5);
    std::cout.rdbuf(orig_buf);
    if(p1.get_health() == 95){
      std::cout << "attack damage test passed" << std::endl;
    } else {
      std:: cout << "attack damage test failed" << std::endl; 
    }
    std::cout.rdbuf(null_stream.rdbuf());
    a1.AttackShip(p2,100);
    std::cout.rdbuf(orig_buf);
    if(p2.get_health() == 0){
      std::cout << "attack kill test passed" << std::endl;
    } else {
      std:: cout << "attack kill test failed" << std::endl; 
    }
  }

  void testReceiveDamage(){
    // setting up buffers to redirect cout stream
    std::streambuf* orig_buf = std::cout.rdbuf();
    std::ostringstream null_stream;

    int cargoInventory[4] = {1,2,3,4};
    int cargoLocation[2] = {2,5};
    CargoShip a1 = CargoShip(100,5,cargoInventory, "Jaiden", cargoLocation,5);
    CargoShip a2 = CargoShip(100,5,cargoInventory, "Cameron", cargoLocation,5);

    std::cout.rdbuf(null_stream.rdbuf());
    a1.ReceiveDamage(100);
    std::cout.rdbuf(orig_buf);

    if (a1.get_health() == 0){
      std::cout << "recieved damage kill test passed" << std::endl;
    } else {
      std:: cout << "recieved damage kill test failed" << std::endl; 
    }

    std::cout.rdbuf(null_stream.rdbuf());
    a2.ReceiveDamage(90);
    std::cout.rdbuf(orig_buf);
    if (a2.get_health() == 10){
      std::cout << "recieved damage kill test passed" << std::endl;
    } else {
      std:: cout << "recieved damage kill test failed" << std::endl; 
    }
  }

  void testIsDestryoed(){
    // setting up buffers to redirect cout stream
    std::streambuf* orig_buf = std::cout.rdbuf();
    std::ostringstream null_stream;

    int cargoInventory[4] = {1,2,3,4};
    int cargoLocation[2] = {2,5};
    CargoShip a1 = CargoShip(100,5,cargoInventory, "Jaiden", cargoLocation,5);
    CargoShip a2 = CargoShip(5,5,cargoInventory, "Luke", cargoLocation,5);

    std::cout.rdbuf(null_stream.rdbuf());
    a1.ReceiveDamage(5);
    std::cout.rdbuf(orig_buf);

    if(a1.isDestroyed() == false){
      std::cout << "ship not destryed, isDestroyed test passed" << std::endl;
    } else {
      std:: cout << "ship not destryed, isDestroyed test failed" << std::endl; 
    }

    std::cout.rdbuf(null_stream.rdbuf());
    a2.ReceiveDamage(5);
    std::cout.rdbuf(orig_buf);

    if(a2.isDestroyed() == true){
      std::cout << "ship destryed, isDestroyed test passed" << std::endl;
    } else {
      std::cout << "ship destryed, isDestroyed test passed" << std::endl; 
    }        
  }
  void testRandomise(){
    CargoShip a1 = CargoShip();
    a1.randomise();
    if(a1.get_damage() < 2 || a1.get_damage() > 5){
      std::cout << "randomise damage test failed." << std::endl;
    } else {
      std::cout << "randomise damage test passed" << std::endl;
    }
    if(a1.get_health() < 30 || a1.get_health() > 50){
      std::cout << "randomise health test failed." << std::endl;
    } else {
      std::cout << "randomise health test passed" << std::endl;
    }
    if(a1.get_size() < 75 || a1.get_size() > 150){
      std::cout << "randomise size test failed." << std::endl;
    } else {
      std::cout << "randomise size test passed" << std::endl;
    }
    
    ItemSet itemset;
    bool testFailed = 0;

    for (int i = 0; i < itemset.get_numItems();i++){
      if(a1.get_inventory()[i] < 0 || a1.get_inventory()[i] > 40){
        testFailed = false;
      }
    }
    if (testFailed == true){
      std::cout << "randomise item test failed." << std::endl;
    } else {
      std::cout << "randomise item test passed." << std::endl;
    }
  }
};
#endif
