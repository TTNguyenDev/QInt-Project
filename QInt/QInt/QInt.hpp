#ifndef QInt_hpp
#define QInt_hpp
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class QInt {
private:
    vector<long> data;
	string str;
public:
    //Constructor
    QInt();
    QInt(string binStr);
    
    
	//Convert input to binary string
	string Dec2Bin(string);
	string Hex2Bin(string);
	string Oct2Bin(string);
	string Bin2Bin(string);
    
    //Convert QInt to 2, 8, 10, 16 string
    string QInt2Hex();
    string QInt2Bin();
    string QInt2Dec(QInt q);

	string DividedByTwo(string&);
    string BaseNumberConvertation(int, int, string);
    string toBinary();
	string Bin2Dec();
    string getData() { return str; };
    
    //Operator
    QInt operator &(const QInt&);
    QInt operator |(const QInt&);
    QInt operator ^(const QInt&);
    QInt& operator ~();
    
    
    
//    QInt& operator =(const QInt&);
};

#endif
