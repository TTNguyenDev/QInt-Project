//
//  Interface.cpp
//  QInt
//
//  Created by TT Nguyen on 10/23/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "Interface.hpp"
#include <fstream>

void convertBaseNumber_FILE(string input, string output) {
    string mainLink = "/Users/trietnguyen/Desktop";
    ifstream inFile(mainLink + input);
    
    
}


int interface::selectBaseNumber() {
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

void interface::selectOperator() {
    cout << "\t\t\t**************" << endl;
    cout << "\t\t\t*  1. a + b  *" << endl;
    cout << "\t\t\t*  1. a - b  *" << endl;
    cout << "\t\t\t*  1. a * b  *" << endl;
    cout << "\t\t\t*  1. a / b  *" << endl;
    cout << "\t\t\t**************" << endl;
    
    int choose;
    cout << "-> ";
    cin >> choose;
    switch (choose) {
        case 1:
            int base = selectBaseNumber();
            //switch case for every base number
            string a;
            string b;
            cin.ignore();
            cout << "Number 1: ";
            getline(cin, a);
           
            cout << "Number 2: ";
            getline(cin, b);
            //+ operator ......(a, b);
            break;
            
    }
}

int interface::selection() {
    cout << "\t\t\t************************************" << endl;
    cout << "\t\t\t* 1.Calculate(+,-,*,/)             *" << endl;
    cout << "\t\t\t* 2.Convert                        *" << endl;
    cout << "\t\t\t* 3.And Or Xor Not << >> RoR RoL  *" << endl;
    cout << "\t\t\t************************************" << endl;
    
    int choose;
    cout << "-> ";
    cin >> choose;
    switch (choose) {
        case 1:
            selectOperator();
            break;
        case 2:
            QInt a("h");
            cout << "Base of first number: " << endl;
            int first = selectBaseNumber();
            cout << "Base of second number: " << endl;
            int second = selectBaseNumber();
            cin.ignore();
            string data;
            cout << "Enter String: ";
            getline(cin, data);
            cout << "Result: " << a.BaseNumberConvertation(first, second, data);
            break;
            }
    return 0;
}



string interface::inputString() {
    string number;
    cout << "Enter Number: " << endl;
    getline(cin, number);
    return number;
}

int main(int argc, const char * argv[]) {
    
    if (argc == 3) {
        
    }
    interface a;
    a.selection();
    
    
    
    
    
}
