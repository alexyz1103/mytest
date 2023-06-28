//файл для примера можно удалить
#include <iostream>
#include "Test.h"
#include "Question.h"

using namespace std;
//пример использования файла с тестами
int newmain()
{
    setlocale(LC_ALL, "russian");
    Test test;
    test.readfile("Раздел 1", "Тест 2");
    test.print();
    return 0;
}
