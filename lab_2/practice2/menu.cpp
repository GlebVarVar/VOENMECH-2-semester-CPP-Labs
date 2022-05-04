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
    cout << "What do you want to do?" << endl;
    cout << "1. Initialization" << endl;
    cout << "2. Testing" << endl;

    exitMenu(3);
}

void printInizializationMenu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. Set the number of elements" << endl;
    cout << "2. Set initial values" << endl;

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
    cout << "Choose string type?" << endl;
    cout << "1. String" << endl;
    cout << "2. Identifier string" << endl;
    cout << "3. Hexadecimal string" << endl;
    exitMenu(4);
    // cout << "4. Set operands" << endl;

    
}


// class menus
void printStringMenu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. To lower" << endl;
    cout << "2. Choose index of string" << endl;
    // cout << "3. Hexadecimal string" << endl;
}

void printHexMenu() {
    // exitMenu();
}

void printIdentifiedMenu() {
    // exitMenu();
}



void exitMenu(int exitNumber) {
    cout << string ( 25,  '-' ) << endl;
    cout << exitNumber << ". Exit" << endl <<  endl;
    cout << "> ";
} 


int getVariant(int count) {
    int var;
    cin.clear();
    string s; // строка для считывания введённых данных
    getline(cin, s); // считываем строку
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &var) != 1 || var < 1 || var > count) {
        if (s.size() != 0) {
            cout << "Incorrect input. Try again: "; // выводим сообщение об ошибке
            getline(cin, s); // считываем строку повторно
        } else {
            var = getVariant(count);
            if (var >= 1 || var <= count) {
                break;
            }
        }
    }

    return var;
}



