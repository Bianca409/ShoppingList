#include <iostream>
#include <string>

#include "ShoppingList.h"
#include "Item.h"

using namespace std;

int main(int argc, char* argv[])
{
    ShoppingList shoppingList;

    shoppingList.loadFromFile("data/shopping_list.json");

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

        string name;

        int quantity;
        double price;

        try
        {
            quantity = stoi(argv[3]);
            price = stod(argv[4]);
        } catch(...){
            cout << "Eroare: cantitatea si pretul trebuie sa fie numere." << endl;
            return 1;
        }
    
        if(quantity <= 0)
        {
            cout << "Eroare: cantitatea trebuie sa fie mai mare decat 0." << endl;
            return 1;
        }

        if(price < 0)
        {
            cout << "Eroare: pretul nu poate fi negativ." << endl;
            return 1;
        }

        string category = argv[5];

        Item item(name, quantity, price, category);
        shoppingList.addItem(item);

        shoppingList.saveToFile("data/shopping_list.json");

        cout << "Artigol adaugat: " << name 
             << " (cantitate: " << quantity
             << ", pret unitar: " << price
             << ", total: " << item.getTotalPrice()
             << ", categorie: " << category << ")"
             << endl;
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
            shoppingList.saveToFile("data/shopping_list.json");
            cout << "Articol sters: " << name << endl;
        } 
        else
        {
            cout << "Articolul nu a fost gasit." << endl;
        }
    }

    else if(command == "list")
    {
        shoppingList.listItems();
    }
    else
    {
        cout << "Comanda necunoscuta." << endl;
    }

    return 0;
}