

#ifndef PRACTICE2_HEXSTRING_H
#define PRACTICE2_HEXSTRING_H
#include <iostream>
#include "IdentifiedString.h"
#include "String.h"


class HexString : public String {
private:
    // переменная hexNumbers показывает какие символы может содержать строка
    const char *hexNumbers = "+-0123456789AaBbCcDdEeFf";
    // длина числа (знак не считается).  Удобно для конвертации из hex в dec и в обратную

    // метод переводит символы в десятичные числа
    int char2dec(char hexChar);

public:
    

    // обозначает какого знака число
    bool isPositive = true;

    // дефолтный конструктор
    HexString() : String() { m_string = new char[100]; };

    // деструктор
    ~HexString();

    // конструктор принимающий в качестве параметра строку
    HexString(char *str) {
        setString(str);
    
        count++;
        this-> id = count;
    }

    // конструктор копирования
    HexString(const HexString &str);

    // сеттер поля m_string
    void setString(char *string);


    // перевод hex строки в десятичное число
    void hexToDec();



    // перегрузка оператора >
    bool operator > (const HexString &str) {
        return (length > str.length);
    }

    // перегрузка оператора ==
    bool operator == (HexString &str) {
        return (this->getString() == str.getString());
    }

    // получение информации о строке
    void info();


};

#endif //PRACTICE2_HEXSTRING_H
