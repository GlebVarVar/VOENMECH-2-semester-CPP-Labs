
#ifndef PRACTICE2_IDENTIFIEDSTRING_H
#define PRACTICE2_IDENTIFIEDSTRING_H


#include "String.h"

class IdentifiedString : public String {
public:

    // дефолтный конструктор
    IdentifiedString() : String() {
        m_string = new char[100];
    }

    // конструктор принимающий на вход строку
    IdentifiedString(char *str) {

        // проверка введеной строки на наличе пробелов, если есть пробелы то строка будет пустой
        setString(str);
        count++;
        this-> id = count;
    }

    // конструктор копирования
    IdentifiedString(const IdentifiedString &str);

    // деструктор
    ~IdentifiedString();

    // проверка строки, если содержит пробелы записать пустую строку
    void setString(char *string);


    // перевод буквеной части числа в нижн. регистр
    void toLower();

    // перегрузка оператора индексации [ ]
    char &operator[](int index);

    // перегрузка оператора >=
    bool operator >= (const IdentifiedString &str);

};


#endif //PRACTICE2_IDENTIFIEDSTRING_H
