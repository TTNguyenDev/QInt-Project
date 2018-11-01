//
//  Interface.cpp
//  QInt
//
//  Created by TT Nguyen on 10/23/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "Interface.hpp"
#include <iostream>

void Interface::helloScreen() {
    cout << "\t\t\t************************************" << endl;
    cout << "\t\t\t*                                  *" << endl;
    cout << "\t\t\t*           QInt Project           *" << endl;
    cout << "\t\t\t*                                  *" << endl;
    cout << "\t\t\t************************************" << endl;
}

void Interface::select_QFloat_QInt() {
    cout << "\t\t\t************************************" << endl;
    cout << "\t\t\t* 1.QInt                           *" << endl;
    cout << "\t\t\t* 2.QFloat                         *" << endl;
    cout << "\t\t\t************************************" << endl;
    
    int choose;
    cout << "-> ";
    cin >> choose;
    
    if (choose == 1) {
        functionalityQInt();
    } else if (choose == 2) {
        functionalityQFloat();
    }
}

void Interface::functionalityQInt() {
    cout << "\t\t\t************************************" << endl;
    cout << "\t\t\t* 1.Calculate(+,-,*,/)             *" << endl;
    cout << "\t\t\t* 2.Convert                        *" << endl;
    cout << "\t\t\t* 3.And Or Xor Not << >> RoR RoL   *" << endl;
    cout << "\t\t\t************************************" << endl;
    
    int choose;
    cout << "-> ";
    cin >> choose;
    
    switch (choose) {
        case 1:
            calculate(1);
            break;
        case 2:
            convert(1);
            break;
        case 3:
            andOrXorNotFunc(1);
            break;
    }
}

void Interface::functionalityQFloat() {
    cout << "\t\t\t************************************" << endl;
    cout << "\t\t\t*  1.Calculate(+,-,*,/)            *" << endl;
    cout << "\t\t\t*  2.Convert                       *" << endl;
    cout << "\t\t\t************************************" << endl;
    
    int choose;
    cout << "-> ";
    cin >> choose;
    
    switch (choose) {
        case 1:
            calculate(2);
            break;
        case 2:
            convert(2);
            break;
    }
    
}

void Interface::calculate(int type) { //1 QInt, 2 QFloat
    int base = selectBaseNumber();
    string number_1 = inputString();
    string number_2 = inputString();
    QInt result;
    string output;
    if (type == 1) {
        QInt a;
        if (base == 1) {
            number_1 = a.Bin2Bin(number_1);
            number_2 = a.Bin2Bin(number_2);
        }
        if (base == 2) {
            number_1 = a.Oct2Bin(number_1);
            number_2 = a.Oct2Bin(number_2);
        }
        if (base == 3)  {
            number_1 = a.Dec2Bin(number_1);
            number_2 = a.Dec2Bin(number_2);
        }
        if (base == 4) {
            number_1 = a.Hex2Bin(number_1);
            number_2 = a.Hex2Bin(number_2);
        }
        
        QInt ele_1(number_1);
        QInt ele_2(number_2);
        selectOperator();
        int operator_c;
        cout << "-> ";
        cin >> operator_c;
        if (operator_c == 1)
            result = ele_1 + ele_2;
        
        if (operator_c == 2)
            result = ele_1 - ele_2;
//        if (operator_c == 3);
//
//        if (operator_c == 4);
        
        cout << "Select result base number: " << endl;
        int bases = selectBaseNumber();
        if (bases == 1) {
            output = result.QInt2Bin();
        }
        if (bases == 3)  {
            output = result.QInt2Dec();
        }
        if (bases == 4) {
           output = result.QInt2Hex();
        }
        cout << "Result: " << output << endl;
        // * /
    } else if (type == 2) {
        
    }
}
    
void Interface::selectAndOrXorNot() {
    cout << "\t\t\t************************************" << endl;
    cout << "\t\t\t*  1.And(&)                        *" << endl;
    cout << "\t\t\t*  2.Or(|)                         *" << endl;
    cout << "\t\t\t*  3.Xor(^)                        *" << endl;
    cout << "\t\t\t*  4.Not(~)                        *" << endl;
    cout << "\t\t\t*  5.Shift Left(<<)                *" << endl;
    cout << "\t\t\t*  6.Shift Right(>>)               *" << endl;
    cout << "\t\t\t*  7.Rotate Left(RoL)              *" << endl;
    cout << "\t\t\t*  8.Rotate Right(RoR)             *" << endl;
    cout << "\t\t\t************************************" << endl;
}

void Interface::andOrXorNotFunc(int type) {
    selectAndOrXorNot();
    int choose;
    cout << "-> ";
    cin >> choose;
    
    
    if (choose > 0 && choose < 4) {
        string number_1 = inputString();
        string number_2 = inputString();
        QInt a(number_1);
        QInt b(number_2);
        QInt result;
        if (choose == 1)
            result = a & b;
        if (choose == 2)
            result = a | b;
        if (choose == 3)
            result = a ^ b;
        cout << result.QInt2Bin() << endl;
    }
    
    else if (choose == 4) {
        string number_1 = inputString();
        QInt a(number_1);
        QInt result;
        result = ~a;
        
        cout << result.QInt2Bin();
    } else if (choose > 4 && choose < 9) {
        string number_1 = inputString();
        int times;
        cout << "Enter time: ";
        cin >> times;
        QInt a(number_1);
        // func >> << ror rol
    }
    
    
}

void Interface::convert(int type) { //1 QInt, 2 QFloat
    cout << "Select base number 1: " << endl;
    int base_1 = selectBaseNumber();
    cout << "Select base number 2: " << endl;
    int  base_2 = selectBaseNumber();
    string number_1 = inputString();
    
    if (type == 1) {
        QInt a;
        if (base_1 == 1)
            number_1 = a.Bin2Bin(number_1);
        if (base_1 == 2)
            number_1 = a.Oct2Bin(number_1);
        if (base_1 == 3)
            number_1 = a.Dec2Bin(number_1);
        if (base_1 == 4)
            number_1 = a.Hex2Bin(number_1);
        
        QInt b(number_1);
        cout << "Result: ";
        if (base_2 == 1)
            cout << b.QInt2Bin();
        if (base_2 == 3)
            cout << b.QInt2Dec();
        if (base_2 == 4)
            cout << b.QInt2Hex();
    } else if (type == 2) {
        
    }
}

int Interface::selectBaseNumber() {
    cout << "\t\t\t**************" << endl;
    cout << "\t\t\t*  1.Bin     *" << endl;
    cout << "\t\t\t*  2.Octa    *" << endl;
    cout << "\t\t\t*  3.Dec     *" << endl;
    cout << "\t\t\t*  4.Hex     *" << endl;
    cout << "\t\t\t**************" << endl;
    
    int choose;
    cout << "-> ";
    cin >> choose;
    switch (choose) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
    }
    return 0;
}

void Interface::selectOperator() {
    cout << "\t\t\t**************" << endl;
    cout << "\t\t\t*  1. a + b  *" << endl;
    cout << "\t\t\t*  2. a - b  *" << endl;
    cout << "\t\t\t*  3. a * b  *" << endl;
    cout << "\t\t\t*  4. a / b  *" << endl;
    cout << "\t\t\t**************" << endl;
}

string Interface::inputString() {
    string number;
    cout << "Enter Number: ";
    cin >> number;
    return number;
}

//int main() {
//    Interface a;
//    a.helloScreen();
//    a.select_QFloat_QInt();
//
//    
//    
//}

