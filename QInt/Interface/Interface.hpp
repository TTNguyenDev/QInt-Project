//
//  Interface.hpp
//  QInt
//
//  Created by TT Nguyen on 10/23/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include "QInt.hpp"
#include "QFloat.hpp"

using namespace std;

class Interface {
public:
    void helloScreen();
    void select_QFloat_QInt();
    
    void functionalityQInt();
    void functionalityQFloat();
    int selectBaseNumber();
    int selectBaseNumberForQFloat();
    void convert(int);
    void andOrXorNotFunc(int);
    void selectAndOrXorNot();
    void calculate(int);
    void selectOperator();
    string inputString();
};
#endif /* Interface_hpp */
