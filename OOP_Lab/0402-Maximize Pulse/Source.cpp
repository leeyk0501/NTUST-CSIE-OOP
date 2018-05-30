// Name: 李聿鎧
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

// Intent: 計算該字串的maximizePulse
// Pre: pulseStr字串長度大於0
// Post: 回傳該字串的maximizePulse
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
// Intent: 計算該字串的出現1的比率
// Pre: str字串長度大於0
// Post: 回傳該字串的出現1的比率
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
		//初始化
		max = -1;
		strData.clear();
		infor.clear();

		//輸入每一筆資料，算出每筆資料"出現1的比率"
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			strData.push_back(str);
			tempInfo.index = i;
			tempInfo.probability = strProbability(str);
			infor.push_back(tempInfo);
		}
		
		//以比率(probability)做排序
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

		//依比率由大到小組合出字串
		str.clear();
		for (int i = 0; i < size; i++)
		{
			str += strData[infor[i].index];
		}

		//輸出該字串的maximizePulse
		cout << maximizePulse(str) << endl;
	}
	return 0;
}