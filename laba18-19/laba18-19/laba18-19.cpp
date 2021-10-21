// laba18-19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdalign>
#include <ctime>
#include <random>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	string file_in, word_in, word_fn;
	ofstream file;
	file.open("test.txt", ios::out | ios::app);

	if (!file)
	{
		cout << "Error - dont possible to open file for whiting data";
		cin.sync(); cin.get(); return 1;
	}

	file << "cat" << endl << "tom" << endl << "mouse" << endl << "Jerry" << endl;

	file.close();
	ifstream file2;
	file2.open("test.txt", ios::in);
	if (!file2)
	{
		cout << "Error - dont possible to open file for whiting data";
		cin.sync(); cin.get(); return 2;
	}

	cout << "Введите слово: ";
	cin >> word_fn;

	while(file2 >> word_in)
		if (word_in == word_fn)
		{
			cout << "Word '" << word_fn << "' find\n";
			system("PAUSE");
			file2.close();
			return 0;
		}
	if (word_in != word_fn)
	{
		cout << "Word '" << word_fn << "' didnt find\n";
		system("PAUSE");
		file2.close();
		return 0;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
