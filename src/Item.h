#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
    private:
        string name;
        int quantity;
        double price;
        string category;

    public:
        Item(string name, int quantity, double price, string cayrgory);

        string getName() const;
        string getCategory() const;
        int getQuantity() const;
        double getPrice() const;

        double getTotalPrice() const;
};

#endif
