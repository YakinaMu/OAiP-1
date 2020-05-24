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
		string s;
		vector<string> Vec;
		while (!fileIn.eof())
		{
			s = "";
			fileIn >> s;
			Vec.push_back(s);
			// cout << s <<endl;
		}
		cout << Vec.size() << endl;

		fileOut.open("newF.txt");
		if (!fileOut.is_open())
			cout << "error";
		else
		{
			int n = 0;
			for (int i = 0; i < Vec.size(); i++)
			{
				n += (Vec[i].size() + 1);
				if (n >= 25)
				{
					n = 0;
					n += (Vec[i].size() + 1);
					//cout << endl;
					//cout<< Vec[i] << " ";
					fileOut << endl;
					fileOut << Vec[i] << " ";
				}
				else
				{
					fileOut << Vec[i] << " ";
					//cout << Vec[i] << " ";
				}
			}
		}
	}

	return 0;
}