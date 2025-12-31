FROM gcc:latest

WORKDIR /usr/src/app

COPY src ./src

COPY data ./data

RUN gcc -std=c++17 src/main.cpp src/Item.cpp src/ShoppingList.cpp -lstdc++ -o shopping_list

ENTRYPOINT [ "./shopping_list" ]