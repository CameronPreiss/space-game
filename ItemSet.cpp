#include "ItemSet.h"

ItemSet::ItemSet() {
  this->numItems = 10;
  std::vector<std::string> items = {"Iron", "Coal", "Wood", "Uranium", "Rations", "Weapons", "Copper", "Gold", "Medicine", "Silver"};
  this->itemNames = items;
}
std::string ItemSet::get_itemName(int index) {
  return this->itemNames[index];
}
int ItemSet::get_numItems() {
  return this->numItems;
}

