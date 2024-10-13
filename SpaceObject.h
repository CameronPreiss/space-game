#ifndef SpaceObject_H
#define SpaceObject_H

#include <iostream>
#include <string>

class Player;

class SpaceObject{
private:
  std::string type;
  int location[2];
  std::string name;
  int size;
public:
  SpaceObject();
  SpaceObject(int* location, std::string name, int size);
  virtual void scanInfo();
  virtual bool interact(Player& p1) { return false; };
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
