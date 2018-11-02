//
//  QFloat.hpp
//  QInt
//
//  Created by TT Nguyen on 10/26/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#ifndef QFloat_hpp
#define QFloat_hpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class QFloat {
private:
    vector<uint32_t> data;
    int exp;
    
public:
    QFloat();
    QFloat(string,int);
    
    string DecFloat2Bin(string);
    string BinFloat2Bin(string);
    string QFloat2Binary();
    string toStr();
    
//    string QFloat2Dec();
    //support function
    int changeExponent2Int(string n);
    int getBit(uint32_t,int);
    string convertInt(string);
    string DividedByTwo(string&);
    string multiplyAfterDotByTwo(string);
};
    
#endif /* QFloat_hpp */
