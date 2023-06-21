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
	User(string login, string password, bool admin = false) : 
		login{ login }, password{ password }, admin{ admin }{}
	User(): User(string(),string()){}
	
	/*User(User &user){
		this->login = user.admin;
		this->password = user.password;
		this->admin = user.admin;
	}*/

	void print();
	bool operator==(User& user);
	bool operator!=(User& user);
	bool getAdmin();
};

