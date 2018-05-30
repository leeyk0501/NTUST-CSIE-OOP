// Name: �����Z
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
	//��J�|�Ӹ��a b c d��struct
	while (cin >> input.a >> input.b >> input.c >> input.d)
	{
		int width = 3;
		int length = 2 * input.d + 1; //2^d+1�O���G����
		vector<int> ans(length); //���ץ�
		vector<int> temp(length); //�Ȧs��
		ans[0] = input.c; //�`�ƶ�
		ans[1] = input.b; //�@����Y��
		ans[2] = input.a; //�G����Y��
		for (int i = 0; i < input.d - 1; i++)
		{
			for (int j = 0; j < length; j++)
			{
				temp[j] = 0;
			}

			//�p��}�l
			//0����
			for (int j = 0; j < width; j++)
			{
				temp[j] += input.c * ans[j];
			}
			//1����
			for (int j = 0; j < width; j++)
			{
				temp[1 + j] += input.b * ans[j];
			}
			//2����
			for (int j = 0; j < width; j++)
			{
				temp[2 + j] += input.a * ans[j];
			}
			width+=2;

			//�Ntemp��Jans
			for (int j = 0; j < length; j++)
			{
				ans[j] = temp[j];
			}
		}

		//��X���G
		for (int i = length - 1; i >= 0; i--) 
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}