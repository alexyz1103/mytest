#pragma once
#include <string>
#include <iostream>

using namespace std;

class User
{
protected:
	string login;
	string password;
	bool admin;
public:
	User(string login, string password, bool admin) : login{ login }, password{ password }, admin{ admin }{}
	User(): User(string(),string(),false){}

	virtual void print();
	bool operator==(User& user);
	bool operator!=(User& user);
	bool getAdmin();
};

