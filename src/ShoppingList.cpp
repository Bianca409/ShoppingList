#include "ShoppingList.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <algorithm>

using json = nlohmann::json;

void ShoppingList::addItem(const Item &item)
{
    items.push_back(item);
}

bool ShoppingList::removeItemByName(const string &name)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getName() == name)
        {
            items.erase(it);
            return true;
        }
    }
    return false;
}

void ShoppingList::listItems() const
{
    if (items.empty())
    {
        cout << "Lista de cumparaturi este goala." << endl;
        return;
    }

    for (const auto &item : items)
    {
        cout << item.getName()
             << " Cantitate: " << item.getQuantity()
             << " Pret unitar: " << item.getPrice()
             << " Total: " << item.getTotalPrice()
             << " Categorie: " << item.getCategory()
             << endl;
    }
}

void ShoppingList::loadFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return;
    }

    json j;
    file >> j;

    items.clear();

    for (const auto &elem : j)
    {
        string name = elem["name"];
        int quantity = elem["quantity"];
        double price = elem["price"];
        string category = elem["category"];

        items.emplace_back(name, quantity, price, category);
    }
}

void ShoppingList::saveToFile(const string &filename) const
{
    json j = json::array();

    for (const auto &item : items)
    {
        j.push_back(
            {{"name", item.getName()},
             {"quantity", item.getQuantity()},
             {"price", item.getPrice()},
             {"category", item.getCategory()}

            });
    }

    ofstream file(filename);
    file << j.dump(4);
}

void ShoppingList::listItemsSortedByName() const
{
    if (items.empty())
    {
        cout << "Lista de cumparaturi este goala." << endl;
        return;
    }

    vector<Item> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(), [](const Item &a, const Item &b)
         { return a.getName() < b.getName(); });

    for (const auto &item : sortedItems)
    {
        cout << item.getName()
             << " Cantitate: " << item.getQuantity()
             << " Pret unitar: " << item.getPrice()
             << " Total: " << item.getTotalPrice()
             << " Categorie: " << item.getCategory()
             << endl;
    }
}

void ShoppingList::listItemsSortedByPrice() const
{
    if (items.empty())
    {
        cout << "Lista de cumparaturi este goala." << endl;
        return;
    }

    vector<Item> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(), [](const Item &a, const Item &b)
         { return a.getPrice() < b.getPrice(); });

    for (const auto &item : sortedItems)
    {
        cout << item.getName()
             << " Cantitate: " << item.getQuantity()
             << " Pret unitar: " << item.getPrice()
             << " Total: " << item.getTotalPrice()
             << " Categorie: " << item.getCategory()
             << endl;
    }
}

void ShoppingList::listItemsSortedByCategory() const
{
    if (items.empty())
    {
        cout << "Lista de cumparaturi este goala." << endl;
        return;
    }

    vector<Item> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(), [](const Item &a, const Item &b)
         { return a.getCategory() < b.getCategory(); });

    for (const auto &item : sortedItems)
    {
        cout << item.getName()
             << " Cantitate: " << item.getQuantity()
             << " Pret unitar: " << item.getPrice()
             << " Total: " << item.getTotalPrice()
             << " Categorie: " << item.getCategory()
             << endl;
    }
}

void ShoppingList::listItemsByCategory(const string &category) const
{
    bool found = false;

    for (const auto &item : items)
    {
        if (item.getCategory() == category)
        {
            found = true;
            cout << item.getName()
                 << " Cantitate: " << item.getQuantity()
                 << " Pret unitar: " << item.getPrice()
                 << " Total: " << item.getTotalPrice()
                 << endl;
        }
    }

    if (!found)
    {
        cout << "Nu exista articole in categoria: " << category << endl;
    }
}

double ShoppingList::getTotalCost() const
{
    double total = 0.0;

    for (const auto &item : items)
    {
        total += item.getTotalPrice();
    }

    return total;
}

void ShoppingList::printSubtotalByCategory() const
{
    map<string, double> subtotals;

    for (const auto &item : items)
    {
        subtotals[item.getCategory()] += item.getTotalPrice();
    }

    for (const auto &pair : subtotals)
    {
        cout << pair.first << ": " << pair.second << " RON" << endl;
    }
}

void ShoppingList::exportToCSV(const string &filename) const
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cout << "Eroare la deschiderea fisierului CSV." << endl;
        return;
    }

    file << "name,quantity,price,category,total\n";

    for (const auto &item : items)
    {
        file << item.getName() << ","
             << item.getQuantity() << ","
             << item.getPrice() << ","
             << item.getCategory() << ","
             << item.getTotalPrice() << "\n";
    }
    
    cout << "Lista exportata in " << filename << endl;
}