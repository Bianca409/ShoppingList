#include "ShoppingList.h"
#include <iostream>

void ShoppingList::addItem(const Item& item)
{
    items.push_back(item);
}

bool ShoppingList::removeItemByName(const string& name)
{
    for(auto it = items.begin(); it != items.end(); ++it)
    {
        if(it->getName() == name)
        {
            items.erase(it);
            return true;
        }
    }
    return false;
}

void ShoppingList::listItems() const
{
    if(items.empty())
    {
        cout << "Lista de cumparaturi este goala." << endl;
        return;
    }

    for(const auto& item : items)
    {
        cout << item.getName()
             << " Cantitate: " << item.getQuantity()
             << " Pret unitar: " << item.getPrice()
             << " Total: " << item.getTotalPrice()
             << " Categorie: " << item.getCategory()
             << endl;
    }
}