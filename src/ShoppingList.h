#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <vector>
#include "Item.h"

using namespace std;

class ShoppingList{
private:
    vector<Item> items;

public:
    void addItem(const Item& item);
    bool removeItemByName(const string& name);
    void listItems() const;

};

#endif