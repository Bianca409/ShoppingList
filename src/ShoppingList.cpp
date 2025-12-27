#include "ShoppingList.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

void ShoppingList::loadFromFile(const string& filename)
{
    ifstream file(filename);
    if(!file.is_open())
    {
        return;
    }

    json j;
    file >> j;

    items.clear();

    for(const auto& elem : j)
    {
        string name = elem["name"];
        int quantity = elem["quantity"];
        double price = elem["price"];
        string category = elem["category"];

        items.emplace_back(name, quantity, price, category);
    }
}

void ShoppingList::saveToFile(const string& filename) const
{
    json j = json::array();

    for(const auto& item : items)
    {
        j.push_back
        (
            {
                {"name", item.getName()},
                {"quantity", item.getQuantity()},
                {"price", item.getPrice()},
                {"category", item.getCategory()}

            }
        );
    }

    ofstream file(filename);
    file << j.dump(4);
}


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