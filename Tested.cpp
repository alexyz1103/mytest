#include "Tested.h"
#include <fstream>

int Tested::Idgenerator()
{
    ifstream infile;
    infile.open("id.txt");
    string getid;
    if (!infile.is_open()) {
        cout << "Ошибка открытия файла для чтения id.txt" << endl;
    }
    else {
        getline(infile, getid);
    }
    infile.close();
    ofstream outfile;
    outfile.open("id.txt");
    if (!infile.is_open()) {
        cout << "Ошибка открытия файла для записи id.txt" << endl;
    }
    else {
        outfile << stoi(getid) + 1;
    }
    outfile.close();
    return stoi(getid);
}

void Tested::print()
{
    cout << lastname << " " << name << " " << secondname << endl
        << 
}
