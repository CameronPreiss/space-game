#ifndef SpaceObject_H
#define SpaceObject_H
#include <iostream>
#include <string>

class SpaceObject{
    private:
        int location[2];
        std::string name;
        int size;
    public:
        SpaceObject();
        SpaceObject(int* location, std::string name, int size);
        virtual void scanInfo() const;
        virtual void interact() const = 0;
        void set_size(int size);
        int get_size() const;
        void set_location(int* location);
        const int* get_location() const;
        void set_name(std::string name);
        std::string get_name() const;
};

#endif