#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "User.h"
#include "Admin.h"

using namespace std;

void enter();
User authorization();
void checkadmin(User& user);
void registration();
list<User> getUsers();
void runAdmin(User& user);
//void runTester(User& user);
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
            User nulluser;
            User tempUser = authorization();;
            if (tempUser != nulluser) {
                checkadmin(tempUser);
            }            
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

User authorization()
{
    list<User> users = getUsers();
    string login;
    cout << "Логин: ";
    cin >> login;
    string password;
    cout << "Пароль:";
    cin >> password;
    User tempuser(0,login, password);
    for (auto item : users) {
        if (tempuser == item) {
            return tempuser;
        }
    }
    User nulluser;
    return nulluser;
}

void checkadmin(User& user)
{
    list<User> users = getUsers();
    for (auto item: users)
    {
        if (item == user) {
            if (item.getAdmin()) {
                runAdmin(item);
            }
            else {
                //runTester(item);
            }
        }
    }
}

void registration()
{
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
            bool admin = false;
            if (userwords[3] == "1") {
                admin = true;
            }
            User newUser(stoi(userwords[0]),userwords[1], userwords[2],admin);
            users.push_back(newUser);
        }
    }
    file.close();
    return users;
}

void runAdmin(User& user)
{
    cout << "Админка" << endl;
    system("pause");

}
