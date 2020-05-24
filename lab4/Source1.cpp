#include <iostream>
using namespace std;

void size1(int);
void size2(int);
void size3(int);
void size4(int);
void size5(int);

int main()

{
	setlocale(LC_ALL, "ru");

	void(*P[5])(int) = { size1, size2, size3, size4, size5 };
	cout << "1.type size int\n";
	cout << "2.type size float\n";
	cout << "3.type size double\n";
	cout << "4.type size char\n";
	cout << "5.type size bool\n";
	cout << " What type of size do you want to know?\n ";
	int my_choose;
	cin >> my_choose;
	my_choose--;
	(*P[my_choose])(my_choose);
	return 0;
}

void size1(int)
{
	int a = 5;
	cout << sizeof(a);
}

void size2(int)
{
	float a = 1.2;
	cout << sizeof(a);
}

void size3(int)
{
	double a = 1.22;
	cout << sizeof(a);
}

void size4(int)
{
	char a = 'a';
	cout << sizeof(a);
}

void size5(int)
{
	bool a = true;
	cout << sizeof(a);
}