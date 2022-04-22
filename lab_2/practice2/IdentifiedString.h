
#ifndef PRACTICE2_IDENTIFIEDSTRING_H
#define PRACTICE2_IDENTIFIEDSTRING_H


#include "String.h"

class IdentifiedString : public String {
public:
//    дефолтный конструктор
    IdentifiedString() : String() {
        m_string = new char[100];
    }

//    конструктор принимающий в качестве параметра строку
    IdentifiedString(char *string) : String(string) {
//    проверка введеной строки на наличе пробелов.
//    если есть пробелы то строка будет пустой
        // setString(string);
        this -> m_string = string;
    }

    // конструктор копирования
    IdentifiedString(const IdentifiedString &str);

    // деструктор
    ~IdentifiedString();

//    проверка строки, если содержит пробелы записать пустую строку
    void setString(char *string);

//    получение первого вхождения символа в строку
    int IndexOf(char c);

};


#endif //PRACTICE2_IDENTIFIEDSTRING_H
