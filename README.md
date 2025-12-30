# ShoppingList

## Descriere
Aceasta aplicatie CLI permite gestionarea unei liste de cumparaturi. Utilizatorul poate adauga, sterge, lista, sorta, filtra articole, calcula costul total si exporta datele in format CSV. Datele sunt salvate in format JSON.

## Tehnologii folosite
 - **Limbaj:** C++
 - **Compilator:** gcc
 - **STL:** (vector, map, algorithm)
 - **Librarie JSON:** nlohmann/json
 - **Sistem de control al versiunilor:** Git (folosit prin GitHub Desktop)
 - **Repository online:** GitHub
 - **Editor de cod:** Visual Studio Code

 ## Compilare
 **Proiectul se compileaza folosind gcc:**   
 ```bash
 gcc -std=c++17 src/main.cpp src/Item.cpp src/ShoppingList.cpp -lstdc++ -o shopping_list.exe
 ```

 ## Rulare
 **Aplicatia se ruleaza din linia de comanda:**    
 ```./shopping_list <comanda> [optiuni]```

 ## Comenzi disponibile
  - **Adaugare articol:**    
  ```./shopping_list add <nume> <cantitate> <pret> <categorie>```  
  - **Stergere articol:**   
 ```./shopping_list remove <nume>```  
  - **Listare articol:**  
    ```./shopping_list list```    
    ```./shopping_list list --sort name```    
    ```./shopping_list --sort price```    
    ```./shopping_list --sort category```    
  - **Cautare dupa categorie:**   
  ```./shopping_list search --category <categorie>```  
  - **Cost total:**    
  ```./shopping_list total```  
  - **Export CSV:**    
  ```./shopping_list export <fisier.csv>```  
  - **Ajutor:**   
  ```./shopping_list help```  

 ## Salvarea datelor
 **Datele sunt salvate automat in fisierul:**    
 ```data/shopping_list.json```

 ## Structura proiectului
 ```
 |-- src/
 |   |-- Item.h
 |   |-- Item.cpp
 |   |-- ShoppingList.h
 |   |-- ShoppingList.cpp
 |   |-- main.cpp
 |-- data/
 |   |-- shopping_list.json
```


 ## Autor
 Linca Bianca-Alexandra-Iosefina

