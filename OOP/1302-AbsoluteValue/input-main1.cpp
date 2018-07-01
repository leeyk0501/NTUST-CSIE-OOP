// Name: 李聿鎧
// Date: 20180605
// Last Update: 20180605
// Problem statement: C++ Homework "1302 - AbsoluteValue"
#include<iostream>
#include<cmath>
using namespace std;
// Intent: 取得兩數相減的絕對值
// Pre:    被減數、減數
// Post:   兩數相減的絕對值
template <class T>
double absoluteValue(T value1, T value2)
{
	double result = value1 - value2;
	return fabs(result);
}
int main()
{
	int i1, i2;
	double d1, d2;
	char c1, c2;
	i1 = 10; i2 = 20;
	cout << "Absolute value of 10, 20 is " << absoluteValue(i1, i2) << endl;

	d1 = 5.5; d2 = 3.1;
	cout << "Absolute value of 5.5, 3.1 is " << absoluteValue(d1, d2) << endl;

	c1 = 'A', c2 = 'C';
	cout << "Absolute value of A, C is " << absoluteValue(c1, c2) << endl;
	system("pause");
	return 0;
}