#include <iostream>
#include "HexString.h"
#include "menu.h"

using namespace std;


int initializationMenu(String**);
void testingMenu();


int String::count = 0;

int main() {
    int variant;
    int flag = 0;
    String** list;
    // char lol[11] = "-10AB";
    // // char lol1[12] = "11AAADDDF22";
    // HexString str1(lol);
    // HexString str2(lol);
    // str1.info();
    // str1.hexToDec();
    // // str1.getString();
    // cout << (str1 == str2) << endl;
    // system("pause");
    

    do {
        printMainMenu();
        variant = getVariant(3);
        switch (variant) {
            case 1:
                flag = initializationMenu(list);
                break;

            case 2:
                if (flag == 0) {
                    cout << "You didn't enter any strings" << endl;
                } else {
                    testingMenu();
                }
                
                system("pause");
                break;

            case 3:
                break;
        }

    } while(variant != 3);

    return 0;
}


int initializationMenu(String ** list) {
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
                }
                
                flagIn++;
                break;

            case 3:
                break;
        }

    } while(variant != 3);
    cout << flagIn;
    system("pause");
    return flagIn;
}


void testingMenu() {
    int variant;

    do {
        printTestingMenu();
        variant = getVariant(4);
        switch (variant) {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            // case 5:
            //     break;
        }

    } while(variant != 4);
}


