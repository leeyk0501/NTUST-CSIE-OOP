// Name: ßı¶÷ÒZ
// Date: March 13, 2018
// Last Update: March 13, 2018
// Problem statement: C++ Homework "02 - SquareCode"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

int textWidth(string data)
{
	double height = data.size(), width = 0;
	while (height > width)
	{
		height = data.size();
		width++;
		height /= width;
	}
	return width;
}
int main()
{
	string data;
	while (cin >> data)
	{
		int size = data.size();
		int width = textWidth(data);
		int index;
		for (int i = 0; i < width; i++)
		{
			index = i;;
			while (index < size)
			{
				cout << data[index];
				index += width;
			}
			cout << endl;
		}

	}
	return 0;
}