// Name: �����Z
// Date: 20180521
// Last Update: 20180521
// Problem statement: C++ Homework "1001- Combinations"
#include<iostream>
#define ELEMENTS_FOR_COMBINATION 5 //i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4
using namespace std;
// Intent: �L�X�զX���e
// Pre: m >= n && n > 0
// Post: �L�XCombination
void combination(int *arrayPtr, int *result, int m, int n, int start, int level)
{
	if (level == n) //Base case
	{
		//��Xresult
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
// Intent: �L�X�Ҧ��զX���e
// Pre: m >= n && n > 0
// Post: �L�XCombination
void PrintCombination(int *arrayPtr, int m, int n)
{
	if (m >= n && n > 0) //�ŦXCombination����
	{
		int *result = new int[n];
		combination(arrayPtr, result, m, n, 0, 0);
	}
}

//�]�D�ػ����u����@�~�ɡA�u������ function ����@�A���ݴ��� int main() { �K }�C�v
//�G�U�誺int main()�i�����
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
