#if !defined(TestFunction_H)
#define TestFunction_H

// Заголовочные файлы
#include "iostream"
#include "algorithm"
#include "string"
#include <iomanip> 
// Функции-помощники
#include "..\..\helpFunctions\functions.h"


using namespace std;


// Функции
template <class T>
void testFunctionInput(int , T *);

template <class T> 
int printSum (T mas[], int );


int getVariantTemplate(int );

#endif // TestFunction_H
