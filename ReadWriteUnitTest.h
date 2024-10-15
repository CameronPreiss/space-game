#ifndef READWRITEUNITTEST_H
#define READWRITEUNITTEST_H

#include "Map.h"
#include "Player.h"
#include "SpaceObject.h"


class ReadWriteUnitTest{

public:
    void runTest(){
        std::string name = "jaiden";
        Map map = Map(name);
        int index = map.get_saveIndex(); 
        map.saveToFile();
        Map map2 = Map();
        map2.loadFromFile(index);

        if(map2->player.get_name() == name){
            std::cout << "save and load test passed" << std::endl;
        } else {
            std::cout << "save and load test failed" << std::endl;
        }
    }


};

#endif
