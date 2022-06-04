#if !defined(MAIN_H)
#define MAIN_H

#include <iostream>
#include "String.h"

#include "..\helpFunctions\functions.h"


String ** initializationMenu(String**);
void testingMenu(String ** list);
void printTypesOfStrings(String ** list, int var);
int typeCheck(String ** list, string var, int i, int countOfStrings);
void objectMenu (String ** list, string str, int numberOfElement);
int idenStr(String ** list, int order);
int hexStr(String ** list, int order);

#endif // main.h