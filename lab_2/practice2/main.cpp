#include <iostream>
#include "HexString.h"
#include "menu.h"

using namespace std;


void initializationMenu();
void testingMenu();




int main() {
    int variant;
    

    do {
        printMainMenu();
        variant = getVariant(3);
        switch (variant) {
            case 1:
                initializationMenu();
                break;

            case 2:
                testingMenu();
                break;

            case 3:
                break;
        }

    } while(variant != 3);



    // char s[] = "11aDf";
    // HexString hex1 = HexString(s);
    // HexString hex2 = HexString("-A");
    // HexString *hex3 = hex1 + &hex2;


    // cout << "Start value: " << hex1.m_string << endl;
    // hex1.toLower();
    // cout << "Lower case: " << hex1.m_string << endl;
    // hex1.toUpper();
    // cout << "Upper case: " << hex1.m_string << endl;

    // cout << "Index of 'A': " << hex1.IndexOf('A') << endl;

    // cout << hex1.m_string << " + " << hex2.m_string << " = " << hex3->m_string << endl;

    // hex3 = hex1 - &hex2;
    // cout << hex1.m_string << " - " << hex2.m_string << " = " << hex3->m_string << endl;

    // HexString hexEmpty = HexString("234laf d");
    // cout << "Empty string'" << hexEmpty.m_string << "'." << endl;
    return 0;
}


void initializationMenu() {
    int variant;

    do {
        printInizializationMenu();
        variant = getVariant(3);

        static int count = 0;
        String** list;

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
                

                break;

            case 3:
                break;
        }

    } while(variant != 3);
}


void testingMenu() {
    int variant;

    do {
        printTestingMenu();
        variant = getVariant(5);
        switch (variant) {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;
        }

    } while(variant != 3);
}


