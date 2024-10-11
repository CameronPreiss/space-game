#include <iostream>
#include <string>

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

class SpaceObject{
private:

int location[2];
std::string name;
int size;

public:
SpaceObject(int* location, std::string name, int size);
SpaceObject();
};

#endif