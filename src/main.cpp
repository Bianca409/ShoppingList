#include <iostream>
#include <string>

#include "ShoppingList.h"
#include "Item.h"

using namespace std;

int main(int argc, char *argv[])
{
    ShoppingList shoppingList;

    shoppingList.loadFromFile("data/shopping_list.json");

    if (argc < 2)
    {
        cout << "Eroare: Nu a fost introdusa nicio comanda." << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "add")
    {
        if (argc != 6)
        {
            cout << "Utilizare: add <nume> <cantitate> <pret> <categorie>" << endl;
            return 1;
        }

        string name = argv[2];

        int quantity;
        double price;

        try
        {
            quantity = stoi(argv[3]);
            price = stod(argv[4]);
        }
        catch (...)
        {
            cout << "Eroare: cantitatea si pretul trebuie sa fie numere." << endl;
            return 1;
        }

        if (quantity <= 0)
        {
            cout << "Eroare: cantitatea trebuie sa fie mai mare decat 0." << endl;
            return 1;
        }

        if (price < 0)
        {
            cout << "Eroare: pretul nu poate fi negativ." << endl;
            return 1;
        }

        string category = argv[5];

        Item item(name, quantity, price, category);
        shoppingList.addItem(item);

        shoppingList.saveToFile("data/shopping_list.json");

        cout << "Articol adaugat: " << name
             << " (cantitate: " << quantity
             << ", pret unitar: " << price
             << ", total: " << item.getTotalPrice()
             << ", categorie: " << category << ")"
             << endl;
    }
    else if (command == "remove")
    {
        if (argc != 3)
        {
            cout << "Utilizare: remove <nume>" << endl;
            return 1;
        }

        string name = argv[2];
        bool removed = shoppingList.removeItemByName(name);

        if (removed)
        {
            shoppingList.saveToFile("data/shopping_list.json");
            cout << "Articol sters: " << name << endl;
        }
        else
        {
            cout << "Articolul nu a fost gasit." << endl;
        }
    }

    else if (command == "list")
    {
        if (argc == 2)
        {
            shoppingList.listItems();
        }
        else if (argc == 4 && string(argv[2]) == "--sort")
        {
            string sortType = argv[3];

            if (sortType == "name")
            {
                shoppingList.listItemsSortedByName();
            }

            else if (sortType == "price")
            {
                shoppingList.listItemsSortedByPrice();
            }

            else if (sortType == "category")
            {
                shoppingList.listItemsSortedByCategory();
            }

            else
            {
                cout << "Tip de sortare necunoscut." << endl;
            }
        }

        else
        {
            cout << "Utilizare: list [--sort name|price|category]" << endl;
        }
    }

    else if (command == "search")
    {
        if (argc != 4 || string(argv[2]) != "--category")
        {
            cout << "Utilizare: search --category <categorie>" << endl;
            return 1;
        }

        string category = argv[3];
        shoppingList.listItemsByCategory(category);
    }

    else if (command == "total")
    {
        double total = shoppingList.getTotalCost();
        cout << "Cost total: " << total << " RON" << endl;
    }

    else if (command == "subtotal")
    {
        shoppingList.printSubtotalByCategory();
    }

    else if (command == "export")
    {
        if (argc != 3)
        {
            cout << "Utilizare: export <fisier.csv>" << endl;
            return 1;
        }

        string filename = argv[2];
        shoppingList.exportToCSV(filename);
    }

    else if (command == "help")
    {
        cout << "== Ajutor - Shopping List ==\n";
        cout << "Comenzi disponibile:\n";
        cout << " add <nume> <cantitate> <pret> <categorie>\n";
        cout << " remove <nume>\n";
        cout << " list\n";
        cout << " list --sort name|price|category\n";
        cout << " search --category <categorie>\n";
        cout << " total\n";
        cout << " export <fisier.csv>\n";
        cout << " help\n";
        cout << "Exemplu: ./shopping_list add mere 5 2.5 fructe\n";
    }

    else
    {
        cout << "Comanda necunoscuta." << endl;
    }

    return 0;
}