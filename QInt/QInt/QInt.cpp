//
//  QInt.cpp
//  QInt
//
//  Created by TT Nguyen on 10/20/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "QInt.hpp"

//Support Function
int getBit(long data, int position) {
    return (data >> position) & 1;
}

void setBit(long &data, int position) {
    data |= 1UL << position;
}

//Constructor
QInt::QInt() {
    this->data.resize(4);
}

QInt::QInt(string binStr) {
    while (binStr.length() != 128)
        binStr = '0' + binStr;
    this->data.resize(4);
    for (int i = 0; i < 128; i++)
        if (binStr[i] == '1')
            this->data[(127-i) / 32] = this->data[(127-i) / 32] | (1 << 31 - (i % 32));
}

//Convert QInt to 2, 10, 16
string QInt::QInt2Hex() {
    int sum;
    string result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 32; j+=4) {
            sum = getBit(data[i], j) + getBit(data[i], j+1)*2 + getBit(data[i], j+2)*4 + getBit(data[i], j+3)*8;
            if (sum < 10 && sum >= 0)
                result.push_back(sum + 48);
            else
                result.push_back(sum - 10 + 'A');
        }
    reverse(result.begin(), result.end());
    return result;
    
}

string QInt::QInt2Bin() {
    string result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 32; j++)
            result.push_back(getBit(data[i], j) + 48);
    reverse(result.begin(), result.end());
    return result;
}


//Operator + - * /

//Toan tu AND OR XOR NOT
//QInt& QInt::operator=(const QInt &qint) {
//
//    data.resize(4);
//
//    for (int i = 0; i < 4; i++) {
//        data[i] = qint.data[i];
//    }
//    return *this;
//}

//Operator & | ^ ~
QInt QInt::operator & (const QInt &qint) {
    QInt result;
    
    for (int i = 0; i < 4; i++)
        result.data[i] = data[i] & qint.data[i];
    
    return result;
}

QInt QInt::operator | (const QInt &qint) {
    QInt result;
    
    for (int i = 0; i < 4; i++)
        result.data[i] = data[i] | qint.data[i];
    
    return result;
}

QInt QInt::operator^(const QInt &qint) {
    QInt result;
    
    for (int i = 0; i < 4; i++)
        result.data[i] = data[i] ^ qint.data[i];
    
    return result;
}

QInt& QInt::operator~() {
    for (int i = 0; i < 4; i++)
        data[i] = ~data[i];
    return *this;
}

//Convert input to Binary String
string QInt::Dec2Bin(string decStr) {
    while (decStr != "") {
        str.push_back(((decStr[decStr.size() - 1] - 48) % 2) + 48);
        decStr = DividedByTwo(decStr);
    }
    reverse(str.begin(), str.end());
    return str;
}

string QInt::Bin2Bin(string str) {
    str = str;
    return str;
}

string QInt::Oct2Bin(string str) {
    for (int i = 0; i < str.size(); i++)
        switch (str[i]) {
            case '0':
                str += "000";
                break;
            case '1':
                str += "001";
                break;
            case '2':
                str += "010";
                break;
            case '3':
                str += "011";
                break;
            case '4':
                str += "100";
                break;
            case '5':
                str += "101";
                break;
            case '6':
                str += "110";
                break;
            case '7':
                str += "111";
                break;
        }
    return str;
}

string QInt::Hex2Bin(string str) {
    for (int i = 0; i < str.size(); i++)
        switch (str[i]) {
            case '0':
                str += "0000";
                break;
            case '1':
                str += "0001";
                break;
            case '2':
                str += "0010";
                break;
            case '3':
                str += "0011";
                break;
            case '4':
                str += "0100";
                break;
            case '5':
                str += "0101";
                break;
            case '6':
                str += "0110";
                break;
            case '7':
                str += "0111";
                break;
            case '8':
                str += "1000";
                break;
            case '9':
                str += "1001";
                break;
            case 'A':
                str += "1010";
                break;
            case 'B':
                str += "1011";
                break;
            case 'C':
                str += "1100";
                break;
            case 'D':
                str += "1101";
                break;
            case 'E':
                str += "1110";
                break;
            case 'F':
                str += "1111";
                break;
        }
    return str;
}

string QInt::DividedByTwo(string &str) {
    string result;
    int tempValue = 0;
    for (int i = 0; i < str.size(); i++) {
        tempValue = tempValue * 10 + (str[i] - 48);
        if (i > 0 || (i == 0 && tempValue >= 2))
            result.push_back((tempValue / 2) + 48);
        tempValue = tempValue % 2;
    }
    return result;
}



string QInt::BaseNumberConvertation(int first, int second, string data) {
    
    
    switch (first) {
        case 1:
            Bin2Bin(data);
            break;
        case 2:
            Oct2Bin(data);
            break;
        case 3:
            Dec2Bin(data);
            break;
        case 4:
            Hex2Bin(data);
            break;
    }
    
    QInt output(getData());
    
    switch (second) {
        case 1:
            return output.toBinary();
        case 2:
            return "2";
        case 3:
            return output.Bin2Dec();
        case 4:
            return "4";
    }
    return "-1";
}

int main(int argc, const char * argv[]) {
    QInt a("1010101011010101010101011001101010101010110111");
    cout << a.QInt2Bin();
}

string QInt::toBinary() {
    string binStr[128];
    for (int i = 3; i >= 0; i--)
        cout << bitset<32>(data[i]);
    return "h";
}

string QInt::Bin2Dec() {
    int64_t result = 0;
    vector<int64_t> sum;
    
    for (int i = 127; i >= 0; i--)
        sum.push_back(data[i] * pow(2, 127 - i));
    for (int i = 0; i < sum.size(); i++)
        result += sum[i];
    
    return to_string(result);
}




