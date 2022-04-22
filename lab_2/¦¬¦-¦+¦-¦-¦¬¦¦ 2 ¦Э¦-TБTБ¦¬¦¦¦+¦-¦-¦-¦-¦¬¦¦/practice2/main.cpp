#include <iostream>
#include "HexString.h"

using namespace std;

int main() {
    char s[] = "11aDf";
    HexString hex1 = HexString(s);
    HexString hex2 = HexString("-A");
    HexString *hex3 = hex1 + &hex2;


    cout << "Как написано: " << hex1.m_string << endl;
    hex1.toLower();
    cout << "В нижнем регистре: " << hex1.m_string << endl;
    hex1.toUpper();
    cout << "В верхнем регистре: " << hex1.m_string << endl;

    cout << "Индекс 'A': " << hex1.IndexOf('A') << endl;

    cout << hex1.m_string << " + " << hex2.m_string << " = " << hex3->m_string << endl;

    hex3 = hex1 - &hex2;
    cout << hex1.m_string << " - " << hex2.m_string << " = " << hex3->m_string << endl;

    HexString hexEmpty = HexString("234laf d");
    cout << "Пустая строка потому что есть недопустимые знаки или пробел '" << hexEmpty.m_string << "'." << endl;
    return 0;
}
