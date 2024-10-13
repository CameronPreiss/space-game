#include "SpaceObject.h"
#include <iostream>
#include <string>

//default constructor
SpaceObject::SpaceObject(){
  location[0] = 0;
  location[1] = 0;
  name = "0";
  size = 0;
  type = "0";
}

//constructor
SpaceObject::SpaceObject(int* location, std::string name, int size) {
  this->location[0] = location[0];
  this->location[1] = location[1];
  this->name = name;
  this->size = size;
}

//scanInfo function 
void SpaceObject::scanInfo() const{
  std::cout << "SpaceObject: " << name << "At location" << location[0] << "," << location[1] << "Size: " << size << std::endl; //displays the attributes of the spaceObject
}

//setters and getters
void SpaceObject::set_size(int size){
  this->size = size;
}

int SpaceObject::get_size() const{
  return size;
}

void SpaceObject::set_location(int* location){
  this->location[0] = location[0];
  this->location[1] = location[1];
}

const int* SpaceObject::get_location() const{
  return location;
}

void SpaceObject::set_name(std::string name){
  this->name = name;
}

std::string SpaceObject::get_name() const{
  return name;
}

std::string SpaceObject::get_type() const{
  return this->type;
}

void SpaceObject::set_type(std::string type) {
  this->type = type;
}
