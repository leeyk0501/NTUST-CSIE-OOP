// Name: 李聿鎧
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0702"
#include "Atoi.h"

// Intent: Atoi的預設建構子
// Pre: NULL
// Post: 預設0，預設正號
Atoi::Atoi()
{
	beTrans = "0"; //預設0
	sign = '+'; //預設正號
}
// Intent: Atoi的建構子
// Pre: string不得為空
// Post: 判斷字串第一字元是否有負號，如果有負號，就會紀錄負號，存下負號後面的東西
Atoi::Atoi(string s)
{
	sign = s[0] == '-' ? '-' : '+'; //判斷是否有負號
	beTrans = s[0] == '-' ? s.substr(1, s.size() - 1) : s; //如果有負號，就存下負號後面的東西
}
// Intent: 設定beTrans
// Pre: string不得為空
// Post: 判斷字串第一字元是否有負號，如果有負號，就會紀錄負號，存下負號後面的東西
void Atoi::SetString(string s)
{
	sign = s[0] == '-' ? '-' : '+'; //判斷是否有負號
	beTrans = s[0] == '-' ? s.substr(1, s.size() - 1) : s; //如果有負號，就輸出負號後面的東西
}
// Intent: 得到輸入完整字串
// Pre: beTrans不要空的
// Post: 回傳輸入完整字串
const string Atoi::GetString()
{
	return this->beTrans;
}
// Intent: 得到輸入字串的完整長度
// Pre: beTrans不要空的
// Post: 回傳輸入字串的完整長度
int Atoi::Length()
{
	return beTrans.size();
}
// Intent: 判斷字串是否為digital
// Pre: beTrans不要空的
// Post: 字串為digital就回傳true，反之為false
bool Atoi::IsDigital()
{
	for (char c : beTrans)
	{
		if ((c >= '0' && c <= '9') || (c == '.')) //字元為0~9或小數點
		{
			//沒事做
		}
		else
		{
			return false;
		}
	}
	return true;
}
// Intent: 將字串轉成整數回傳
// Pre: beTrans不得為空
// Post: 將字串轉成整數回傳，如果超過INT_MAX就會回傳INT_MAX(根據官方atoi的機制)
int Atoi::StringToInteger()
{
	int value = 0;
	for (char c : beTrans)
	{
		if (c >= '0' && c <= '9') //如果字元為0~9
		{
			//如果超過INT_MAX就會回傳INT_MAX(根據官方atoi的機制)
			if (value > (INT_MAX / 10) && sign == '+')
			{
				if (sign == '+')
				{
					return INT_MAX;
				}
				else
				{
					return INT_MIN;
				}
				
			}
			value *= 10;
			value += (c - '0');
		}
		else if (c == '.') //遇到小數點就直接回傳小數點以前的東西
		{
			value = sign == '+' ? value : -value; //如果是負號的話就要轉成負的
			return value;
		}
		else //非法字元就直接回傳0
		{
			return 0;
		}
	}
	value = sign == '+' ? value : -value; //如果是負號的話就要轉成負的
	return value;
}