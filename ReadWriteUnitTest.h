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
        map.saveToFile();
        int index = map.get_saveIndex(); 
        Map map2 = Map();
        map2.loadFromFile(index);

        if(map2.get_player()->get_name() == name){
            std::cout << "save and load test passed ✔" << std::endl;
        } else {
            std::cout << "save and load test failed ✖" << std::endl;
        }
    }


};

#endif
