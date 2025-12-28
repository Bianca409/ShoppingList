#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <vector>
#include "Item.h"

using namespace std;

class ShoppingList
{
private:
    vector<Item> items;

public:
    void addItem(const Item &item);
    bool removeItemByName(const string &name);
    void listItems() const;

    void loadFromFile(const string &filename);
    void saveToFile(const string &filename) const;

    void listItemsSortedByName() const;
    void listItemsSortedByPrice() const;
    void listItemsSortedByCategory() const;

    void listItemsByCategory(const string &category) const;

    double getTotalCost() const;
    void printSubtotalByCategory() const;

    void exportToCSV(const string &filname) const;
};

#endif