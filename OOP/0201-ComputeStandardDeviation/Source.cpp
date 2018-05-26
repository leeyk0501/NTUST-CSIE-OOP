#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

double Average(vector<double> data)
{
	double ave = 0;
	for (double i : data)
	{
		ave += i;
	}
	ave /= data.size();
	return ave;
}
double StandardDeviation(vector<double> data, double average)
{
	double dev = 0;
	for (double i : data)
	{
		dev += pow(i - average, 2);
	}
	dev = sqrt(dev / data.size());
	return dev;
}
int main()
{
	double n, temp;
	double ave, dev;
	vector<double> data;
	while (cin >> n)
	{
		data.clear();
		for (int i = 0; i<n; i++)
		{
			cin >> temp;
			data.push_back(temp);
		}
		ave = Average(data);
		dev = StandardDeviation(data, ave);
		cout << "Average:" << ave << "\tStandard deviation:" << dev << endl;
	}
	return 0;
}
