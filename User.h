#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
protected:
	string login;
	string password;
public:
	User(string login, string password): login{login}, password{password}{}
	//User(): User(string(),string()){}

	void print();
};

