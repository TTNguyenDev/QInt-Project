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

using namespace std;

class QFloat {
private:
    vector<long> data;
public:
    //Convert input
    //chuyen float hệ 10 sang float hệ 2
    QFloat();
    QFloat(string);
    string QFloat2Bin();

};

#endif /* QFloat_hpp */
