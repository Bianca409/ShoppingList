#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

//Clasa Item reprezinta un articol din lista de cumparaturi
//Contine informatii despre: nume, cantitate, pret unitar si categorie
class Item
{
    private:
        string name;
        int quantity;
        double price;
        string category;

    public:
        //Constructor pentru initializarea unui articol
        Item(string name, int quantity, double price, string cayrgory);

        //Returneaza numele articolului
        string getName() const;

        //Returneaza categoria articolului
        string getCategory() const;

        //Returneaza cantitatea articolului
        int getQuantity() const;

        //Returneaza pretul unitar
        double getPrice() const;

        //Calculeaza si returneaza pretul total (cantitate * pret unitar)
        double getTotalPrice() const;
};

#endif
