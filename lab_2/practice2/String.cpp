
#include "String.h"
#include <string.h>

using namespace std;

// конструктор дефолтный
String::String() {
    m_string = new char[100];
    this->type = "String";
    length = 0;
}


// конструтор с параметром
String::String(char *string) { 
    this -> m_string = string; 
    this-> type = "String";
    count++;
    id = count;
}


// конструктор копирования
String::String(const String &str) { 
    m_string = str.m_string; 
    length = str.length;
    count++;
    id = count;
}


// деструктор
String::~String() {
    cout << "Destructor String" << endl;
    delete m_string;
}


// оператор присваивания
String &String::operator=(String &otherString) {
    m_string = otherString.m_string;
    length = otherString.length;

    count++;
    id = count;
    return *this;
}


// геттеры
int String::getStringLength() {
    return this-> length;
}

char * String::getString() {
    return this-> m_string;
}

int String::getId() {
    cout << this-> id << endl;
    return this->id;
}

