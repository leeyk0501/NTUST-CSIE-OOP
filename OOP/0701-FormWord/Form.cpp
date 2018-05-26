// Name: 李聿鎧
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0701"
#include "Form.h"

// Intent: 設定Input
// Pre: inputWord為string
// Post: 設定待測單字
void Form::SetInputWord(string inputWord)
{
	this->input = inputWord;
}
// Intent: 處理Input資訊
// Pre: inputWord不得為空
// Post: 處理Input資訊
void Form::ProcessInputWord()
{
	inputInfor.clear();
	char value;
	map<char, int>::iterator iter;
	for (char c : this->input)
	{
		//把小寫認成大寫，其他不動
		value = (c >= 'a'&&c <= 'z') ? c - ('a' - 'A') : c;

		//尋找map內是否有該char資料
		iter = inputInfor.find(value);
		if (iter != inputInfor.end()) //不存在
		{
			inputInfor[value]++;
		}
		else //存在
		{
			inputInfor[value] = 1;
		}
	}
}
// Intent: 設定檔案名稱
// Pre: inputWord為string
// Post: 設定input
void Form::SetFileName(string fileName)
{
	this->fileName = fileName;
}
// Intent: 讀檔並且比較
// Pre: fileName檔案須存在
// Post: 讀檔並且比較出結果並存到vector裡面
void Form::Load_CompaerWord()
{
	map<char, int> compaeWord;
	fstream fs;
	string str;
	conformWord.clear();
	fs.open(fileName); //打開文件
	while (getline(fs, str))
	{
		map<char, int>::iterator iter;
		char value;
		
		//符合文字vector清空
		compaeWord.clear();
		for (char c : str)
		{
			//把小寫認成大寫，其他不動
			value = (c >= 'a'&&c <= 'z') ? c - ('a' - 'A') : c;

			//尋找map內是否有該char資料
			iter = compaeWord.find(value);
			if (iter != compaeWord.end()) //存在
			{
				compaeWord[value]++;
			}
			else //不存在
			{
				compaeWord[value] = 1;
			}
		}
		if (compaeWord.size() <= inputInfor.size()) //組合的單字數目"大於"待測單字的組合數目
		{
			bool isConform = true;
			map<char, int>::iterator iterChar;
			for (iter = compaeWord.begin(); iter != compaeWord.end(); iter++)
			{
				iterChar = inputInfor.find(iter->first);
				if (iterChar == inputInfor.end()) //找不到字元
				{
					isConform = false; //不符合條件
					break; //直接離開迴圈
				}
				else if (iter->second > inputInfor[iter->first]) //找到字元，但是該字元的使用數目大於待測字元的使用數目
				{
					isConform = false; //不符合條件
					break; //直接離開迴圈
				}
			}
			if (isConform)
			{
				conformWord.push_back(str);  //將符合答案的文字放進vector中
			}
		}
	}
	fs.close(); //關閉文件
}
// Intent: 印出符合的字
// Pre: conformWord為vector
// Post: 印出找到的單字
void Form::PrintFoundWords()
{
	for (string str : conformWord)
	{
		cout << str << endl; //輸出單字
	}
}
