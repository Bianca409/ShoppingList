#include <iostream>
#include <string>

#include "ShoppingList.h"
#include "Item.h"

using namespace std;

int main(int argc, char* argv[])
{
    ShoppingList shoppingList;
    if(argc < 2)
    {
        cout << "Eroare: Nu a fost introdusa nici o camanda." << endl;
        return 1;
    }

    string command = argv[1];

    if(command == "add")
    {
        if(argc != 6)
        {
            cout <<"Utilizare: add <nume> <cantitate> <pret> <categorie>" << endl;
            return 1; 
        }

        string name = argv[2];
        int quantity = stoi(argv[3]);
        double price = stod(argv[4]);
        string category = argv[5];

        Item item(name, quantity, price, category);
        shoppingList.addItem(item);

        cout << "Artigol adaugat: " << name << endl;
    }
    else if(command == "remove")
    {
        if(argc != 3)
        {
            cout << "Utilizare: remove <nume>" << endl;
            return 1;
        }

        string name = argv[2];
        bool removed = shoppingList.removeItemByName(name);

        if(removed)
        {
            cout << "Articol sters: " << name << endl;
        } 
        else
        {
            cout << "Articolul nu a fost gasit." << endl;
        }
    }

    return 0;
}