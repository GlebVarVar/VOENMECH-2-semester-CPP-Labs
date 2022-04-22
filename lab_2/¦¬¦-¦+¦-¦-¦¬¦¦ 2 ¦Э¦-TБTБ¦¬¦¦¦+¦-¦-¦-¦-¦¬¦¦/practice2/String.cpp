//
// Created by Artur Kabirov on 19/3/22.
//

#include "String.h"

using namespace std;

String::String() {
    m_string = new char[100];
}

String::String(char *string) { m_string = string; }

String::String(const String &str) { m_string = str.m_string; }

String::~String() {
    cout << "Destructor String" << endl;
    delete m_string;
}

String &String::operator=(String &otherString) {
    m_string = otherString.m_string;
    return *this;
}
