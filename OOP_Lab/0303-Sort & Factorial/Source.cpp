// Name: ßı¶÷ÒZ
// Date: March 15, 2018
// Last Update: March 15, 2018
// Problem statement: C++ Homework "0303 - Sort & Factorial"
#include<iostream>
#include<vector>
#include<algorithm> 
#include<string>
using namespace std;

long long int Factorial(int n)
{
	if (n > 1)
	{
		return n * Factorial(n - 1);
	}
	else
	{
		return 1;
	}
}
int main()
{
	int length, n;
	vector<int> data;
	while (cin >> length)
	{
		int i;
		data.clear();
		for (i = 0; i < length; i++)
		{
			cin >> n;
			data.push_back(n);
		}
		sort(data.begin(), data.end());
		for (i = 0; i < length - 1; i++) 
		{
			cout << Factorial(data[i]) << "<";
		}
		cout << Factorial(data[i]) << endl;
	}
	return 0;
}