// Name: ßı¶÷ÒZ
// Date: March 15, 2018
// Last Update: March 15, 2018
// Problem statement: C++ Homework "0301 - Number Pyramid"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string data;
	while (cin >> data)
	{
		int i = 0;
		for (; i < data.size()&&data[i] == '0'; i++);
		vector<unsigned long long int> pyramidTop, pyramid;
		unsigned long long int ans = 0;
		for (; i < data.size(); i++)
		{
			pyramidTop.push_back(data[i] - 48);
		}
		int width = pyramidTop.size();
		int height = pyramidTop.size();
		for (i = 0; i < height - 1; i++)
		{
			pyramid.clear();
			for (int j = 0; j < width - 1; j++) 
			{
				pyramid.push_back(pyramidTop[j] + pyramidTop[j + 1]);
			}
			pyramidTop = pyramid;
			width--;
			ans = pyramid[0];
		}
		cout << ans << endl;
	}
	return 0;
}