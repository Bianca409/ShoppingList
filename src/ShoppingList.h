#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <vector>
#include "Item.h"

using namespace std;

//Clasa ShoppingList gestioneaza lista de cumparaturi
//Permite adaugarea, stergerea, listarea, sortarea si salvarea articolelor
class ShoppingList
{
private:
    //Vector care stocheaza toate articolele din lista de cumparaturi
    vector<Item> items;

public:

    //Adauga un articol in lista
    void addItem(const Item &item);

    //Sterge un articol dupa nume
    //Returneaza true daca articolul a fost gasit si sters
    bool removeItemByName(const string &name);

    //Afiseaza toate articolele
    void listItems() const;

    //Incarca articolele din fisier JSON
    void loadFromFile(const string &filename);

    //Salveaza articolele in fisier JSON
    void saveToFile(const string &filename) const;

    //Afiseaza articolele sortate dupa nume
    void listItemsSortedByName() const;

    //Afiseaza articolele sortate dupa pret
    void listItemsSortedByPrice() const;

    //Afiseaza articolele sortate dupa categorie
    void listItemsSortedByCategory() const;

    //Afiseaza articolele dintr-o anumita categorie
    void listItemsByCategory(const string &category) const;

    //Calculeaza si returneaza costul total al listei de cumparaturi
    double getTotalCost() const;

    //Afiseaza subtotalul costurilor pentru fiecaare categorie
    void printSubtotalByCategory() const;

    //Exporta lista de cumparaturi in format CSV
    void exportToCSV(const string &filename) const;
};

#endif