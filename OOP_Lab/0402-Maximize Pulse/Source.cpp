// Name: �����Z
// Date: March 22, 2018
// Last Update: March 22, 2018
// Problem statement: C++ Homework "0402 -  Maximize Pulse"
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int max;
struct strInfor
{
	int index;
	double probability;
};

// Intent: �p��Ӧr�ꪺmaximizePulse
// Pre: pulseStr�r����פj��0
// Post: �^�ǸӦr�ꪺmaximizePulse
int maximizePulse(string pulseStr)
{
	int max = 0;
	for (int i = pulseStr.size() - 1; i >= 0; i--)
	{
		if (pulseStr[i] == '0')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (pulseStr[j] == '1')
				{
					max++;
				}
			}
		}
	}
	return max;
}
// Intent: �p��Ӧr�ꪺ�X�{1����v
// Pre: str�r����פj��0
// Post: �^�ǸӦr�ꪺ�X�{1����v
double strProbability(string str)
{
	double count = 0, size = str.size();
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
		{
			count++;
		}
	}
	return (count / size);
}
int main()
{
	int n;
	string str;
	vector<string> strData;
	vector<strInfor> infor;
	strInfor tempInfo;

	while (cin >> n)
	{
		//��l��
		max = -1;
		strData.clear();
		infor.clear();

		//��J�C�@����ơA��X�C�����"�X�{1����v"
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			strData.push_back(str);
			tempInfo.index = i;
			tempInfo.probability = strProbability(str);
			infor.push_back(tempInfo);
		}
		
		//�H��v(probability)���Ƨ�
		int size = infor.size();
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (infor[i].probability < infor[j].probability)
				{
					swap(infor[i], infor[j]);
				}
			}
		}

		//�̤�v�Ѥj��p�զX�X�r��
		str.clear();
		for (int i = 0; i < size; i++)
		{
			str += strData[infor[i].index];
		}

		//��X�Ӧr�ꪺmaximizePulse
		cout << maximizePulse(str) << endl;
	}
	return 0;
}