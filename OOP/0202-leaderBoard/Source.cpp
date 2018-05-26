// Name: 李聿鎧
// Date: March 13, 2018
// Last Update: March 13, 2018
// Problem statement: C++ Homework "02 - leaderBoard"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

// Intent: 排序成績並輸出前三名
// Pre: arrayOfStrings與anArrayOfIntegers大於0筆資料
// Post: 輸出前三名的名字和成績
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
	//輸出前三名
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

		//排名成績並輸出前三名
		getHighScores(arrayOfStrings, anArrayOfIntegers);
	}
	return 0;
}