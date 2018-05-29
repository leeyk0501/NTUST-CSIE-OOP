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
	string username;
	// Intent: �P�_username�O�_�ŦX����
	// Pre: NONE
	// Post: �p�Gusername���ŦX����A�N�^��false�A�Ϥ���true
	bool isValid()
	{
		bool allLetter = true;
		bool only8Char = false;
		if (username.size() == 8)only8Char = true; //�n��n8�Ӧr��
		for (int i = 0; i < username.size(); i++)
		{
			if (!isalpha(username[i]))allLetter = false; //�u�n���@�Ӥ��Oletter�A�N���ŦX����
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


