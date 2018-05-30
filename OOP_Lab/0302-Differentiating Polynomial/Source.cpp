// Name: ßı¶÷ÒZ
// Date: March 15, 2018
// Last Update: March 15, 2018
// Problem statement: C++ Homework "0302 - Differentiating polynomial"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int length, nowCoe;

void Print(int* coefficients)
{
	int i;
	for (i = 0; i < nowCoe - 1; i++)
	{
		cout << coefficients[i] << " ";
	}
	cout << coefficients[i] << endl;
}
void Differential(int* coefficients)
{
	for (int i = 0; i < nowCoe; i++)
	{
		int coe = nowCoe - (i + 1);
		coefficients[i] *= coe;
	}
	nowCoe--;
}
void Differential(int* coefficients, int times)
{
	int* _coefficients;
	_coefficients = new int[length];
	for (int i = 0; i < length; i++)
	{
		_coefficients[i] = coefficients[i];
	}

	nowCoe = length;
	for (int i = 0; i < times; i++)
	{
		Differential(_coefficients);
	}

	Print(_coefficients);
}

int main()
{
	int times;
	
	while (cin >> length >> times)
	{
		int* coefficients;
		coefficients = new int[length];
		for (int i = 0; i < length; i++)
		{
			cin >> coefficients[i];
		}

		//method 1 differential
		Differential(coefficients, times);

		//method 2 differential
		nowCoe = length;
		for (int i = 0; i < times; i++)
		{
			Differential(coefficients);
			Print(coefficients);
		}
	}
	return 0;
}