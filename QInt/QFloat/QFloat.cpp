//
//  QFloat.cpp
//  QInt
//
//  Created by TT Nguyen on 10/26/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "QFloat.hpp"

QFloat::QFloat() {
    this->data.resize(4);
}

QFloat::QFloat(string binStr) {
    while (binStr.length() != 128)
        binStr = '0' + binStr;
    this->data.resize(4);
    for (int i = 0; i < 128; i++)
        if (binStr[i] == '1')
            this->data[(127-i) / 32] = this->data[(127-i) / 32] | (1 << (31 - (i % 32)));

    float *p = (float*) &data;
}

string QFloat::QFloat2Bin() {
    return "1";
}
