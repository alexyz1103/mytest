#pragma once
#include <map>
#include <iostream>
using namespace std;
class Question
{
public:
	Question(string text, map<string, bool> answer) : 
		text{ text }, answer{answer} {	}
	Question() {
		text = "none text";
	}
	void setText(string text);
	void addAnswer(string tanswer, bool banswer);
	void print();
private:
	string text;
	map<string, bool> answer;
};

