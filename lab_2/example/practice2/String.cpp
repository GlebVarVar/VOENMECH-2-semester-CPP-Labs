
#include "String.h"

using namespace std;

// конструктор дефолтный
String::String() {
    m_string = new char[100];
    length = 0;
}
// конструтор с параметром
String::String(char *string) { m_string = string; }

// конструктор копирования
String::String(const String &str) { m_string = str.m_string; }

// деструктор
String::~String() {
    cout << "Destructor String" << endl;
    delete m_string;
}

String &String::operator=(String &otherString) {
    m_string = otherString.m_string;
    return *this;
}

// методы получения длины строки
int String::getStringLength() {
    return this-> length;
}

void String::getString() {
    cout << m_string << endl;
}
