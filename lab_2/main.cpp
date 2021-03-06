#include <iostream>
#include "HexString.h"
#include "menu.h"
#include "main.h"

// подключакм функции-помощники
#include "..\helpFunctions\functions.cpp"

using namespace std;




int String::count = 0;


int masLength = 0;
int initializedMass = 0;

int main() {
    int variant;
    int flag = 0;
    String** listOld;
     String** list;

    // for testing

    // char lol[11] = "-10AB";
    // char lol1[12] = "11AAADDDF22";
    // IdentifiedString str1(lol);
    // HexString str2(lol);
    // str1[1];
    // str1.info();
    // str1.hexToDec();
    // str1.getString();
    // cout << (str1 == str2) << endl;
    // system("pause");
    

    do {
        printMainMenu();
        variant = getVariant(3);
        switch (variant) {
            case 1:
                list = initializationMenu(listOld);
                break;

            case 2:
                
                if (initializedMass == 1) {
                    testingMenu(list);

                } else {
                    cout << "You didn't enter any strings" << endl;
                    system("pause");
                }

                break;

            case 3:
                break;
        }

    } while(variant != 3);

    return 0;
}


String ** initializationMenu(String ** list) {
    int variant;
    int flagIn = 0;

    do {
        printInizializationMenu();
        variant = getVariant(3);

        static int count = 0;
        // String** list;

        switch (variant) {
            case 1: {
                if (count != 0) {
                    cout << "You have already initialized the array" << endl;
                    system("pause");
                    break;
                } else {
                    system("cls");
                    cout << "Enter list size" << endl << ">";
                    count = getVariant(10);
                    cout << count << endl;
                    masLength = count;
                    list = new String*[count];
                    break;
                }
            }
            case 2:
                if (count == 0) {
                    cout << "Initialized the array first" << endl;
                    system("pause");
                    break;
                } else {
                    printAllStrings(list, count);
                    initializedMass++;
                }
                
                flagIn++;
                break;

            case 3:
                break;
        }

    } while(variant != 3);
    return list;
}


void testingMenu(String ** list) {
    int variant;
    do {
        printTestingMenu();
        variant = getVariant(4);

        if (variant != 4) printTypesOfStrings(list, variant);

    } while(variant != 4);
    // cout << "End" << endl;
    // system("pause");
}

void printTypesOfStrings(String ** list, int var) {
    // cout << "Start" << list[0]->getString() << endl;
    // system("pause");
    int countOfStrings = 1;
    string str;
    switch (var) {
        case 1:
            str = "String";
            break;
        case 2:
            str = "IdentifiedString";
            break;
        case 3:
            str = "HexString";
            break;
    }

    do {
        countOfStrings = 1;
        system("cls");
        for (int j = 0; j < masLength; j++) {
            // cout << "Start loop " << flag <<" " << j<< " var"<< var<< endl;
            // system("pause");
            countOfStrings = typeCheck(list, str, j, countOfStrings);

        }
        exitMenu(countOfStrings);
        var = getVariant(countOfStrings);

        if (var != countOfStrings) {
            objectMenu(list, str, var);

        }
        
        
        

    } while (var != countOfStrings);
    
       
}


void objectMenu (String ** list, string str, int numberOfElement) {

    int var;
    int counter = 0;
    int order = 0;

    for(int j = 0; j < masLength; j++) {
        if (list[j]->type == str) {
            order = j;
            ++counter;
            if (counter == numberOfElement) break;
        }
    }

    
    if (str == "HexString") {
        do {
            system("cls");
            var = hexStr(list, order);
        } while (var != 3);

    } else if (str == "IdentifiedString") {
         do {
            system("cls");
            var = idenStr(list, order);
        } while (var != 4);
        
    }
    
    
}


int typeCheck(String ** list, string var, int i, int count) {
    // cout << list[i]->getString() << endl;
    // cout << list[i]->type << var << endl;
    if (var == list[i]->type) {
        cout << count++ << ". " << list[i]->type <<" #"<<i+1<< endl;
    }
    return count;
}


int idenStr(String ** list, int order) {

    int var;
    
    string menu[] =  { 
        "What do you want to do?",
        "1. Print properties",
        "2. To lower register", 
        "3. Choose index of string" };

    printMenu(menu, 4);
    exitMenu(4);

    var = getVariant(4);

    switch (var) {
        case 1:
            system("cls");
            list[order]->printProperties(list[order]->type);
            system("pause");
            break;
        case 2:
            system("cls");
            list[order]->toLower();
            cout << "String is " << list[order]->getString() << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "choose index from 0 to " << list[order]->getStringLength() << endl << ">";
            int index = getVariant(list[order]->getStringLength());
            system("cls");
            cout << "Elem #" << index << " - " << (list[order]->getString())[index-1] << endl;
        
            system("pause");
            break;
        
    }

    return var;
}

int hexStr(String ** list, int order) {


    int var;

    string menu[] =  { 
        "What do you want to do?",
        "1. Print properties", 
        "2. Heximal to decimal" };

    printMenu(menu, 3);
    exitMenu(3);

    var = getVariant(3);
    system("cls");
    switch (var) {
        case 1:
            list[order]->printProperties(list[order]->type);
            break;

        case 2:
            list[order]->hexToDec();
            break;
        
    }
    system("pause");

    return var;
}