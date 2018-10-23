#ifndef QInt_hpp
#define QInt_hpp
#include "Convert.h"
#include <math.h>

class QInt {
private:
    bitset<128> data;
public:
    QInt(string binStr); //Chuyển chuỗi string về dạng binary (bitset)
    string BaseNumberConvertation(int, int, string);
    string toBinary();
    string Bin2Dec();
    
};

#endif
