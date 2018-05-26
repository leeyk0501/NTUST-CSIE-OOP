// Name: 李聿鎧
// Date: March 17, 2018
// Last Update: March 17, 2018
// Problem statement: C++ Homework "0301 - occurrencCounting"
#include<iostream>
#include<fstream>
#include<map> //use at map
#include<functional> //use at std::greater
#include<string>

using namespace std;

// Intent: 輸出output.txt
// Pre: outputData裡至少要有一筆資料
// Post: 將資料逐筆輸出至output.txt
void outputFile(map<int, int, std::greater<int>> outputData)
{
	fstream ostream;
	ostream.open("output.txt", fstream::out);

	ostream << "N\tCount" << endl;
	for (pair<int,int> i : outputData)
	{
		ostream << i.first << "\t" << i.second << endl;
	}
	ostream.close();
	cout << "output.txt" << endl;
}
int main()
{
	int n;
	string fileName;
	ifstream inputStream;
	ofstream outputStream;
	
	map<int, int, std::greater<int>> inputData;
	while (cin >> fileName)
	{
		//開啟檔案
		inputStream.open(fileName);

		inputData.clear();

		while (inputStream >> n)
		{
			//尋找inputData有無為n值的key
			map<int, int, std::greater<int>>::iterator iter;
			iter = inputData.find(n);

			if (iter == inputData.end()) 
			{
				//如果在inputData沒有找到key，就新增一筆key-value
				inputData.insert(make_pair(n, 1));
			}
			else
			{
				//如果在inputData找到key，就直接在該key的value+=1
				inputData[n]++;
			}
		}
		//關閉檔案
		inputStream.close();

		//將統計結果輸出至output.txt
		outputFile(inputData);
	}
	return 0;
}