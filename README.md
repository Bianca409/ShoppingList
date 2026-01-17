# ShoppingList

Este o aplicatie de tip CLI pentru gestionarea unei liste de cumparaturi. Permite adaugarea, stergerea, listarea si salvarea articolelor, cu salvarea datelor in format JSON si export in format CSV. 

## Autor
- **Nume:** Linca Bianca-Alexandra-Iosefina
- **Grupa:** 2.1
- **Email:** bianca-alexandra-iosefina.linca@student.upt.ro
- **An academic:** 2025-2026

## Descriere
Aceasta aplicatie permite utilizatorului sa gestioneze o lista de cumparaturi direct din linia de comanda. Articolele pot fi adaugate cu nume, cantitate, pret unitar si categorie, iar functionalitatile includ sortarea, filtrarea, calculul costului total si exportul datelor.
Datele sunt pastrate folosind fisiere JSON.

## Tehnologii folosite
- **Limbaj:** C++ 17
- **Biblioteci:** 
  - `iostream` - reprezinta afisarea meniului in consola (`cout`) si citirea datelor introduse de la tastatura (`cin`)  
  - `vector` - container STL utilizat pentru a stoca lista de cumparaturi sub forma unui tablou dinamic, permitand redimensionarea automata la adaugarea/stergerea produselor  
  - `string` - folosita pentru manipularea sirurilor de caractere, necesara pentru stocarea numelor produselor si categoria acestora  
  - `fstream` - utilizata pentru gestionarea fisierelor, permitand salvarea listei pe disk (scriere) si incarcarea ei la repornirea aplicatiei (citire)  
  - `algorithm` - ofera algoritmi standard, folosita in proiect pentru functionalitati precum sortarea listei de cumparaturi sau cautarea/stergerea unui element specific  
  - `json.hpp` (nlohmann/json) - biblioteca externa utilizata pentru salvarea si incarcarea datelor in format JSON  
  - `map` - structura de date cheie-valoare folosita pentru gruparea articolelor pe categorii
- **Tools:** Git, Docker, GitHub Actions

## Cerințe sistem
- Compilator: gcc (suport C++17)  
- Sistem de operare: Windows / Linux  
- Docker (pentru rulare in container)

## Instalare
```bash
# Clone repository  
git clone https://github.com/username/ShoppingList.git  
cd ShoppingList  

# Build 
gcc -std=c++17 src/main.cpp src/Item.cpp src/ShoppingList.cpp -lstdc++ -o shopping_list
```
## Rulare  
```bash
# Comanda de baza
./shopping_list help
```
## Exemple de comenzi
```bash
./shopping_list add mere 5 2.5 fructe
./shopping_list list
./shopping_list list --sort price
./shopping_list search --category fructe
./shopping_list total
```
### Exemple de utilizare
Exemplul 1: Adaugare articol
```bash
./shopping_list add mere 5 2.5 fructe
```
Output asteptat: 
```bash  
Articol adaugat: mere (cantitate: 5, pret unitar: 2.5, total: 12.5, categorie: fructe)
```
Exemplul 2: Listare articole
```bash
./shopping_list list
```
Output asteptat:  
```bash
Nume: mere, Cantitate: 5, Pret unitar: 2.5, Total: 12.5, Categorie: fructe   
Nume: lapte, Cantitate: 2, Pret unitar: 4.5, Total: 9, Categorie: lactate
```
Exemplul 3: Sortare dupa pret 
```bash
./shopping_list list --sort price
```
Output asteptat: 
```bash
Nume: mere, Cantitate: 5, Pret unitar: 2.5, Total: 12.5, Categorie: fructe
Nume: lapte, Cantitate: 2, Pret unitar: 4.5, Total: 9, Categorie: lactate
```
Exemplul 4: Cautare dupa categorie
```bash
./shopping_list search --category fructe
```
Output asteptat:
```bash
Nume: mere, Cantitate: 5, Pret unitar: 2.5, Total: 12.5
```
Exemplul 5: Calcul total
```bash
./shopping_list total
```
Output asteptat:
```bash
Cost total: 12.5 RON
```
Exemplul 6: Cautare categorie inexistenta
```bash
./shopping_list search --category dulciuri
```
Output ateptat:
```bash
Nu exista articole in categoria: dulciuri
```
Exemplul 7: Subtotal pe categorii
```bash
./shopping_list subtotal
```
Output asteptat:
```bash
fructe: 12.5 RON
lactate: 10.5 RON
```
## Functionalitati implementate
[x] Adaugare articole   
[x] Stergere articole   
[x] Listare articole   
[x] Sortare dupa nume, pret si categorie   
[x] Filtrare dupa categorie   
[x] Calcul cost total si subtotaluri   
[x] Export in format CSV   
[x] Salvare si incarcare date JSON   
[x] Meniu de ajutor (help)   

## Structura proiectului
ShoppingList/   
├── src/   
│   ├── main.cpp - logica principala CLI    
│   ├── Item.h / Item.cpp - definitia articolului   
│   ├── ShoppingList.h / ShoppingList.cpp - logica listei de cumparaturi   
├── data/   
│   └── shopping_list.json - date salvate   
├── .github/workflows/   
│   └── build.yml - CI/CD   
├── Dockerfile   
└── README.md   

## Decizie de design
Articolele sunt stocate intr-un vector<Item> deoarece numarul lor este variabil.  
Sortarea este realizata folosind std::sort cu functii lambda.  
Datele sunt salvate in format JSON pentru simplitate si lizibilitate.

## Probleme intalnite si solutii
Problema: Erori de conversie input CLI   
Solutie: Tratarea exceptiilor folosind try-catch   

Problema: Compilare cu gcc pe Windows   
Solutie: Legarea explicita a bibliotecii standard C++ folosind -lstdc++   

## Testare
### Cum sa rulati testele
Aplicatia nu contine teste automate. Testarea a fost realizata manual prin rularea comenzilor in linia de comanda si verificarea rezultatelor afisate.

### Comenzile folosite
```bash
./shopping_list help
./shopping_list add mere 5 2.5 fructe
./shopping_list list
./shopping_list list --sort price
./shopping_list search --category fructe
./shopping_list total
./shopping_list subtotal
./shopping_list export output.csv
```

### Am testat
Pornirea aplicației și afișarea meniului de ajutor.   
Adăugarea articolelor și salvarea lor în fișier JSON.   
Listarea articolelor și sortarea după criterii diferite.   
Căutarea articolelor după categorie.   
Calculul corect al costului total.   
Exportul listei în format CSV.   
Validarea datelor de intrare și tratarea erorilor.   

## Docker
```bash
# Build image
docker build -t shoppinglist .

# Rulare container
docker run shoppinglist help 
```
## Resurse folosite
- https://github.com/nlohmann/json   
- https://docs.github.com/en/actions   
- https://docs.docker.com/   
- Cursul de Programare Orientata pe Obiecte - Crisan-Vida Mihaela Marcella (Universitatea Politehnica Timisoara)

## Contact
Pentru intrebari: bianca-alexandra-iosefina.linca@student.upt.ro
