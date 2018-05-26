// Name: ßı¶÷ÒZ
// Date: 2018/04/02
// Last Update: 2018/04/02
// Problem statement: C++ Homework "0502"
#include<iostream>
#include<string>
using namespace std;

class Month
{
public:
	Month(int monthValue) : month(monthValue > 12 ? 1 : monthValue) {}
	Month(char monthChar1, char monthChar2, char monthChar3)
	{
		string monthStr;
		monthStr.push_back(monthChar1);
		monthStr.push_back(monthChar2);
		monthStr.push_back(monthChar3);
		month = monthStrToInt(monthStr);
	}
	Month() :month(1) {}
	Month nextMonth();
	void inputInt();
	void inputStr();
	void outputInt();
	void outputStr();
	int monthStrToInt(string);
	string monthIntToStr(int);
private:
	int month;
};
