#include "Player.h"
#include <iostream>

Player::Player() : SpaceObject() {
    money = 0.0;
    resources = nullptr;
    resourcesArraySize = 0;
}

Player::Player(int* location, std::string name, int size, float money, int resourcesArraySize) 
    : SpaceObject(location, name, size) {
    this->money = money;
    this->resourcesArraySize = resourcesArraySize;
    resources = new float[resourcesArraySize](); 
}

Player::~Player() {
    delete[] resources;
}

void Player::scanInfo() const {
    std::cout << "Player: " << get_name() << " at location (" << get_location()[0] << "," << get_location()[1] << ")"
              << " Size: " << get_size() << std::endl;
    std::cout << "Money: " << money << std::endl;
}

void Player::interact() const {
    std::cout << "Interacting with Player: " << get_name() << std::endl;
    std::cout << "Current money: " << money << std::endl;
}

void Player::set_money(float money) {
    this->money = money;
}

float Player::get_money() const {
    return money;
}

void Player::set_resources(float* resources, int resourcesArraySize) {
    this->resources = resources;
    this->resourcesArraySize = resourcesArraySize;
}

float* Player::get_resources() const {
    return resources;
}

int Player::get_resourcesArraySize() const {
    return resourcesArraySize;
}

