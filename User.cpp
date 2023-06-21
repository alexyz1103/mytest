#include "User.h"

void User::print()
{
	std::cout << login << "\t" << password << endl;
}

bool User::operator==(User& user)
{
	if (user.login == this->login && user.password == this->password) {
		return true;
	}
	else {
		return false;
	}
}

bool User::operator!=(User& user)
{
	if (user.login != this->login || user.password != this->password) {
		return true;
	}
	else {
		return false;
	}
}

bool User::getAdmin()
{
	return admin;
}
