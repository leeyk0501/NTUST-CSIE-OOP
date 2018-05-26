// Name: 李聿鎧
// Date: 2018/04/02
// Last Update: 2018/04/02
// Problem statement: C++ Homework "0502"
#include "Header.h"

// Intent: 輸入月份(整數)
// Pre: 透過CIN輸入整數
// Post: 將月份存入變數month中，如果超過12直接視為1月
void Month::inputInt()
{
	int monthValue;
	cin >> monthValue;
	month = monthValue > 12 ? 1 : monthValue;
}

// Intent: 輸入月份(字元)
// Pre: 透過CIN輸入三個字元
// Post: 判斷月份後存入變數month中，如果判斷錯誤直接視為1月
void Month::inputStr()
{
	string monthValue;
	char c;
	cin >> c;
	monthValue.push_back(c);
	cin >> c;
	monthValue.push_back(c);
	cin >> c;
	monthValue.push_back(c);
	month = monthStrToInt(monthValue);
}

// Intent: 輸出月份(整數)
// Pre: Month::month不得為NULL
// Post: print出月份(整數)
void Month::outputInt()
{
	cout << month;
}

// Intent: 輸出月份(字串)
// Pre: Month::month不得為NULL
// Post: print出月份(字串)
void Month::outputStr()
{
	cout << monthIntToStr(month);
}

// Intent: 回傳下一個月份
// Pre: Month::month不得為NULL
// Post: 回傳下一個月份(型態為Month)，如果超過12月直接視為1月
Month Month::nextMonth()
{
	int nextValue = month + 1;
	nextValue = nextValue > 12 ? 1 : nextValue;
	Month nextMonth(nextValue);
	return nextMonth;
}

// Intent: 判斷字串為何月份，回傳月份數字
// Pre: monthStr為三字元的字串
// Post: 判斷字串為何月份，回傳月份數字，如果判斷錯誤直接視為1月
int Month::monthStrToInt(string monthStr)
{
	if (monthStr == "Jan")
	{
		return 1;
	}
	else if (monthStr == "Feb")
	{
		return 2;
	}
	else if (monthStr == "Mar")
	{
		return 3;
	}
	else if (monthStr == "Apr")
	{
		return 4;
	}
	else if (monthStr == "May")
	{
		return 5;
	}
	else if (monthStr == "Jun")
	{
		return 6;
	}
	else if (monthStr == "Jul")
	{
		return 7;
	}
	else if (monthStr == "Aug")
	{
		return 8;
	}
	else if (monthStr == "Sep")
	{
		return 9;
	}
	else if (monthStr == "Oct")
	{
		return 10;
	}
	else if (monthStr == "Nov")
	{
		return 11;
	}
	else if (monthStr == "Dec")
	{
		return 12;
	}
	else
	{
		return 1;
	}
}

// Intent: 判斷數字為何月份，回傳月份字串
// Pre: monthInt為整數，不得為NULL，不得大於12，不得小於0
// Post: 判斷數字為何月份，回傳月份字串
string Month::monthIntToStr(int monthInt)
{
	if (monthInt == 1)
	{
		return "Jan";
	}
	else if (monthInt == 2)
	{
		return "Feb";
	}
	else if (monthInt == 3)
	{
		return "Mar";
	}
	else if (monthInt == 4)
	{
		return "Apr";
	}
	else if (monthInt == 5)
	{
		return "May";
	}
	else if (monthInt == 6)
	{
		return "Jun";
	}
	else if (monthInt == 7)
	{
		return "Jul";
	}
	else if (monthInt == 8)
	{
		return "Aug";
	}
	else if (monthInt == 9)
	{
		return "Sep";
	}
	else if (monthInt == 10)
	{
		return "Oct";
	}
	else if (monthInt == 11)
	{
		return "Nov";
	}
	else if (monthInt == 12)
	{
		return "Dec";
	}
}