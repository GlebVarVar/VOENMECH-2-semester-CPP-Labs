

#ifndef PRACTICE2_HEXSTRING_H
#define PRACTICE2_HEXSTRING_H
#include <iostream>
#include "IdentifiedString.h"
#include "String.h"


class HexString : public String {
private:
//    переменная hexNumbers показывает какие символы..
// ..может содержать строка
    const char *hexNumbers = "+-0123456789AaBbCcDdEeFf";
// длина числа (знак не считается).
// удобно для конвертации из hex в dec и в обратную
    int length;

//   метод переводит символы в десятичные числа
    int char2dec(char hexChar);

public:
//    обозначает какого знака число
    bool isPositive = true;

//  наследуемы конструктор
    HexString() : String() { m_string = new char[100]; };

//    деструктор
    ~HexString();

//    конструктор принимающий в качестве параметра строку
    HexString(char *string) : String(string) {
        // setString(string);
        this-> m_string = string;

    }

//    конструктор копирования
    HexString(const HexString &str);

//    Сеттер поля m_string
    void setString(char *string);

//    перевод буквеной части числа в верх. регистр
    void toUpper();

//    перевод буквеной части числа в нижн. регистр
    void toLower();

//    перевод hex строки в десятичное число
    int hexToDec();

//    десятичное число в hex строку
    char *decToHex(int n);

//    перегрузка оператора +
    HexString *operator+(HexString *anotherHex);

//    перегрузка оператора -
    HexString *operator-(HexString *anotherHex);

};

#endif //PRACTICE2_HEXSTRING_H
