//
//  File.hpp
//  QInt
//
//  Created by TT Nguyen on 10/23/18.
//  Copyright � 2018 TT Nguyen. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include "QInt.hpp"
#include "QFloat.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

//int checkString(vector<string> str);
class File{
private:
    int countLine;
    vector<string> data;
    vector<string> p1;
    vector<string> p2;
    vector<string> qint1;
    vector<string> qint2;
    vector<string> ope;
public:
    void readFile(const char *path);
    void writeFile(const char *path);
    int countSpace(string str);
    bool isQFloat(string qfloat);
};

class FileFloat {
private:
    int countLine;
    vector<string> data;
    vector<string> p1;
    vector<string> p2;
    vector<string> qfloat;
public:
    void readFileFloat(const char *path);
    void writeFileFloat(const char *path);
    bool isQFloat(string qfloat);
};
#endif
