//
//  QInt.cpp
//  QInt
//
//  Created by TT Nguyen on 10/20/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "QInt.hpp"

string QInt::BaseNumberConvertation(int first, int second, string data) {
    Convert in;
    
    switch (first) {
        case 1:
            in.Bin2Bin(data);
            break;
        case 2:
            in.Oct2Bin(data);
            break;
        case 3:
            in.Dec2Bin(data);
            break;
        case 4:
            in.Hex2Bin(data);
            break;
    }
    
    QInt output(in.getData());
    
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


QInt::QInt(string binStr) {
    while (binStr.length() != 128) {
        binStr = '0' + binStr;
    }
    for (int i = 0; i < 128; ++i) {
        data[i] = (binStr[i] - '0');
    }
}

string QInt::toBinary() {
    string binary = data.to_string();
    reverse(binary.begin(), binary.end());
    return binary;
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




