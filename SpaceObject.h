#ifndef SpaceObject_H
#define SpaceObject_H

#include <iostream>
#include <string>

// dummy player class to avoid circular inclusion of header files
class Map;

//purely abstract spaceObject class, planet and ships are inherited from this class
class SpaceObject{
private:
  //attributes
  std::string type;
  int location[2];
  std::string name;
  int size;
public:
  //default constructor and normal constructor
  SpaceObject();
  SpaceObject(int* location, std::string name, int size);

  //virtual scanInfo function (will be inherited by future classes to display their attributes to the console)
  virtual void scanInfo();
  
  //once the player scans for all the nearby planets and ships, they can choose to interact with one of these objects
  virtual bool interact(Map*) { return false; };

  //setters and getters
  void set_size(int size);
  int get_size();
  void set_location(int* location);
  int* get_location();
  void set_name(std::string name);
  std::string get_name();
  std::string get_type();
  void set_type(std::string type);
  virtual int get_health() = 0;
  virtual int get_damage() = 0;
  virtual int* get_inventory() { return nullptr; }
  virtual void randomise() {};
  virtual int get_population() { return 0; };
  virtual std::string get_economyStatus() { return "0"; }
};

#endif
