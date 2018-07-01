// Name: 李聿鎧
// Date: 20180605
// Last Update: 20180605
// Problem statement: C++ Homework "1301 - templateBS"
#include<iostream>
#include<string>
#define ARRAY_SIZE 10
using namespace std;
// Intent: 二分搜尋(迴圈)
// Pre:    遞增整數陣列、起始索引、終點索引、尋找資料、搜尋結果、搜尋位置
// Post:   如果有搜尋到，found會為True，location即為找到的位置
template<class T>
void ItrSearch(T data[], int first, int last, const T& key, bool& found, int& location)
{
	while (first <= last) 
	{
		int mid = (first + last) / 2;

		if (data[mid] > key) // 解可能所在的範圍縮減為 [l, mid-1]
		{
			last = mid - 1;
		}
		else if (data[mid] < key) // 解可能所在的範圍縮減為 [mid+1, r]
		{
			first = mid + 1;
		}
		else // data[mid] == K
		{
			location = mid;
			found = true;
			return;
		}
	}
	
	location = -1; //找不到
	found = false; 
}
// Intent: 二分搜尋(遞迴)
// Pre:    遞增整數陣列、起始索引、終點索引、尋找資料、搜尋結果、搜尋位置
// Post:   如果有搜尋到，found會為True，location即為找到的位置
template<class T>
void recBinSrch(T data[], int first, int last, const T& key, bool& found, int& location)
{
	if (first <= last)
	{
		int mid = (first + last) / 2;

		if (data[mid] > key) // 解可能所在的範圍縮減為 [first, mid-1]
		{
			last = mid - 1;
			return recBinSrch(data, first, last, key, found, location);
		}
		else if (data[mid] < key) // 解可能所在的範圍縮減為 [mid+1, last]
		{
			first = mid + 1;
			return recBinSrch(data, first, last, key, found, location);
		}
		else // data[mid] == K
		{
			location = mid;
			found = true;
			return;
		}
	}

	location = -1; //找不到
	found = false;
	return;
}
int main()
{
	int a[ARRAY_SIZE];
	const int finalIndex = ARRAY_SIZE - 1;
	int i;
	for (i = 0; i < ARRAY_SIZE; i++)
		a[i] = 3 * i;
	cout << "Array contains:\n";
	for (i = 0; i < ARRAY_SIZE; i++)
		cout << a[i] << " ";
	cout << endl;
	int key, location;
	bool found;
	cout << "Enter number to be located: ";
	cin >> key;
	cout << "\nTesting Template Iterative Binary Search\n";
	ItrSearch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;
	cout << "\nTesting Template Recursive Binary Search\n";
	recBinSrch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;
	system("pause");
	return 0;
}
