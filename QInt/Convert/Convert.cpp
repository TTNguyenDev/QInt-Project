#include "Convert.h"


//Convert input to Binary
string Convert::Dec2Bin(string decStr) {
    while (decStr != "") {
        data.push_back(((decStr[decStr.size() - 1] - 48) % 2) + 48);
        decStr = DividedByTwo(decStr);
    }
    reverse(data.begin(), data.end());
    return data;
}

string Convert::Bin2Bin(string str) {
    data = str;
    return data;
}

string Convert::Oct2Bin(string str) {
    for (int i = 0; i < str.size(); i++)
        switch (str[i]) {
            case '0':
                data += "000";
                break;
            case '1':
                data += "001";
                break;
            case '2':
                data += "010";
                break;
            case '3':
                data += "011";
                break;
            case '4':
                data += "100";
                break;
            case '5':
                data += "101";
                break;
            case '6':
                data += "110";
                break;
            case '7':
                data += "111";
                break;
        }
    return data;
}

string Convert::Hex2Bin(string str) {
    for (int i = 0; i < str.size() ; i++)
        switch (str[i]) {
            case '0':
                data += "0000";
                break;
            case '1':
                data += "0001";
                break;
            case '2':
                data += "0010";
                break;
            case '3':
                data += "0011";
                break;
            case '4':
                data += "0100";
                break;
            case '5':
                data += "0101";
                break;
            case '6':
                data += "0110";
                break;
            case '7':
                data += "0111";
                break;
            case '8':
                data += "1000";
                break;
            case '9':
                data += "1001";
                break;
            case 'A':
                data += "1010";
                break;
            case 'B':
                data += "1011";
                break;
            case 'C':
                data += "1100";
                break;
            case 'D':
                data += "1101";
                break;
            case 'E':
                data += "1110";
                break;
            case 'F':
                data += "1111";
                break;
        }
    return data;
}

//Support Function
bool Convert::checkNagative(string &str) {
    if (str[0] == '-') {
        str.erase(str.begin());
        
        //chuyen sang dang bu 2 + 1
        return true;
    }
    return false;
}


string Convert::DividedByTwo(string &str) {
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


