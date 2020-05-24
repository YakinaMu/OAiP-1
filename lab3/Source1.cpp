#include <iostream>
using namespace std;

void F1(double);
void F2(double);
void F3(double);
void F4(double);

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "1.Посчитать сумму чисел\n";
	cout << "2.Посчитать разность чисел\n";
	cout << "3.Посчитать произведение чисел\n";
	cout << "4.Посчитать частное чисел\n";
	cout << "Какую действие выбрать?\n ";
	int i;
	cin >> i;
	i--;
	void(*functions[4])(double) = { F1,F2,F3,F4 };
	(*functions[i])(i);
	return 0;
}

void F1(double)
{
	cout << "Введите два числа " << endl;
	double a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a + b << endl;
	system("pause");
}

void F2(double)
{
	cout << "Введите два числа " << endl;
	double a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a - b << endl;
	system("pause");
}

void F3(double)
{
	cout << "Введите два числа " << endl;
	double a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a * b << endl;
	system("pause");
}

void F4(double)
{
	cout << "Введите два числа " << endl;
	double a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a / b << endl;
	system("pause");
}