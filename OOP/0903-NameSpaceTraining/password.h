// Name: �����Z
// Date: 20180509
// Last Update: 20180509
// Problem statement: C++ Homework "0903 - namespace"
#pragma once
#include<iostream>
#include<string>
#include<locale> //�Ω�isalpha
using namespace std;
namespace
{
	string password;
	// Intent: �P�_password�O�_�ŦX����
	// Pre: NONE
	// Post: �p�Gpassword���ŦX����A�N�^��false�A�Ϥ���true
	bool isValid()
	{
		bool haveNonLetter = false;
		bool atLeast8Char = false;
		if (password.size() >= 8)atLeast8Char = true; //���o�֩�8��char
		for (int i = 0; i < password.size(); i++)
		{
			if (!isalpha(password[i]))haveNonLetter = true; //�ܤ֭n���@�Ӥ��Oletter�A�~�ŦX����
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