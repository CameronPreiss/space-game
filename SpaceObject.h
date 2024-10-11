// temp SpaceObject.h for testing

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

class SpaceObject {
public:
  SpaceObject() {
    this->location[0] = 0;
    this->location[1] = 0;
  }
  SpaceObject(int coords[2]) {
    this->location[0] = coords[0];
    this->location[1] = coords[1];
  }
  int* get_location() {
    return this->location;
  }
private:
  int location[2];
};

#endif 
