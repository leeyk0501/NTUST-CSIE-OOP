// Name: 李聿鎧
// Date: 20180509
// Last Update: 20180509
// Problem statement: C++ Homework "0903 - namespace"
#pragma once
#include<iostream>
#include<string>
#include<locale> //用於isalpha
using namespace std;
namespace
{
	string username;
	// Intent: 判斷username是否符合條件
	// Pre: NONE
	// Post: 如果username不符合條件，就回傳false，反之為true
	bool isValid()
	{
		bool allLetter = true;
		bool only8Char = false;
		if (username.size() == 8)only8Char = true; //要剛好8個字元
		for (int i = 0; i < username.size(); i++)
		{
			if (!isalpha(username[i]))allLetter = false; //只要有一個不是letter，就不符合條件
		}
		return(allLetter && only8Char);
	}
}
namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}
	string getUserName()
	{
		return username;
	}
}


