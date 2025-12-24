#include "Item.h"

Item::Item(string name, int quantity, double price, string category)
{
    this->name = name;
    this->quantity = quantity;
    this->price = price;
    this->category = category;
}

string Item::getName() const
{
    return name;
}

string Item::getCategory() const
{
    return category;
}

int Item::getQuantity() const
{
    return quantity;
}

double Item::getPrice() const
{
    return price;
}

double Item::getTotalPrice() const
{
    return quantity * price;
}