#ifndef PRACTICE2_STRING_H
#define PRACTICE2_STRING_H

#include <iostream>
#include <string.h>

using namespace std;

class String {

protected:
    char *m_string;
    int length;
    int id;
    
    
public:
    string type;
    static int count;
    
    virtual void toLower() { std::cout << "B\n"; }
    virtual void hexToDec() { std::cout << "B\n"; }
    char &operator[](int index) {
        count << m_string[index];
        return m_string[index];
    }
    

    // дефолтный конструктор
    String();

    // конструктор принимающий на вход строку
    String(char *string);

    // конструктор копирования
    String(const String &str);

    // деструктор
    virtual ~String();

    // перегрузка оператора '='
    String &operator=(String &otherString);

    // методы
    int getStringLength();
    char * getString();
    int getId();

    void setLength(int length) {
        this->length = length;
    }

    void printProperties(string type) {
        cout << type << " #"<<  id << ": " << m_string << endl;
        cout << "Length: " << length << endl;
        cout << endl;
    }
};

#endif //PRACTICE2_STRING_H
