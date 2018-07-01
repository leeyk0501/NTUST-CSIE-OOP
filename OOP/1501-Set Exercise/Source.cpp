// Name: ßı¶÷ÒZ
// Date: 20180619
// Last Update: 20180619
// Problem statement: C++ Homework "1501 - Set Exercise"
#include<iostream>
#include<fstream>
#include<string>
#include<set>
using namespace std;
int main()
{
	set<string> data;
	string temp;
	fstream fs("name.txt", ios::in);
	while (getline(fs, temp)) 
	{
		data.insert(temp);
	}
	fs.close();
	for (set<string>::iterator it = data.begin(); it != data.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}