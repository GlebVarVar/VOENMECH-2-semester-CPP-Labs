
#include <cmath>
#include "HexString.h"

HexString::HexString(const HexString &str) {
    m_string = str.m_string;
    length = str.length;
    isPositive = str.isPositive;
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
            m_string = new char[100];
            return;
        }
        flag = false;
        i++;
    }

    length = i;
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

void HexString::toUpper() {
    int i = 0;
    while (m_string[i] != '\0') {
        if ('a' <= m_string[i] && m_string[i] <= 'f') {
            m_string[i] -= 32;
        }
        i++;
    }
}

void HexString::toLower() {
    int i = 0;
    while (m_string[i] != '\0') {
        if ('A' <= m_string[i] && m_string[i] <= 'F')
            m_string[i] += 32;
        i++;
    }
}

int HexString::hexToDec() {
    int i;
    int l = length;
    int decimal = 0;
    i = (m_string[0] == '+') || (m_string[0] == '-') ? 1 : 0;
    while (m_string[i] != '\0') {
        decimal += char2dec(m_string[i]) * pow(16, --l);
        i++;
    }
    decimal *= isPositive ? 1 : -1;

    return decimal;
}

char *HexString::decToHex(int n) {
    char *hexaDeciNum = new char[100];
    char tmp;

    int i = 0;
    while (n != 0) {
        int temp;

        temp = n % 16;

        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
        } else {
            hexaDeciNum[i] = temp + 55;

        }
        i++;
        n = n / 16;
    }

    for (int end = i - 1, start = 0; i / 2 > 0; end--, start++) {
        tmp = hexaDeciNum[end];
        hexaDeciNum[end] = hexaDeciNum[start];
        hexaDeciNum[start] = tmp;
        i--;
    }

    return hexaDeciNum;
}

HexString *HexString::operator+(HexString *anotherHex) {
    int resultDec = hexToDec() + anotherHex->hexToDec();
    bool flag = resultDec < 0;
    char *resHex;
    if (flag) {
        resHex = decToHex(resultDec * -1);
        int i = 0, len;
        while (resHex[i++] != '\0');
        len = i;
        for (int j = i; j > 0; j--) {
            resHex[j] = resHex[j - 1];
        }
        resHex[0] = '-';

    } else {
        resHex = decToHex(resultDec);
    }

    return new HexString(resHex);
}

HexString *HexString::operator-(HexString *anotherHex) {
    int resultDec = hexToDec() - anotherHex->hexToDec();
    bool flag = resultDec < 0;
    char *resHex;
    if (flag) {
        resHex = decToHex(resultDec * -1);
        int i = 0, len;
        while (resHex[i++] != '\0');
        len = i;
        for (int j = i; j > 0; j--) {
            resHex[j] = resHex[j - 1];
        }
        resHex[0] = '-';

    } else {
        resHex = decToHex(resultDec);
    }

    return new HexString(resHex);
}