#ifndef ITEMSET_H
#define ITEMSET_H

#include <string>
#include <vector>

class ItemSet {
public:
  ItemSet();
  std::string get_itemName(int index);
  int get_numItems();
private:
  int numItems;
  std::vector<std::string> itemNames;
};

#endif // !ITEMSET_H
