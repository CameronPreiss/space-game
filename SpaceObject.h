#ifndef SpaceObject_H
#define SpaceObject_H

#include <iostream>
#include <string>

class SpaceObject{
private:
  std::string type;
  int location[2];
  std::string name;
  int size;
public:
  SpaceObject();
  SpaceObject(int* location, std::string name, int size);
  virtual void scanInfo() const;
  virtual void interact() const {};
  void set_size(int size);
  int get_size() const;
  void set_location(int* location);
  const int* get_location() const;
  void set_name(std::string name);
  std::string get_name() const;
  std::string get_type() const;
  void set_type(std::string type);
  virtual int get_health() = 0;
  virtual int get_damage() = 0;
  virtual int get_inventoryCount() = 0;
  virtual int* get_inventory() { return nullptr; }
  virtual void randomise() {};
};

#endif
