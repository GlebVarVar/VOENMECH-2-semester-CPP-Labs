#include <iostream>
#include <string.h>
#include "String.h"
#include <stdio.h>
#include "IdentifiedString.h"
#include "HexString.h"

using namespace std;




void printMainMenu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. Initialization" << endl;
    cout << "2. Testing" << endl;

    cout << string ( 25,  '-' ) << endl;
    cout << "3. Exit" << endl <<  endl;
    cout << "> ";
}


void printInizializationMenu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. Set the number of elements" << endl;
    cout << "2. Set initial values" << endl;

    cout << string ( 25,  '-' ) << endl;
    cout << "3. Exit" << endl <<  endl;
    cout << "> ";
}


void printTestingMenu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. Set the number of elements" << endl;
    cout << "2. String" << endl;
    cout << "3. Identifier string" << endl;
    cout << "4. Hexadecimal string" << endl;

    cout << string ( 25,  '-' ) << endl;
    cout << "5. Exit" << endl <<  endl;
    cout << "> ";
}


void printAllStrings(String ** list, int N) {
    int getVariant(int);
    static int l = 0;
    IdentifiedString* p;
    HexString* p1;

    for (int i = 0; i < N; i++) {
        system("cls"); // очищаем экран


        cout << "Chosse type for" << " string #" << i + 1  << endl;
        cout << "1. " << "Identifier string" << endl;
        cout << "2. " << "Hexadecimal string" << endl;
        cout << "> ";
        int var = getVariant(2);

        cout << endl << "Enter string" << endl;
        cout << "> ";
        
        char str[100];
        string temp;
        cin >> temp;

        strcpy(str, temp.c_str());

        
        
        if (var == 1) {
            IdentifiedString* p;
            p = new IdentifiedString(str);
            // IdentifiedString identifierString(str);
            cout << p << " " << &list[l];
            list[l] = p;
            cout << str << endl;
        } else {
            // HexString hexString(str); 
            HexString* p1;
            p1 = new HexString(str);   
            cout << p1 << " " << &list[l];    
            list[l] = p1;
            cout << str << endl;
        }
        system("pause");
        l++;

    }
    system("pause");
    list[0]->getString();
    list[1]->getString();
    cout << p << " " << &(*list[0]) << endl;
    cout << p1 << " " << &(*list[1])<< endl ;   
    system("pause");

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