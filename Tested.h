#pragma once
#include "User.h"
#include <map>
class Tested : public User
{
private:
	string lastname;
	string name;
	string secondname;
	string adress;
	string tel;
	map<string, int> rezult;

	int Idgenerator();

public:
	Tested(int id, string login, string password, string lastname, 
		string name, string secondname, string adress,
		string tel, map<string, int> rezult): User(id,login,password) {
		this->id = id;
		this->lastname = lastname;
		this->name = name;
		this->secondname = secondname;
		this->adress = adress;
		this->tel = tel;
		this->rezult = rezult;
	}

	void print();

};

