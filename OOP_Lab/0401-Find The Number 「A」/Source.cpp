// Name: �����Z
// Date: March 22, 2018
// Last Update: March 22, 2018
// Problem statement: C++ Homework "0401 -  Find The Number A"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

// Intent: ��list�Pinput�̤p���t��
// Pre: list�ܤ֤j��@�����
// Post: �^��list�Pinput�̤p���t��
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

// Intent: ��Xlist���
// Pre: list�ܤ֤j��@�����
// Post: print�Xlist��ơA�����H" + "���Ů�
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

		//�ŧi�P��l��
		double d, minDiffer, differ;
		istrs.clear();
		list.clear();
		outputList.clear();
		
		//�N�Ĥ@���Ʊ����Jdouble vector
		while (istrs >> d)
		{
			list.push_back(d);
		}

		//��X�̤p�t�Z
		minDiffer = minimumDifference(list, number);

		//�N�̤p�t�Z���Ҧ��Ʀr�[�Joutput vector
		for (double i : list)
		{
			differ = abs(number - i);
			if (differ == minDiffer)
			{
				outputList.push_back(i);
			}
		}

		//��X���G
		print(outputList);

		cin >> tmp;
	}
	return 0;
}