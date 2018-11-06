
#include "File.hpp"


void File::readFile(const char *path) {
    ifstream file;
    file.open(path);
    string line;
    countLine = 0;
    vector<size_t> first_pos;
    vector<size_t> second_pos;
    vector<size_t> third_pos;
    
    if (file.is_open())
    {
        while (!file.eof()) {
            getline(file, line,'\n');
            data.push_back(line);
            countLine++;
        }
        
        for (int k = 0; k < countLine; k++)
        {
            if (countSpace(data[k]) == 2)
            {
                first_pos.push_back(data[k].find(' ', 0));
                second_pos.push_back(data[k].find(' ', first_pos[k]+1));
                third_pos.push_back(0);
                p1.push_back( data[k].substr(0, data[k].find(' ')));
                p2.push_back( data[k].substr(first_pos[k]+1,second_pos[k]-first_pos[k]-1));
                qint1.push_back(data[k].substr(second_pos[k]+1, string::npos));
                ope.push_back("0");
                qint2.push_back("0");
            }
            if (countSpace(data[k]) == 3)
            {
                first_pos.push_back(data[k].find(' ', 0));
                second_pos.push_back(data[k].find(' ', first_pos[k] + 1));
                third_pos.push_back( data[k].find(' ', second_pos[k] + 1));
                p1.push_back(data[k].substr(0, data[k].find(' ')));
                p2.push_back("0");
                qint1.push_back(data[k].substr(first_pos[k]+1, second_pos[k]-first_pos[k]-1));
                ope.push_back(data[k].substr(second_pos[k]+1, third_pos[k]-second_pos[k]-1));
                qint2.push_back(data[k].substr(third_pos[k]+1, string::npos));
            }
        }
        file.close();
    }
}

int File::countSpace(string str) {
    int k = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] == ' '))
        {
            k++;
        }
    }
    if (k == 2)
        return 2;
    if (k == 3)
        return 3;
    return 0;
}

void File::writeFile(const char*path) {
    ofstream file;
    file.open(path);
    for (int i = 0; i < countLine; i++)
    {
        if (countSpace(data[i]) == 2)
        {
            /*if(isQFloat(qint1[i])==1)
            {
                if (p1[i] == "2")
                {
                    if (p2[i] == "10")
                    {
                        QFloat a(qint1[i], 2);
                        file << a.QFloat2Dec() << endl;
                    }
                }
                if (p1[i] == "10")
                {
                    if (p2[i] == "2")
                    {
                        QFloat temp(qint1[i], 10);
                        file << temp.QFloat2Binary() << endl;
                    }
                }

            }*/
            if(isQFloat(qint1[i])==0)
            {
                if (p1[i] == "2")
                {
                    if (p2[i] == "10")
                    {
                        QInt temp1;
                        qint1[i] = temp1.Bin2Bin(qint1[i]);
                        QInt temp(qint1[i]);
                        file << temp.QInt2Dec() << endl;
                    }
                    if (p2[i] == "16")
                    {
                        QInt temp1;
                        qint1[i] = temp1.Bin2Bin(qint1[i]);
                        QInt temp(qint1[i]);
                        file << temp.QInt2Hex() << endl;
                    }
                }
                if (p1[i] == "10")
                {
                    if (p2[i] == "2")
                    {
                        QInt temp1;
                        qint1[i]=temp1.Dec2Bin(qint1[i]);
                        QInt temp(qint1[i]);
                        file << temp.QInt2Bin() << endl;
                    }
                    if (p2[i] == "16")
                    {
                        QInt temp1;
                        qint1[i] = temp1.Dec2Bin(qint1[i]);
                        QInt temp(qint1[i]);
                        file << temp.QInt2Hex() << "\n";
                    }
                }
                if (p1[i] == "16")
                {
                    if (p2[i] == "2")
                    {
                        QInt temp1;
                        qint1[i] = temp1.Hex2Bin(qint1[i]);
                        QInt temp(qint1[i]);
                        file << temp.QInt2Bin() << "\n";
                    }
                    if (p2[i] == "10")
                    {
                        QInt temp1;
                        qint1[i] = temp1.Hex2Bin(qint1[i]);
                        QInt temp(qint1[i]);
                        file << temp.QInt2Dec() << "\n";
                    }
                }
            }
            
        }
        if (countSpace(data[i]) == 3)
        {
            if (ope[i] == "+")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Bin2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) + QInt(qint2[i]);
                    file << a.QInt2Bin()<<"\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Dec2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) + QInt(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Hex2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) + QInt(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "-")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Bin2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) - QInt(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Dec2Bin(qint2[i]);
                    
                    QInt a = QInt(qint1[i]) - QInt(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Hex2Bin(qint2[i]);
                    
                    QInt a = QInt(qint1[i]) - QInt(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "*")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Bin2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) * QInt(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Dec2Bin(qint2[i]);
                    
                    QInt a = QInt(qint1[i]) * QInt(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Hex2Bin(qint2[i]);
                    
                    QInt a = QInt(qint1[i]) * QInt(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "/")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Bin2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) / QInt(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Dec2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) / QInt(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Hex2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) / QInt(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "|")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Bin2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) | QInt(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Dec2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) | QInt(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Hex2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) | QInt(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "&")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Bin2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) & QInt(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Dec2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) & QInt(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Hex2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) & QInt(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "^")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Bin2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) ^ QInt(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Dec2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) ^ QInt(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt temp2;
                    qint2[i] = temp2.Hex2Bin(qint2[i]);
                    QInt a = QInt(qint1[i]) ^ QInt(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "<<")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]) << stoi(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]) << stoi(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]) << stoi(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == ">>")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]) >> stoi(qint2[i]);
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]) >> stoi(qint2[i]);
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]) >> stoi(qint2[i]);
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "rol")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]).RoL(stoi(qint2[i]));
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]).RoL(stoi(qint2[i]));
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]).RoL(stoi(qint2[i]));
                    file << a.QInt2Hex() << "\n";
                }
            }
            if (ope[i] == "ror")
            {
                if (p1[i] == "2") {
                    QInt temp1;
                    qint1[i] = temp1.Bin2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]).RoR(stoi(qint2[i]));
                    file << a.QInt2Bin() << "\n";
                }
                if (p1[i] == "10") {
                    QInt temp1;
                    qint1[i] = temp1.Dec2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]).RoR(stoi(qint2[i]));
                    file << a.QInt2Dec() << "\n";
                }
                if (p1[i] == "16") {
                    QInt temp1;
                    qint1[i] = temp1.Hex2Bin(qint1[i]);
                    QInt a = QInt(qint1[i]).RoR( stoi(qint2[i]));
                    file << a.QInt2Hex() << "\n";
                }
            }
            
        }
    }
    file.close();
}

void FileFloat::readFileFloat(const char *path) {
    ifstream file;
    file.open(path);
    string line;
    countLine = 0;
    vector<size_t> first_pos;
    vector<size_t> second_pos;
    
    if (file.is_open())
    {
        while (!file.eof()) {
            getline(file, line, '\n');
            data.push_back(line);
            countLine++;
        }
        
        for (int k = 0; k < countLine; k++)
        {
            first_pos.push_back(data[k].find(' ', 0));
            second_pos.push_back(data[k].find(' ', first_pos[k] + 1));
            p1.push_back(data[k].substr(0, data[k].find(' ')));
            p2.push_back(data[k].substr(first_pos[k] + 1, second_pos[k] - first_pos[k] - 1));
            qfloat.push_back(data[k].substr(second_pos[k] + 1, string::npos));
        }
        file.close();
    }
}

void FileFloat::writeFileFloat(const char*path) {
    ofstream file;
    file.open(path);
    for (int i = 0; i < countLine; i++)
    {
        if (p1[i] == "2")
        {
            if (p2[i] == "10")
            {
                QFloat a(qfloat[i], 2);
                file << a.QFloat2Dec() << endl;
            }
        }
        if (p1[i] == "10")
        {
            if (p2[i] == "2")
            {
                QFloat temp(qfloat[i], 10);
                file << temp.QFloat2Binary() << endl;
            }
        }
    }
}

bool File::isQFloat(string qfloat) {
    int check = 0;
    for (int i = 0; i < qfloat.size(); i++)
    {
        if (qfloat[i] == '.')
            check++;
    }
    if (check > 0)
        return true;
    else if (check == 0)
        return false;
    return false;
}

bool FileFloat::isQFloat(string qfloat) {
    int check = 0;
    for (int i = 0; i < qfloat.size(); i++)
    {
        if (qfloat[i] == '.')
            check++;
    }
    if (check > 0)
        return true;
    else if (check == 0)
        return false;
    return false;
}

