#ifndef COMBATTEST_H
#define COMBATTEST_H

#include "SpaceObject.h"
#include "Ship.h"
#include "CargoShip.h"

#include <string>
#include <iostream>

class CargoTest {
public:

void runTest() {
    testShield();
    testAttackShip();
    testReceiveDamage();
    testIsDestryoed();
}

private:
    void testShield(){
        int cargoInventory[4] = {1,2,3,4};
        int cargoLocation[2] = {2,5};
        CargoShip a1 = CargoShip(100,5,cargoInventory, 0, "Jaiden", cargoLocation,5);
        CargoShip a2 = CargoShip(95,5,cargoInventory, 0, "Cameron", cargoLocation,5);
        
        a1.shield(5);
        if(a1.get_health() == 100){
            std::cout << "shield activated and no damage is taken, testing success" << std::endl;
        } else {
            std::cout << "test 1 failed" << std::endl; 
        }
        a2.shield(5);
        if(a2.get_health() == 95){
            std::cout << "shield activated and no damage is taken, testing success" << std::endl;
        } else {
            std:: cout << "test 2 failed" << std::endl; 
        }
    }


    void testAttackShip(){
        int cargoInventory[4] = {1,2,3,4};
        int cargoLocation[2] = {2,5};
        CargoShip a1 = CargoShip(100,5,cargoInventory, 0, "Jaiden", cargoLocation,5);
        CargoShip a2 = CargoShip(95,5,cargoInventory, 0, "Cameron", cargoLocation,5);
        CargoShip a3 = CargoShip(5,5,cargoInventory, 0, "Luke", cargoLocation,5);

        a1.AttackShip(a2,5);
        if(a2.get_health() == 90){
            std::cout << "attack damaged opponent as expected, testing success" << std::endl;
        } else {
            std:: cout << "test 3 failed" << std::endl; 
        }
        a1.AttackShip(a3,5);
        if(a3.get_health() == 0){
            std::cout << "attack killed opponent as expected, testing success" << std::endl;
        } else {
            std:: cout << "test 4 failed" << std::endl; 
        }
    }
    
    void testReceiveDamage(){
        int cargoInventory[4] = {1,2,3,4};
        int cargoLocation[2] = {2,5};
        CargoShip a1 = CargoShip(100,5,cargoInventory, 0, "Jaiden", cargoLocation,5);
        CargoShip a2 = CargoShip(95,5,cargoInventory, 0, "Cameron", cargoLocation,5);

        a1.ReceiveDamage(100);
        if (a1.get_health() == 0){
            std::cout << "ship recieved sufficient damage to destroy, testing success" << std::endl;
        } else {
            std:: cout << "test 5 failed" << std::endl; 
        }

        a2.ReceiveDamage(90);
        if (a2.get_health() == 5){
            std::cout << "ship recieved damage, testing success" << std::endl;
        } else {
            std:: cout << "test 6 failed" << std::endl; 
        }
    }
    
    void testIsDestryoed(){
        int cargoInventory[4] = {1,2,3,4};
        int cargoLocation[2] = {2,5};
        CargoShip a1 = CargoShip(100,5,cargoInventory, 0, "Jaiden", cargoLocation,5);
        CargoShip a2 = CargoShip(95,5,cargoInventory, 0, "Cameron", cargoLocation,5);
        CargoShip a3 = CargoShip(5,5,cargoInventory, 0, "Luke", cargoLocation,5);

        a1.AttackShip(a2,5);
        if(a2.isDestroyed() == false){
            std::cout << "attack damaged opponent as expected, testing success" << std::endl;
        } else {
            std:: cout << "test 7 failed" << std::endl; 
        }
        a1.AttackShip(a3,5);
        if(a3.isDestroyed() == true){
            std::cout << "attack killed opponent as expected, testing success" << std::endl;
        } else {
          std::cout << "test 8 failed" << std::endl; 
        }        
    }
};
#endif
