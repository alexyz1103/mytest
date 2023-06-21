#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "User.h"
using namespace std;

void enter();
bool authorization();
void run();
void registration();
list<User> getUsers();

string pathUsers = "users.txt";

int main()
{
    setlocale(LC_ALL, "russian");
    enter();    
}

void enter()
{
    bool flag = true;
    short answer;
    while (flag) {
        system("cls");
        cout << "Система тестирования\n"
            << "Выбирите действие:\n"
            << "1) Авторизироваться\n"
            << "2) Зарегистрироваться\n"
            << "0) Выйти"
            << endl;
        cin >> answer;
        switch (answer)
        {
        case 1: {
            if (authorization()) run();
            break;
        }
        case 2: {
            registration();
            break;
        }
        case 0: {
            flag = false;
            break;
        }
        default:
            cout << "Введена не верная команда" << endl;
            break;
        }
    }
}

bool authorization()
{
    list<User> users = getUsers();
    string login;
    cout << "Логин: ";
    cin >> login;
    string password;
    cout << "Пароль:";
    cin >> password;
    User tempuser(login, password);

    return false;
}

void run()
{
    cout << "run()" << endl;
}

void registration()
{
    cout << "registration()" << endl;
}

list<User> getUsers()
{
    list<User> users;
    ifstream file;
    file.open(pathUsers);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << pathUsers << endl;
    }
    else {
        while (!file.eof()) {
            string str;
            string word;
            vector<string> userwords;
            getline(file, str);
            for (size_t i = 0; i < str.size(); i++)
            {
                if (str[i] == '\t' || str[i] == '\n') {
                    userwords.push_back(word);
                    word = "";
                }
                else {
                    word += str[i];
                }
            }
            userwords.push_back(word);
            User newUser(userwords[0],userwords[1]);
            users.push_back(newUser);
        }
    }
    file.close();
    return users;
}
