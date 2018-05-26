// Name: 李聿鎧
// Date: 20180508
// Last Update: 20180508
// Problem statement: C++ Homework "0901 - Reversal"
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#define FILENAME "words.txt" //檔名
using namespace std;

// Intent: 單字轉小寫
// Pre: word為string
// Post: 輸出全小寫的單字
string toLower(string word)
{
	int cut = 'a' - 'A';
	for (int i = 0; i < word.size(); i++)word[i] = (word[i] >= 'A' && word[i] <= 'Z') ? word[i] + cut : word[i];
	return word;
}
int main()
{
	map<string, int> wordData;	//不重複資料
	vector<string> wordFile;	//全部資料
	ifstream in(FILENAME); // 讀取檔案FILENAME
	stringstream strStream(static_cast<stringstream const&>(stringstream() << in.rdbuf()).str()); //讀取文件內所有資料
	string str, lStr, rStr;
	int i = 0;
	while (getline(strStream, str, '\n')) //分行讀取
	{
		if (str.size() > 0) //非空單字
		{
			lStr = toLower(str);
			bool find;
			find = wordData.count(lStr); //將單字(key)以及流水號(value)放入map(不分大小寫)
			if (!find)wordData[lStr] = i;

			wordFile.push_back(str); //將所有單字放入vector(有分大小寫)

			i++;//流水號
		}
	}

	int max = -1; //目前最長符合條件的單字
	int nowID = i; // 目前最長符合條件的單字流水號
	map<string, int>::iterator temp = wordData.end();
	for (vector<string>::iterator iter = wordFile.begin(); iter != wordFile.end(); iter++)
	{
		rStr = iter->c_str();
		reverse(rStr.begin(), rStr.end()); //反轉字串
		rStr = toLower(rStr); //字串改小寫
		map<string, int>::iterator itit = wordData.find(rStr);
		if (itit != wordData.end())
		{
			int size = itit->first.size();

			//如果找到符合條件且長度更長的單字，或是找到符合條件、長度足夠且長位置更前面的單字
			if (size > max || (size >= max && itit->second < nowID)) 
			{
				max = size;
				nowID = itit->second;
				temp = itit;
			}
		}
	}
	if (temp != wordData.end())cout << wordFile[temp->second] << endl; //符合條件的單字就輸出(同樣長度就輸出最先找到的)
	
	system("pause");
	return 0;
}