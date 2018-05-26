// Name: �����Z
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0701"
#include "Form.h"

// Intent: �]�wInput
// Pre: inputWord��string
// Post: �]�w�ݴ���r
void Form::SetInputWord(string inputWord)
{
	this->input = inputWord;
}
// Intent: �B�zInput��T
// Pre: inputWord���o����
// Post: �B�zInput��T
void Form::ProcessInputWord()
{
	inputInfor.clear();
	char value;
	map<char, int>::iterator iter;
	for (char c : this->input)
	{
		//��p�g�{���j�g�A��L����
		value = (c >= 'a'&&c <= 'z') ? c - ('a' - 'A') : c;

		//�M��map���O�_����char���
		iter = inputInfor.find(value);
		if (iter != inputInfor.end()) //���s�b
		{
			inputInfor[value]++;
		}
		else //�s�b
		{
			inputInfor[value] = 1;
		}
	}
}
// Intent: �]�w�ɮצW��
// Pre: inputWord��string
// Post: �]�winput
void Form::SetFileName(string fileName)
{
	this->fileName = fileName;
}
// Intent: Ū�ɨåB���
// Pre: fileName�ɮ׶��s�b
// Post: Ū�ɨåB����X���G�æs��vector�̭�
void Form::Load_CompaerWord()
{
	map<char, int> compaeWord;
	fstream fs;
	string str;
	conformWord.clear();
	fs.open(fileName); //���}���
	while (getline(fs, str))
	{
		map<char, int>::iterator iter;
		char value;
		
		//�ŦX��rvector�M��
		compaeWord.clear();
		for (char c : str)
		{
			//��p�g�{���j�g�A��L����
			value = (c >= 'a'&&c <= 'z') ? c - ('a' - 'A') : c;

			//�M��map���O�_����char���
			iter = compaeWord.find(value);
			if (iter != compaeWord.end()) //�s�b
			{
				compaeWord[value]++;
			}
			else //���s�b
			{
				compaeWord[value] = 1;
			}
		}
		if (compaeWord.size() <= inputInfor.size()) //�զX����r�ƥ�"�j��"�ݴ���r���զX�ƥ�
		{
			bool isConform = true;
			map<char, int>::iterator iterChar;
			for (iter = compaeWord.begin(); iter != compaeWord.end(); iter++)
			{
				iterChar = inputInfor.find(iter->first);
				if (iterChar == inputInfor.end()) //�䤣��r��
				{
					isConform = false; //���ŦX����
					break; //�������}�j��
				}
				else if (iter->second > inputInfor[iter->first]) //���r���A���O�Ӧr�����ϥμƥؤj��ݴ��r�����ϥμƥ�
				{
					isConform = false; //���ŦX����
					break; //�������}�j��
				}
			}
			if (isConform)
			{
				conformWord.push_back(str);  //�N�ŦX���ת���r��ivector��
			}
		}
	}
	fs.close(); //�������
}
// Intent: �L�X�ŦX���r
// Pre: conformWord��vector
// Post: �L�X��쪺��r
void Form::PrintFoundWords()
{
	for (string str : conformWord)
	{
		cout << str << endl; //��X��r
	}
}
