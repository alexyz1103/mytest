#pragma once
#include <string>
#include <iostream>

using namespace std;

class User
{
protected:
	int id;
	string login;
	string password;
	bool admin;
public:
	User(int id, string login, string password, bool admin = false) : 
		id{ id }, login{ login }, password{ password }, admin{ admin }{}
	User(): User(int(),string(),string()){}
	
	User(const User &user){
		this->id = user.id;
		this->login = user.login;
		this->password = user.password;
		this->admin = user.admin;
	}

	void print();
	bool operator==(User& user);
	bool operator!=(User& user);
	bool getAdmin();
	User operator=(const User& user);
};

