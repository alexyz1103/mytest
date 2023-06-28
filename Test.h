#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Question.h"

using namespace std;

class Test
{
public:
	bool readfile(string chapter, string name);
	void print();
private:
	string chapter;
	string name;
	list<Question> questions;
};

