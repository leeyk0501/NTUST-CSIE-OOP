// Name: 李聿鎧
// Date: March 17, 2018
// Last Update: March 17, 2018
// Problem statement: C++ Homework "0302 - TextBasedHistogram"
#include<iostream>
#include<fstream>
#include<map> //use at map
#include<string>
#define SIZE 5

using namespace std;

// Intent: 輸出grades.Output
// Pre: outputData至少要有一筆資料
// Post: 將資料逐筆輸出至grades.Output
void outputGrades(map<int, int> outputData)
{
	fstream ostream;
	ostream.open("grades.Output", fstream::out);

	for (pair<int, int> i : outputData)
	{
		ostream << i.second << " grade(s) of " << i.first << endl;
	}
	ostream.close();
	cout << "grades.Output" << endl;
}
int main()
{
	int n;
	string fileName;
	ifstream inputStream;
	ofstream outputStream;

	map<int, int> inputData;
	while (cin >> fileName)
	{
		//開啟檔案
		inputStream.open(fileName);

		//inputData初始化，新增0至SIZE的key
		inputData.clear();
		for (int i = 0; i <= SIZE; i++)
		{
			inputData.insert(make_pair(i, 0));
		}

		//統計成績
		while (inputStream >> n)
		{
			inputData[n]++;
		}

		//關閉檔案
		inputStream.close();

		//將統計結果輸出至grades.Output
		outputGrades(inputData);
	}
	return 0;
}