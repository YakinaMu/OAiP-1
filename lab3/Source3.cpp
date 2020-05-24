#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	ifstream fileIn;
	fileIn.open("F.txt");
	string str;
	vector<string>Vec;

	//считывание файла
	while (!fileIn.eof())
	{
		str = "";
		getline(fileIn, str);
		Vec.push_back(str);
		cout << str << endl;
	}
	cout << "Количество строк: " << Vec.size() << endl;
	fileIn.close();

	int k;
	cout << "Какую строку удалить: ";
	cin >> k;
	if (k > Vec.size() || k == 0)
		cout << "Недостаточное кол-во строк" << endl;
	else
	{
		k--;
		Vec.erase(Vec.begin() + k);
	}
	ofstream fileOut;
	fileOut.open("F.txt");
	for (int i = 0; i < Vec.size(); i++)
		fileOut << Vec[i] << endl;
	fileOut.close();

	return 0;
}