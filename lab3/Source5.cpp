#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

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
		vector<char> Vec;
		while (fileIn.get(s))
		{
			Vec.push_back(s);
			cout << s;
		}
		cout << endl;
		vector<char> newVec;
		newVec.push_back(Vec[0]);

		for (int i = 0; i < Vec.size(); i++)
		{
			int n = 0;
			for (int j = 0; j < newVec.size(); j++)
			{
				if (Vec[i] != newVec[j])
					n++;
				if (n == newVec.size())
				{
					newVec.push_back(Vec[i]);
					break;
				}
			}
		}
		for (int i = 0; i < newVec.size(); i++)
		{
			cout << newVec[i] << " ";
		}
		fileIn.close();

		fileOut.open("newF.txt");
		if (!fileOut.is_open())
			cout << "error";
		else
		{
			for (int i = 0; i < newVec.size(); i++)
			{
				fileOut << newVec[i] << " ";
			}
			fileOut.close();
		}
	}

	return 0;
}