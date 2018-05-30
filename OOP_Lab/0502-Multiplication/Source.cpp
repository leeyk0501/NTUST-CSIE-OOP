// Name: 李聿鎧
// Date: March 29, 2018
// Last Update: March 29, 2018
// Problem statement: C++ Homework "0502"
#include<iostream>
#include<vector>
using namespace std;

struct function
{
	int a, b, c, d;
}input;
int main()
{
	//輸入四個資料a b c d至struct
	while (cin >> input.a >> input.b >> input.c >> input.d)
	{
		int width = 3;
		int length = 2 * input.d + 1; //2^d+1是結果長度
		vector<int> ans(length); //答案用
		vector<int> temp(length); //暫存用
		ans[0] = input.c; //常數項
		ans[1] = input.b; //一次方係數
		ans[2] = input.a; //二次方係數
		for (int i = 0; i < input.d - 1; i++)
		{
			for (int j = 0; j < length; j++)
			{
				temp[j] = 0;
			}

			//計算開始
			//0次方
			for (int j = 0; j < width; j++)
			{
				temp[j] += input.c * ans[j];
			}
			//1次方
			for (int j = 0; j < width; j++)
			{
				temp[1 + j] += input.b * ans[j];
			}
			//2次方
			for (int j = 0; j < width; j++)
			{
				temp[2 + j] += input.a * ans[j];
			}
			width+=2;

			//將temp放入ans
			for (int j = 0; j < length; j++)
			{
				ans[j] = temp[j];
			}
		}

		//輸出結果
		for (int i = length - 1; i >= 0; i--) 
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}