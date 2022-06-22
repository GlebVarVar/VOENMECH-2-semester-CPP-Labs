
#include "IdentifiedString.h"

// конструктор копирования
IdentifiedString::IdentifiedString(const IdentifiedString &str) { 
    m_string = str.m_string; 
    length = str.length;
    count++;
    id = count;
}

// деструктор
IdentifiedString::~IdentifiedString() {
    cout << "Destructor IdentifiedString" << endl;
    delete m_string;
}

// проверка строки
void IdentifiedString::setString(char *string) {
    int i = 0;
    bool containSpace = false;

    while (string[i] != '\0') {
        if (string[i] == ' ') {
            containSpace = true;
            break;
        }
        i++;
    }
    if (containSpace == false) {
        m_string = string;
        length = i;
    } else {
        m_string = "";
        length = 0;
    }
        
}


// перевод буквеной части числа в нижн. регистр
void IdentifiedString::toLower() {
    int i = 0;
    while (m_string[i] != '\0') {
        if ('A' <= m_string[i] && m_string[i] <= 'F')
            m_string[i] += 32;
        i++;
    }
}


// перегрузка оператора индексации >=
bool IdentifiedString::operator >= (const IdentifiedString &str) {
    return (length >= str.length);
}


// перегрузка оператора []
char &IdentifiedString::operator[](int index) {
    cout << m_string[index];
    return m_string[index];

}






