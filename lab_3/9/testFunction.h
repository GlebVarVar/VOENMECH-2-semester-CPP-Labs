#if !defined(TestFunction_H)
#define TestFunction_H

// Заголовочные файлы
#include "iostream"
#include "algorithm"
#include "string"
// Функции-помощники
#include "..\..\helpFunctions\functions.h"


using namespace std;


// Функции
template <class T>
void testFunctionInput(int size, int max, T *list);

template <class T> 
int printSortedList (T mas[], int n);

template <class T>
void sort (T mas[], int n, int flag);

int getVariantTemplate(int count);

#endif // TestFunction_H
