#include "Test.h"

bool Test::readfile(string find_chapter, string find_name)
{
    chapter = find_chapter;
    name = find_name;
    ifstream file;
    file.open("questions.txt");
    if (!file.is_open()) {
        cout << "Ошибка чтения файла " 
            << "questions.txt" << endl;
        return false;
    }
    else {
        while (!file.eof())
        {
            string str;
            getline(file, str);
            if (str != find_chapter) { 
                while (str != "_") {
                    getline(file, str);
                    if (file.eof()) {
                        break;
                    }
                }
                continue; }
            getline(file, str);
            if (str != find_name) {
                while (str != "_") {
                    getline(file, str);
                    if (file.eof()) {
                        break;
                    }
                }
                continue;
            }
            Question temp;
            getline(file, str);
            temp.setText(str);
            string answer;
            bool tf;
            
            do {
                getline(file, str);
                if (str == "_" || file.eof()) { break; }
                const string separators{ "\t" };
                answer = str.substr(0, str.find_first_of(separators));
                if (str.substr(str.find_first_of(separators) + 1) == "1") {
                    tf = true;
                }
                else {
                    tf = false;
                }
                temp.addAnswer(answer, tf);
                //getline(file, str);
            } while (str != "_");
            this->questions.push_back(temp);
        }
    }
    file.close();
    return true;
}

void Test::print()
{
    cout << "Название раздела: " << chapter
        << "\t Название теста: " << name << endl;
    for (auto item : questions)
    {
        item.print();
    }
}
