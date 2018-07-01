// Name: �����Z
// Date: 20180605
// Last Update: 20180605
// Problem statement: C++ Homework "1301 - templateBS"
#include<iostream>
#include<string>
#define ARRAY_SIZE 10
using namespace std;
// Intent: �G���j�M(�j��)
// Pre:    ���W��ư}�C�B�_�l���ޡB���I���ޡB�M���ơB�j�M���G�B�j�M��m
// Post:   �p�G���j�M��Afound�|��True�Alocation�Y����쪺��m
template<class T>
void ItrSearch(T data[], int first, int last, const T& key, bool& found, int& location)
{
	while (first <= last) 
	{
		int mid = (first + last) / 2;

		if (data[mid] > key) // �ѥi��Ҧb���d���Y� [l, mid-1]
		{
			last = mid - 1;
		}
		else if (data[mid] < key) // �ѥi��Ҧb���d���Y� [mid+1, r]
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
	
	location = -1; //�䤣��
	found = false; 
}
// Intent: �G���j�M(���j)
// Pre:    ���W��ư}�C�B�_�l���ޡB���I���ޡB�M���ơB�j�M���G�B�j�M��m
// Post:   �p�G���j�M��Afound�|��True�Alocation�Y����쪺��m
template<class T>
void recBinSrch(T data[], int first, int last, const T& key, bool& found, int& location)
{
	if (first <= last)
	{
		int mid = (first + last) / 2;

		if (data[mid] > key) // �ѥi��Ҧb���d���Y� [first, mid-1]
		{
			last = mid - 1;
			return recBinSrch(data, first, last, key, found, location);
		}
		else if (data[mid] < key) // �ѥi��Ҧb���d���Y� [mid+1, last]
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

	location = -1; //�䤣��
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
