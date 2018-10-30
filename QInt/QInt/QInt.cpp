//
//  QInt.cpp
//  QInt
//
//  Created by TT Nguyen on 10/20/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "QInt.hpp"
#include "float.h"



//Constructor

//Khởi tạo kiểu QInt với vùng nhớ là 4 biến kiểu long 32bit
QInt::QInt() {
    this->data.resize(4);
}

//Khởi tạo kiểu QInt với vùng nhớ là 4 biến kiểu long 32bit, giá trị truyền vào là chuỗi string, sử dụng phép tính toán số học để gán dãy bit vào 4 biến kiểu long(vùng nhớ của QInt)
QInt::QInt(string binStr) {
    while (binStr.length() != 128)
        binStr = '0' + binStr;
    this->data.resize(4);
    for (int i = 0; i < 128; i++)
        if (binStr[i] == '1')
            this->data[(127-i) / 32] = this->data[(127-i) / 32] | (1 << (31 - (i % 32)));
}

//Convert input to Binary String

//Hàm chuyển đổi từ hệ 10 sang hệ 2
string QInt::Dec2Bin(string decStr) {
    string str;
    while (decStr != "") {
        str.push_back(((decStr[decStr.size() - 1] - 48) % 2) + 48);
        decStr = DividedByTwo(decStr);
    }
    reverse(str.begin(), str.end());
    return str;
}

//Hàm trả về hệ 2
string QInt::Bin2Bin(string bin) {
    return bin;
}

//Hàm chuyển từ hệ 8 sang hệ 2
string QInt::Oct2Bin(string oct) {
    string str;
    for (int i = 0; i < oct.size(); i++)
        switch (oct[i]) {
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

//Hàm chuyển từ hệ 16 sang hệ 2
string QInt::Hex2Bin(string hex) {
    string str;
    for (int i = 0; i < hex.size(); i++)
        switch (hex[i]) {
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

//Convert QInt to 2, 10, 16

//Hàm chuyển từ kiểu QInt sang hệ 16 dạng chuỗi
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

//Hàm chuyển từ kiểu QInt sang hệ 2 dạng chuỗi
string QInt::QInt2Bin() {
    string result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 32; j++)
            result.push_back(getBit(data[i], j) + 48);
    reverse(result.begin(), result.end());
    return result;
}

string QInt::QInt2Dec() {
    long double temp;
    string saveString;
    string result;
    int dotOfFloatNumber = 0;
    vector<bool> m_data;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 32; j++)
            m_data.push_back(getBit(data[i], j));
    
    for (int i = 0; i < 128; ++i) {
        temp = m_data[i] * pow(2, i);
        saveString = to_string(temp);
        dotOfFloatNumber = saveString.find_first_of(".");
        saveString.erase(dotOfFloatNumber, saveString.size() - dotOfFloatNumber);
        result = Add2String(result, saveString);
    }
    return result;
}


//Operator + - * /
QInt QInt::operator +(QInt qint) //Sai rồi :)
{
    QInt q = *this;
    QInt result;
    result.data.clear();
    
    int length = q.data.size() > qint.data.size() ? q.data.size() : qint.data.size();
    
    q.data.resize(length);
    qint.data.resize(length);
    
    long extra = 0;
    long temp = 0;
    for (int i = 0; i <length; i++)
    {
        temp = q.data[i] + qint.data[i] + extra;
        extra = 0;
        if (temp <= 9 || i == 0)
        {
            result.data.push_back(temp );
            //extra = temp / 10;
        }
        else
        {
            result.data.push_back(temp % 10);
            //extra = temp / 10;
            extra = 1;
        }
    }
    if (extra > 0)
        result.data.push_back(temp);
    return result;
}


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

QInt QInt::operator <<(const int times) {
    QInt result;
    result.data = data;
    for (int j = 0; j < times; j++)
        for (int i = 3; i >= 0; i--) {
            result.data[i] = result.data[i] << 1;
            if (getBit(result.data[i-1], 31) == 1)
                setBit(result.data[i], 0);
        }
    return result;
}

QInt QInt::operator >>(const int times) { 
    QInt result;
    result.data = data;
    for (int j = 0; j < times; j++)
        for (int i = 0; i < 4; i++) {
            result.data[i] = result.data[i] >> 1;
            if (getBit(result.data[i+1], 0) == 1)
                setBit(result.data[i], 31);
            if (getBit(data[3], 31) == 1)
                setBit(result.data[3], 31);
        }
    return result;
}

QInt QInt::operator ==(const int times) {
    QInt result;
    result.data = data;
    for (int j = 0; j < times; j++)
        for (int i = 0; i < 4; i++) {
            result.data[i] = result.data[i] >> 1;
            if (getBit(result.data[i+1], 0) == 1)
                setBit(result.data[i], 31);
        }
    return result;
    
}


QInt& QInt::RoL(const int times) {
    for (int i = 0; i < times; i++) {
        if (getBit(data[3], 31) == 1) {
            *this = *this << 1;
            setBit(data[0], 0);
        } else {
            *this = *this << 1;
        }
    }
    return *this;
}

QInt& QInt::RoR(const int times) {
    for (int i = 0; i < times; i++) {
        if (getBit(data[0], 0) == 1) {
            *this = *this >> 1;
            setBit(data[3], 31);
        } else {
            *this = *this == 1;
        }
    }
    return *this;
}

//Support Function
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
} //Chia 2 chuỗi số hệ 10

int QInt::getBit(uint32_t data, int position) {
    return (data >> position) & 1;
} //Lấy bit tại vị trí position

int QInt::setBit(uint32_t &data, int position) {
    data = (1 << position) | data;
    return data;
}

string QInt::Add2String(string &num1, string &num2) {
    int tempNum = 0;
    //Thêm 0 vào 2 dãy đến khi chúng có chiều dài bằng nhau
    if (num1.size() > num2.size())
        while (num1.size() != num2.size())
            num2.insert(num2.begin(), '0');
    else
        while (num1.size() != num2.size())
            num1.insert(num1.begin(), '0');
    
    for (int i = num1.size() - 1; i >= 0; i--) {
        tempNum = tempNum + num1[i] + num2[i] - 2 * '0';
        num1[i] = (tempNum % 10) + '0';
        tempNum = tempNum / 10;
    }
    
    if (tempNum != 0) {
        num1.insert(num1.begin(), tempNum + '0');
        tempNum = 0;
    }
    
    while (num1[0] == '0')
        num1.erase(num1.begin());
    
    return num1;
}

string QInt::Substract2String(string &num1, string &num2) {
    int Temp = 0;
    
    if (num1.size() > num2.size())
        while (num1.size() != num2.size())
            num2.insert(num2.begin(), '0');
    else
        while (num1.size() != num2.size())
            num1.insert(num1.begin(), '0');
    
    if (strcmp(num1.c_str(), num2.c_str()) < 0) {
        string TempStr = num1;
        num1 = num2;
        num2 = TempStr;
    }
    
    for (int i = num1.size() - 1; i > -1; i--) {
        if ((num1[i] - Temp) < num2[i]) {
            num1[i] = (10 + num1[i] - num2[i] - Temp) + '0';
            Temp = 1;
        } else {
            num1[i] = num1[i] - num2[i] - Temp + '0';
            Temp = 0;
        }
    }
    
    while (num1[0] == '0')
        num1.erase(num1.begin());
    return num1;
}



