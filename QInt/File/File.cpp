//
//  File.cpp
//  QInt
//
//  Created by TT Nguyen on 10/30/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "File.hpp"

int QINT_FILE::getType(string type) {
    int numOfSpace = 0;
    for (int i = 0; i < type.size(); i++)
        if (type[i] == ' ') numOfSpace++;
    if (numOfSpace == 2)
        return 1;
    else if (numOfSpace == 3)
        return 2;
    return numOfSpace;
}

void QINT_FILE::khongbietdattengi(string path) {
    ifstream input(path);
    
    while (!input.eof()) {
        
    }
}
