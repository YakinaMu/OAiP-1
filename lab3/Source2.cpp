#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void iswap(char& n1, char& n2);

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream fileIn;
	ofstream fileOut;

	fileIn.open("F.txt");
	if (!fileIn.is_open())
		cout << "error";
	else
	{
		char s;
		vector<char> v;
		while (fileIn.get(s))
		{
			if (s != ' ')
				v.push_back(s);
			cout << s;
		}

		//сортировка

		int sh = 0;
		bool b;
		do
		{
			b = false;
			for (int i = 0; i < v.size(); i++)
			{
				if (i * 2 + 2 + sh < v.size())
				{
					if ((v[i + sh] > v[i * 2 + 1 + sh]) || (v[i + sh] > v[i * 2 + 2 + sh]))
					{
						if (v[i * 2 + 1 + sh] < v[i * 2 + 2 + sh])
						{
							iswap(v[i + sh], v[i * 2 + 1 + sh]);
							b = true;
						}
						else if (v[i * 2 + 2 + sh] < v[i * 2 + 1 + sh])
						{
							iswap(v[i + sh], v[i * 2 + 2 + sh]);
							b = true;
						}
					}

					if (v[i * 2 + 2 + sh] < v[i * 2 + 1 + sh])
					{
						iswap(v[i * 2 + 1 + sh], v[i * 2 + 2 + sh]);
						b = true;
					}
				}
				else if (i * 2 + 1 + sh < v.size())
				{
					if (v[i + sh] > v[i * 2 + 1 + sh])
					{
						iswap(v[i + sh], v[i * 2 + 1 + sh]);
						b = true;
					}
				}
			}
			if (!b)
				++sh;
		} while (sh + 2 < v.size());

		cout << "\nДанные после сортировки ";
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';

		//запись данных в файл
		fileOut.open("F.txt", ofstream::app);
		fileOut << endl;
		if (!fileOut.is_open())
			cout << "error";
		else
			fileOut << "Данные после сортировки ";
		for (int i = 0; i < v.size(); i++)
			fileOut << v[i] << " ";
		fileOut.close();
	}
	fileIn.close();
	return 0;
}
void iswap(char& n1, char& n2)
{
	char temp = n1;
	n1 = n2;
	n2 = temp;
}
