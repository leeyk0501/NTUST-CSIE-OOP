// Name: �����Z
// Date: 2018/04/02
// Last Update: 2018/04/02
// Problem statement: C++ Homework "0502"
#include "Header.h"

// Intent: ��J���(���)
// Pre: �z�LCIN��J���
// Post: �N����s�J�ܼ�month���A�p�G�W�L12��������1��
void Month::inputInt()
{
	int monthValue;
	cin >> monthValue;
	month = monthValue > 12 ? 1 : monthValue;
}

// Intent: ��J���(�r��)
// Pre: �z�LCIN��J�T�Ӧr��
// Post: �P�_�����s�J�ܼ�month���A�p�G�P�_���~��������1��
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

// Intent: ��X���(���)
// Pre: Month::month���o��NULL
// Post: print�X���(���)
void Month::outputInt()
{
	cout << month;
}

// Intent: ��X���(�r��)
// Pre: Month::month���o��NULL
// Post: print�X���(�r��)
void Month::outputStr()
{
	cout << monthIntToStr(month);
}

// Intent: �^�ǤU�@�Ӥ��
// Pre: Month::month���o��NULL
// Post: �^�ǤU�@�Ӥ��(���A��Month)�A�p�G�W�L12�몽������1��
Month Month::nextMonth()
{
	int nextValue = month + 1;
	nextValue = nextValue > 12 ? 1 : nextValue;
	Month nextMonth(nextValue);
	return nextMonth;
}

// Intent: �P�_�r�ꬰ�����A�^�Ǥ���Ʀr
// Pre: monthStr���T�r�����r��
// Post: �P�_�r�ꬰ�����A�^�Ǥ���Ʀr�A�p�G�P�_���~��������1��
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

// Intent: �P�_�Ʀr�������A�^�Ǥ���r��
// Pre: monthInt����ơA���o��NULL�A���o�j��12�A���o�p��0
// Post: �P�_�Ʀr�������A�^�Ǥ���r��
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