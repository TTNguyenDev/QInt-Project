#ifndef Convert_h
#define Convert_h

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>


using namespace std;

class Convert {
private:
    string data;
public:
    
    string getData() { return data; };
    string Dec2Bin(string);
    string Hex2Bin(string);
    string Oct2Bin(string);
    string Bin2Bin(string);
    
    
    
    bool checkNagative(string&);
    string DividedByTwo(string&);
};





#endif
