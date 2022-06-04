
#include <cmath>
#include "HexString.h"

HexString::HexString(const HexString &str) {
    m_string = str.m_string;
    length = str.length;
    isPositive = str.isPositive;

    count++;
    id = count;
}

HexString::~HexString() {
    cout << "Destructor HexString" << endl;
    delete m_string;
}

int HexString::char2dec(char hexChar) {
    if ((hexChar >= '0') && (hexChar <= '9'))
        return hexChar - '0';
    else if ((hexChar >= 'A') && (hexChar <= 'F'))
        return hexChar - 'A' + 10;
    else if ((hexChar >= 'a') && (hexChar <= 'f'))
        return hexChar - 'a' + 10;

}


// сеттер поля m_string
void HexString::setString(char *string) {
    int i = 0, j;
    bool flag = false;

    while (string[i] != '\0') {
        j = 0;
        while (hexNumbers[j] != '\0') {
            if (hexNumbers[j] == string[i]) {
                flag = true;
                break;
            }
            j++;
        }

        if (flag == false) {
            char *empty = "";
            m_string = empty;
            length = 0;
            return;
        }
        flag = false;
        i++;
    }

    if (i != 0) {
        length = i;
        m_string = string;


        if (m_string[0] == '+') {
            isPositive = true;
            length--;
        } else if (m_string[0] == '-') {
            isPositive = false;
            length--;
        } else {
            isPositive = true;
        }
    }
    
    
}


// перевод hex строки в десятичное число
void HexString::hexToDec() {
    int i;
    int l = length;
    int decimal = 0;
    i = (m_string[0] == '+') ?  1 : ((m_string[0] == '-') ? 2 : 0);

    if (i == 2) {
        cout << "Impossible to convert to unsigned int" << endl;
        return;
    }
    while (m_string[i] != '\0') {
        decimal += char2dec(m_string[i]) * pow(16, --l);
        i++;
    }
    decimal *= isPositive ? 1 : -1;
    cout << "Decimal: " << decimal << endl;
    // return decimal;
}


// получение информации о строке
void HexString::info() {
    cout << "HexString " << id << ": " << m_string << endl;
    cout << "Length: " << length << endl;
    cout << endl;
}


