#ifndef Planet_H
#define Planet_H

#include <iostream>
#include <string>
#include "SpaceObject.h"
#include "Player.h"

class Planet : public SpaceObject {
    private:
        int population;
        float* prices;
        int pricesArraySize;
        float* sellableResources;
        int resourcesArraySize;
        std::string economyStatus;
    
    public:
        Planet();
        Planet(int population, float* prices, int pricesArraySize, float* sellableResources, int resourcesArraySize, std::string economyStatus, int* location, std::string name, int size);
        ~Planet();
        void scanInfo() const override;
        void interact() const override;
        void interact(Player& p1);
        void buy(Player& p1);
        void buyingProcess(Player& p1, int resourceIndex);
        void sell(Player& p1);
        void set_population(int population);
        void set_prices(float* prices, int size);
        void set_sellableResources(float* sellableResources, int size);
        void set_economyStatus(std::string economyStatus);
        int get_population() const;
        float* get_prices() const;
        float* get_sellableResources() const;
        std::string get_economyStatus() const;
};

#endif
