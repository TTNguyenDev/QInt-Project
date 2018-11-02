//
//  QFloat.cpp
//  QInt
//
//  Created by TT Nguyen on 10/26/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "QFloat.hpp"
#include <math.h>

QFloat::QFloat() {
    this->data.resize(4);
} //Khởi tạo QFloat được lưu trữ bằng 4 biến uint32_t

QFloat::QFloat(string input, int type) { //2 hoac 10
    this->data.resize(4);
    string result = "";
    
    if (type == 2)
        result = BinFloat2Bin(input);
    if (type == 10)
        result = DecFloat2Bin(input);
    
    for (int i = 0; i < 128; i++)
        if (result[i] == '1')
            this->data[(127-i) / 32] = this->data[(127-i) / 32] | (1 << (31 - (i % 32)));
} //Khởi tạo QFloat từ chuỗi string nhập vào từ bàn phím ở hệ 2 hoặc 10

string QFloat::DecFloat2Bin(string floatString) {
    bool negative = false;
    if (floatString[0] == '-') {
        negative = true;
        floatString.erase(floatString.begin());
    }
    int dotPostion;
    string int_significant;
    string fraction_significant;
    string bit;
    int k;
    
    dotPostion = floatString.find_first_of('.');
    
    if (dotPostion == string::npos) {
        int_significant = floatString;
        fraction_significant = "0";
    } else {
        int_significant = floatString.substr(0, dotPostion);
        fraction_significant = floatString.substr(dotPostion);
        fraction_significant.insert(fraction_significant.begin(), '0');
    }
    
    int_significant = convertInt(int_significant);
    
    k = (1 << 14) - 1;
    
    if (int_significant != "") {
        exp = int_significant.size() - 1 + k;
        for (int i = 0; i < 112 - int(int_significant.size() - 1); ++i) {
            fraction_significant = multiplyAfterDotByTwo(fraction_significant);
            bit += fraction_significant[0];
            fraction_significant[0] = '0';
        }
    } else {
        int cnt = 0;
        while (cnt < k) {
            fraction_significant = multiplyAfterDotByTwo(fraction_significant);
            bit += fraction_significant[0];
            fraction_significant[0] = '0';
            if (bit.back() == '1') break;
            cnt++;
        }
        
        exp = -(cnt + 1) + k;
        if (cnt + 1 < k) {
            for (int i = 0; i < 112; ++i) {
                fraction_significant = multiplyAfterDotByTwo(fraction_significant);
                bit += fraction_significant[0];
                fraction_significant[0] = '0';
            }
        } else {
            bit = "";
            while (exp < 1) {
                fraction_significant = multiplyAfterDotByTwo(fraction_significant);
                bit += fraction_significant[0];
                fraction_significant[0] = '0';
                exp++;
            }
            string result = int_significant + bit;
            while (result.size() < 113) result += '0';
            return result;
        }
    }
    string result = int_significant + bit;
    while (result[0] == '0') result.erase(0, 1);
    while (result.size() < 113) result += '0';
    if (result.size() >= 113) {
        int temp = result.size() - 112;
        while (temp != 0) {
            result.pop_back();
            temp--;
        }
    }
    
    string expStr = convertInt(to_string(exp));
    
    if (expStr.length() < 15) {
        expStr.insert(expStr.begin(), '0');
    }
    
    result = expStr + result;
    if (negative == true)
        result.insert(result.begin(), '1');
    else result.insert(result.begin(), '0');
    return result;
} //Chưa hoàn thành

string QFloat::BinFloat2Bin(string floatString) {
    int dotPosition;
    bool negative = false;
    
    if (floatString[0] == '-') {
        negative = true;
        floatString.erase(floatString.begin());
    }
    
    if (floatString.find_first_of('.') == string::npos) {
        floatString += ".0";
    }
    
    dotPosition = floatString.find_first_of('.');
    floatString.erase(dotPosition,1);
    exp = 16382 + dotPosition;
    
    string expStr = convertInt(to_string(exp));
    if (expStr.length() < 15) {
        expStr.insert(expStr.begin(), '0');
    }
    
    floatString = expStr + floatString;
    
    while (floatString.size() <= 127)
        floatString.push_back('0');
    
    if (negative == true)
        floatString.insert(floatString.begin(), '1');
    else floatString.insert(floatString.begin(), '0');
    
    return floatString;
} //Chuyển Chuỗi nhị phân nhập vào sang chuỗi nhị phân đã chuẩn hoá

string QFloat::QFloat2Binary() {
    bool negative = false;
    string binary = this->toStr();
    
    if (binary[0] == '1')
        negative = true;
    
    int pos = exp - 16383 + 1;
    
    string significant = binary.substr(16, 127);
    
    significant.insert(significant.begin() + pos, '.');
    
    if (negative == true)
        significant.insert(significant.begin(), '-');
    
    
    return significant;
} //Convert biến QFloat thành binary ở dạng chuỗi

string QFloat::QFloat2Dec() {
    long double temp;
    string saveString;
    string result;
    int dotOfFloatNumber = 0;
    vector<bool> m_data;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 32; j++) {
            if (i == 3 && j > 15) {}
            else {
                m_data.push_back(getBit(data[i], j));
            }
        }
    // đã có mảng bool chứa significant
    return result;
}

string QFloat::toStr() {
    string result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 32; j++)
            result.push_back(getBit(data[i], j) + 48);
    reverse(result.begin(), result.end());
    return result;
} //Test Func -> in chuỗi bit được lưu trong máy tính

int QFloat::changeExponent2Int(string n) {
    int result = 0;
    reverse(n.begin(), n.end());
    for (int i = 0; i < n.length(); i++)
        if (n[i] == '1')
            result += 1 * pow(2,i);
    return result;
} //Chuyển exponent sang kiểu Int

string QFloat::DividedByTwo(string &str) {
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

string QFloat::convertInt(string decStr) {
    string str;
    
    while (decStr != "") {
        str.push_back(((decStr[decStr.size() - 1] - 48) % 2) + 48);
        decStr = DividedByTwo(decStr);
    }
    reverse(str.begin(), str.end());
    
    return str;
} //Hàm chuyển đổi từ hệ 10 sang hệ 2

string QFloat::multiplyAfterDotByTwo(string input) {
    string result;
    int carries = 0;
    int temp;
    int length = input.length();
    int k = input.find_first_of('.');
    
    if (k != string::npos) {
        for (int i = length - 1; i > k; --i) {
            temp = (input[i] - '0') * 2 + carries;
            if (temp >= 10) {
                result.insert(result.begin(), char(temp - 10 + '0'));
                carries = 1;
            } else {
                result.insert(result.begin(), char(temp + '0'));
                carries = 0;
            }
        }
        result.insert(result.begin(), '.');
        
        for (int i = k - 1; i >= 0; --i) {
            temp = (input[i] - '0') * 2 + carries;
            if (temp >= 10) {
                result.insert(result.begin(), char(temp - 10 + '0'));
                carries = 1;
            } else {
                result.insert(result.begin(), char(temp + '0'));
                carries = 0;
            }
        }
    } else {
        for (int i = length - 1; i >= 0; --i) {
            temp = (input[i] - 48) * 2 + carries;
            if (temp >= 10) {
                result.insert(result.begin(), char(temp - 10 + '0'));
                carries = 1;
            } else {
                result.insert(result.begin(), char(temp + '0'));
                carries = 0;
            }
        }
    }
    if (carries == 1) result.insert(result.begin(), '1');
    return result;
} //Nhân chuỗi string cho 2

int QFloat::getBit(uint32_t data, int position) {
    return (data >> position) & 1;
} //Lấy bit tại vị trí position

int QFloat::getBit(int pos) {
    int dataId = pos / 32;
    int bitId = pos % 32;
    return getBit(data[dataId], bitId);
} // Lấy bit dựa vào vị trí, phát triển từ hàm getBit(uint32_t,int)


int main() {
    QFloat a("1100", 2);
    QFloat x;
    string result;
    cout << a.QFloat2Binary() << endl;
}
