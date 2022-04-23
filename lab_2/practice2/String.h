#ifndef PRACTICE2_STRING_H
#define PRACTICE2_STRING_H

#include <iostream>

using namespace std;

class String {

protected:
    char *m_string;
    int length;
    int id;
    
public:

    static int count;
    
    

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

    // методы
    int getStringLength();
    char * getString();
    void getId();
};

#endif //PRACTICE2_STRING_H
