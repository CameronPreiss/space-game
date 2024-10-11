#include "SpaceObject.h"
#include <string>

SpaceObject::SpaceObject(int* location, std::string name, int size) {
    this->location[0] = location[0];
    this->location[1] = location[1];
    this->name = name;
    this->size = size;
}

SpaceObject::SpaceObject(){
    location[0] = 0;
    location[1] = 0;
    name = "0";
    size = 0;
}