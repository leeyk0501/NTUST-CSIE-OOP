#include<iostream>
#include<vector>
#include<string>
#define SIZE 1501
using namespace std;

string add(string a, string b)
{
	vector<int> A, B, result;
	string value;
	A.clear();
	B.clear();
	result.clear();
	value.clear();
	for (int i = a.size() - 1;i >= 0;i--)A.push_back(a[i] - '0');
	for (int i = b.size() - 1;i >= 0;i--)B.push_back(b[i] - '0');
	int bigger = a.size() > b.size() ? a.size() : b.size();
	int numValue = 0;
	for (int i = 0;i < bigger;i++)
	{
		int aValue, bValue;
		aValue = i < a.size() ? A[i] : 0;
		bValue = i < b.size() ? B[i] : 0;
		numValue += aValue + bValue;
		result.push_back(numValue % 10);
		numValue /= 10;
	}
	while (numValue > 0)
	{
		result.push_back(numValue % 10);
		numValue /= 10;
	}
	for (int i = result.size() - 1;i >= 0;i--) 
	{
		value.push_back(result[i] + '0');
	}
	return value;
}
int main()
{
	
	int input[3];
	while (cin >> input[0] >> input[1] >> input[2])
	{
		int process = 2;
		string fib[SIZE];
		fib[0] = "0";
		fib[1] = "1";
		for (int i = 2;i < SIZE;i++)fib[i] = "0";

		for (int j = 0;j < 3;j++)
		{
			int num = input[j];
			if (num == 0)cout << "0: 0" << endl;
			else
			{
				if (fib[num] != "0")cout << num << ": " << fib[num] << endl;
				else
				{
					for (int i = process;i <= num;i++) 
					{
						fib[i] = add(fib[i - 1], fib[i - 2]);
					}
					process = num;
					cout << num << ": " << fib[num] << endl;
				}
			}
		}
	}
	return 0;
}