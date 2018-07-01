// Name: 李聿鎧
// Date: 20180521
// Last Update: 20180521
// Problem statement: C++ Homework "1001- Combinations"
#include<iostream>
#define ELEMENTS_FOR_COMBINATION 5 //i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4
using namespace std;
// Intent: 印出組合內容
// Pre: m >= n && n > 0
// Post: 印出Combination
void combination(int *arrayPtr, int *result, int m, int n, int start, int level)
{
	if (level == n) //Base case
	{
		//輸出result
		int i;
		for (i = 0; i < n-1; i++)
		{
			cout << result[i] << " ";
		}
		cout << result[i] << endl;
	}
	else
	{
		for (int i = start; i <= m - (n - level); i++)
		{
			result[level] = arrayPtr[i];
			combination(arrayPtr, result, m, n, i + 1, level + 1);
		}
	}
}
// Intent: 印出所有組合內容
// Pre: m >= n && n > 0
// Post: 印出Combination
void PrintCombination(int *arrayPtr, int m, int n)
{
	if (m >= n && n > 0) //符合Combination條件
	{
		int *result = new int[n];
		combination(arrayPtr, result, m, n, 0, 0);
	}
}

//因題目說明「提交作業時，只須提交 function 的實作，不需提交 int main() { … }。」
//故下方的int main()進行註解
//int main(void)
//{
//	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];
//	//Get all elements for combination
//	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
//		arrayPtr[i] = i + 1;
//	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);
//	if (arrayPtr != NULL)
//		delete[] arrayPtr;
//	system("pause");
//	return 0;
//}
