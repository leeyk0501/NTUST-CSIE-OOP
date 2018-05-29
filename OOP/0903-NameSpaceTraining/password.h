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
	string password;
	// Intent: 判斷password是否符合條件
	// Pre: NONE
	// Post: 如果password不符合條件，就回傳false，反之為true
	bool isValid()
	{
		bool haveNonLetter = false;
		bool atLeast8Char = false;
		if (password.size() >= 8)atLeast8Char = true; //不得少於8個char
		for (int i = 0; i < password.size(); i++)
		{
			if (!isalpha(password[i]))haveNonLetter = true; //至少要有一個不是letter，才符合條件
		}
		return(haveNonLetter && atLeast8Char);
	}
}
namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}
	string getPassword()
	{
		return password;
	}
}