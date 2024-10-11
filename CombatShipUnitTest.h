#ifndef COMBATTEST_H
#define COMBATTEST_H

#include "SpaceObject.h"
#include "Ship.h"
#include "CombatShip.h"

#include <string>
#include <iostream>

class CombatTest {
public:

void runTest() {
    testDoubleAttack();
    testAttackShip();
    testReceiveDamage();
    testIsDestryoed();
}

private:
    void testDoubleAttack(){
        int combatInventory[4] = {1,2,3,4};
        int combatLocation[2] = {2,5};
        CombatShip a1 = CombatShip(100,5,combatInventory, 0, "Jaiden", combatLocation,5);
        CombatShip a2 = CombatShip(95,5,combatInventory, 0, "Cameron", combatLocation,5);
        CombatShip a3 = CombatShip(10,5,combatInventory, 0, "Luke", combatLocation,5);

        a1.doubleAttack(a2,5);
        if(a2.get_health() == 85){
            std::cout << "double attack damaged opponent as expected, testing success" << std::endl;
        } else {
            std::cout << "test 1 failed" << std::endl; 
        }
        a1.doubleAttack(a3,5);
        if(a3.get_health() == 0){
            std::cout << "double attack killed opponent as expected, testing success" << std::endl;
        } else {
            std:: cout << "test 2 failed" << std::endl; 
        }
    }
    void testAttackShip(){
        int combatInventory[4] = {1,2,3,4};
        int combatLocation[2] = {2,5};
        CombatShip a1 = CombatShip(100,5,combatInventory, 0, "Jaiden", combatLocation,5);
        CombatShip a2 = CombatShip(95,5,combatInventory, 0, "Cameron", combatLocation,5);
        CombatShip a3 = CombatShip(5,5,combatInventory, 0, "Luke", combatLocation,5);

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
        int combatInventory[4] = {1,2,3,4};
        int combatLocation[2] = {2,5};
        CombatShip a1 = CombatShip(100,5,combatInventory, 0, "Jaiden", combatLocation,5);
        CombatShip a2 = CombatShip(95,5,combatInventory, 0, "Cameron", combatLocation,5);

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
        int combatInventory[4] = {1,2,3,4};
        int combatLocation[2] = {2,5};
        CombatShip a1 = CombatShip(100,5,combatInventory, 0, "Jaiden", combatLocation,5);
        CombatShip a2 = CombatShip(95,5,combatInventory, 0, "Cameron", combatLocation,5);
        CombatShip a3 = CombatShip(5,5,combatInventory, 0, "Luke", combatLocation,5);

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
