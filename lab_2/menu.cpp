#include <iostream>
#include <string.h>
#include "String.h"
#include <stdio.h>
#include "IdentifiedString.h"
#include "HexString.h"
#include "menu.h"

using namespace std;



void printAllStrings(String ** list, int N) {
    int getVariant(int);
    int l = 0;
    IdentifiedString* p;
    HexString* p1;


    for (int i = 0; i < N; i++) {

        int var = printInizializationMenuChooseType(i);

        
        // обработка строки ввода
        string temp;
        getline(cin, temp);
        int tmp = temp.length();
        char* str;
        str = new char[tmp + 1];
        strcpy(str, temp.c_str());

        
        // создание объекта в зависимости от выбранного типа
        if (var == 1) {
            IdentifiedString* p;
            p = new IdentifiedString(str);
            list[l] = p;

        } else {
            HexString* p1;
            p1 = new HexString(str);    
            list[l] = p1;
            
        }
        
        l++;

    }

    // cout << list[0]->getString() << endl;
    // list[0]->getStringLength();
    // cout << list[1]->getString() << endl;
    // list[1]->getStringLength();
    // system("pause");

    

}

void printMainMenu() {

    system("cls"); // очищаем экран

    string menu[] =  { 
        "What do you want to do?",
        "1. Initialization", 
        "2. Testing" };

    printMenu(menu, 3);
    exitMenu(3);
}

void printInizializationMenu() {

    system("cls"); // очищаем экран
    
    string menu[] =  { 
        "What do you want to do?",
        "1. Set the number of elements", 
        "2. Set initial values" };

    printMenu(menu, 3);
    exitMenu(3);
}

int printInizializationMenuChooseType(int i) {
    int getVariant(int);

    system("cls"); // очищаем экран
    cout << "Chosse type for" << " string #" << i + 1  << endl;
    cout << "1. " << "Identifier string" << endl;
    cout << "2. " << "Hexadecimal string" << endl;
    cout << "> ";

    int var = getVariant(2);

    cout << endl << "Enter string" << endl;
    cout << "> ";

    return var;
}

void printTestingMenu() {

    system("cls"); // очищаем экран

    string menu[] =  { 
        "What do you want to do?",
        "1. String",
        "2. Identifier string", 
        "3. Hexadecimal string" };

    printMenu(menu, 4);
    exitMenu(4);
    // cout << "4. Set operands" << endl;

    
}


// class menus
void printStringMenu() {

    system("cls"); // очищаем экран
    
    string menu[] =  { 
        "What do you want to do?",
        "1. To lower", 
        "2. Choose index of string" };

    printMenu(menu, 3);
    // cout << "3. Hexadecimal string" << endl;
}

void printHexMenu() {
    // exitMenu();
}

void printIdentifiedMenu() {
    // exitMenu();
}






