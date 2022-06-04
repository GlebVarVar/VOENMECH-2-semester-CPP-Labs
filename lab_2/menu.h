#if !defined(MENU_H)
#define MENU_H

#include <iostream>
#include "string.h"

#include "..\helpFunctions\functions.h"


using namespace std;

// class HelpFunctions {
//     public:
//         static void printPropertiesFunc (String ** list, int order );
// };


// void HelpFunctions::printPropertiesFunc (String ** list, int order ) {
//     system("cls");
//     list[order]->printProperties(list[order]->type);
//     system("pause");
// }


int getVariant(int);

void printMainMenu();
void printInizializationMenu();
void printTestingMenu();
void printAllStrings(String**, int);
void exitMenu(int);
int printInizializationMenuChooseType(int );


#endif // menu.h


