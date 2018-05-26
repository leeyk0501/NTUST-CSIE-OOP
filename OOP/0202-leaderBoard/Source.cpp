// Name: �����Z
// Date: March 13, 2018
// Last Update: March 13, 2018
// Problem statement: C++ Homework "02 - leaderBoard"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

// Intent: �ƧǦ��Z�ÿ�X�e�T�W
// Pre: arrayOfStrings�PanArrayOfIntegers�j��0�����
// Post: ��X�e�T�W���W�r�M���Z
void getHighScores(vector<string> arrayOfStrings, vector<int> anArrayOfIntegers) 
{
	int size = anArrayOfIntegers.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (anArrayOfIntegers[i] < anArrayOfIntegers[j])
			{
				swap(arrayOfStrings[i], arrayOfStrings[j]);
				swap(anArrayOfIntegers[i], anArrayOfIntegers[j]);
			}
		}
	}
	//��X�e�T�W
	for (int i = 0; i < 3; i++)
	{
		cout << arrayOfStrings[i] << endl << anArrayOfIntegers[i] << endl;
	}
}
int main()
{
	int score;
	string name, fileName;
	ifstream inputStream;
	vector<string> arrayOfStrings;
	vector<int> anArrayOfIntegers;

	while (cin >> fileName)
	{
		arrayOfStrings.clear();
		anArrayOfIntegers.clear();
		inputStream.open(fileName);

		while (inputStream >> name)
		{
			arrayOfStrings.push_back(name);
			inputStream >> score;
			anArrayOfIntegers.push_back(score);
		}
		inputStream.close();

		//�ƦW���Z�ÿ�X�e�T�W
		getHighScores(arrayOfStrings, anArrayOfIntegers);
	}
	return 0;
}