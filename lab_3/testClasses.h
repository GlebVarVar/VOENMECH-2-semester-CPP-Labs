#if !defined(TEST_CLASSES_H)
#define TEST_CLASSES_H

// Заголовочные файлы
#include "string"
// функции-помощники
#include "..\helpFunctions\functions.h"
// файлы проекта
#include ".\Classes\stackArray.h"
#include ".\Classes\stackList.h"
#include ".\Classes\stack.h"

using namespace std;


template <class T>
void templateClassTest (Stack<T> * );


#endif // TEST_CLASSES_H
