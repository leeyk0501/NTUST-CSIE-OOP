// Name: 李聿鎧
// Date: March 22, 2018
// Last Update: March 22, 2018
// Problem statement: C++ Homework "0401 -  Find The Number A"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

// Intent: 找list與input最小的差值
// Pre: list至少大於一筆資料
// Post: 回傳list與input最小的差值
double minimumDifference(vector<double> list, double input)
{
	double min = (double)LLONG_MAX, differ;
	for (double d : list)
	{
		differ = abs(input - d);
		if (differ < min) 
		{
			min = differ;
		}
	}
	return min;
}

// Intent: 輸出list資料
// Pre: list至少大於一筆資料
// Post: print出list資料，中間以" + "為空格
void print(vector<double> list)
{
	int i, size = list.size() - 1;
	for (i = 0; i < size; i++)
	{
		cout << list[i] << " + ";
	}
	cout << list[i] << endl;
}
int main()
{
	char tmp;
	string data;
	istringstream istrs;
	vector<double> list;
	vector<double> outputList;
	double number;

	while (getline(cin, data, '\n')) 
	{
		istrs.str(data);
		cin >> number;

		//宣告與初始化
		double d, minDiffer, differ;
		istrs.clear();
		list.clear();
		outputList.clear();
		
		//將第一行資料接續輸入double vector
		while (istrs >> d)
		{
			list.push_back(d);
		}

		//找出最小差距
		minDiffer = minimumDifference(list, number);

		//將最小差距的所有數字加入output vector
		for (double i : list)
		{
			differ = abs(number - i);
			if (differ == minDiffer)
			{
				outputList.push_back(i);
			}
		}

		//輸出結果
		print(outputList);

		cin >> tmp;
	}
	return 0;
}