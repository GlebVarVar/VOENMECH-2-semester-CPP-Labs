
#include "IdentifiedString.h"

// конструктор копирования
IdentifiedString::IdentifiedString(const IdentifiedString &str) { m_string = str.m_string; }

IdentifiedString::~IdentifiedString() {
    cout << "Destructor IdentifiedString" << endl;
    delete m_string;
}

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
        length = ++i;
    } else {
        m_string = new char[100];
        length = 0;
    }
        
}

int IdentifiedString::IndexOf(char c) {
    int i = 0;
    while (m_string[i] != '\0') {
        if (m_string[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}
