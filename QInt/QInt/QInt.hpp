#ifndef QInt_hpp
#define QInt_hpp
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class QInt {
private:
    vector<uint32_t> data;
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
    string QInt2Dec(); //Chưa làm :))

    //Operator
    QInt operator &(const QInt&);
    QInt operator |(const QInt&);
    QInt operator ^(const QInt&);
    QInt& operator ~();
    QInt operator >>(const int);
    QInt operator <<(const int);
    QInt operator ==(const int); //spam operator :))
    QInt ShiftRight();
    QInt& RoL(const int);
    QInt& RoR(const int);
    
    //+ - * /
    QInt operator +(QInt qint);
    
    
    //Support Function
    string DividedByTwo(string&);
    int getBit(uint32_t,int);
    int setBit(uint32_t&,int);

};

#endif
