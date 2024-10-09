#ifndef PLAYER_H
#define PLAYER_H

#include "SpaceObject.h"
#include <string>

class Player : public SpaceObject {
    public:
        float money;
        float* resources; 
        int resourcesArraySize;
        Player();
        Player(int* location, std::string name, int size, float money, int resourcesArraySize);
        ~Player();

        void scanInfo() const override;
        void interact() const override;

        void set_money(float money);
        float get_money() const;

        void set_resources(float* resources, int resourcesArraySize);
        float* get_resources() const;
        int get_resourcesArraySize() const;
};

#endif
