//
// Created by Artur Kabirov on 19/3/22.
//

#ifndef PRACTICE2_STRING_H
#define PRACTICE2_STRING_H

#include <iostream>

using namespace std;

class String {
public:
    char *m_string;

    // дефолтный конструктор
    String();

    // конструктор принимающий на вход строку
    String(char *string);

    // конструктор копирования
    String(const String &str);

    // деструктор
    ~String();

    // перегрузка оператора '='
    String &operator=(String &otherString);

};

#endif //PRACTICE2_STRING_H
