#include "Question.h"

void Question::setText(string text)
{
	this->text = text;
}

void Question::addAnswer(string tanswer, bool banswer)
{
	answer.emplace(tanswer, banswer);
}

void Question::print()
{
	cout << "Текст вопроса: " << text << endl;
	int counter = 1;
	for (auto item : answer) {
		cout << counter++ << ")" << item.first << endl;
	}
}
