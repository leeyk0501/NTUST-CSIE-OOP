// Name: 李聿鎧
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0701"
#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class Form
{
private:
	string input;//輸入的字
	string fileName;//檔案名稱
	map<char, int> inputInfor; //待測單字的資訊
	vector<string> conformWord; //符合的單字
public:
	void SetInputWord(string inputWord);//設定Input
	void ProcessInputWord();//處理 Input 的資訊
	void SetFileName(string fileName);//設定檔案名稱
	void Load_CompaerWord();//讀檔並且比較
	void PrintFoundWords();//印出符合的字
};

