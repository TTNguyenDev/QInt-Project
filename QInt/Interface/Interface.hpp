//
//  Interface.hpp
//  QInt
//
//  Created by TT Nguyen on 10/23/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
#include "QInt.hpp"

using namespace std;

class interface {
public:
    int selection();
    int selectBaseNumber();
    void selectOperator();
    string inputString();
    
    
};
#endif /* Interface_hpp */
