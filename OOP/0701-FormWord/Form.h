// Name: �����Z
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0701"
#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class Form
{
private:
	string input;//��J���r
	string fileName;//�ɮצW��
	map<char, int> inputInfor; //�ݴ���r����T
	vector<string> conformWord; //�ŦX����r
public:
	void SetInputWord(string inputWord);//�]�wInput
	void ProcessInputWord();//�B�z Input ����T
	void SetFileName(string fileName);//�]�w�ɮצW��
	void Load_CompaerWord();//Ū�ɨåB���
	void PrintFoundWords();//�L�X�ŦX���r
};

