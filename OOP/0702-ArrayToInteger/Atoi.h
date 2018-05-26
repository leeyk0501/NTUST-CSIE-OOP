// Name: ßı¶÷ÒZ
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0702"
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Atoi 
{
private:
	string beTrans;
	char sign;
public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();
};

