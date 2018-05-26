// Name: �����Z
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0702"
#include "Atoi.h"

// Intent: Atoi���w�]�غc�l
// Pre: NULL
// Post: �w�]0�A�w�]����
Atoi::Atoi()
{
	beTrans = "0"; //�w�]0
	sign = '+'; //�w�]����
}
// Intent: Atoi���غc�l
// Pre: string���o����
// Post: �P�_�r��Ĥ@�r���O�_���t���A�p�G���t���A�N�|�����t���A�s�U�t���᭱���F��
Atoi::Atoi(string s)
{
	sign = s[0] == '-' ? '-' : '+'; //�P�_�O�_���t��
	beTrans = s[0] == '-' ? s.substr(1, s.size() - 1) : s; //�p�G���t���A�N�s�U�t���᭱���F��
}
// Intent: �]�wbeTrans
// Pre: string���o����
// Post: �P�_�r��Ĥ@�r���O�_���t���A�p�G���t���A�N�|�����t���A�s�U�t���᭱���F��
void Atoi::SetString(string s)
{
	sign = s[0] == '-' ? '-' : '+'; //�P�_�O�_���t��
	beTrans = s[0] == '-' ? s.substr(1, s.size() - 1) : s; //�p�G���t���A�N��X�t���᭱���F��
}
// Intent: �o���J����r��
// Pre: beTrans���n�Ū�
// Post: �^�ǿ�J����r��
const string Atoi::GetString()
{
	return this->beTrans;
}
// Intent: �o���J�r�ꪺ�������
// Pre: beTrans���n�Ū�
// Post: �^�ǿ�J�r�ꪺ�������
int Atoi::Length()
{
	return beTrans.size();
}
// Intent: �P�_�r��O�_��digital
// Pre: beTrans���n�Ū�
// Post: �r�ꬰdigital�N�^��true�A�Ϥ���false
bool Atoi::IsDigital()
{
	for (char c : beTrans)
	{
		if ((c >= '0' && c <= '9') || (c == '.')) //�r����0~9�Τp���I
		{
			//�S�ư�
		}
		else
		{
			return false;
		}
	}
	return true;
}
// Intent: �N�r���ন��Ʀ^��
// Pre: beTrans���o����
// Post: �N�r���ন��Ʀ^�ǡA�p�G�W�LINT_MAX�N�|�^��INT_MAX(�ھکx��atoi������)
int Atoi::StringToInteger()
{
	int value = 0;
	for (char c : beTrans)
	{
		if (c >= '0' && c <= '9') //�p�G�r����0~9
		{
			//�p�G�W�LINT_MAX�N�|�^��INT_MAX(�ھکx��atoi������)
			if (value > (INT_MAX / 10) && sign == '+')
			{
				if (sign == '+')
				{
					return INT_MAX;
				}
				else
				{
					return INT_MIN;
				}
				
			}
			value *= 10;
			value += (c - '0');
		}
		else if (c == '.') //�J��p���I�N�����^�Ǥp���I�H�e���F��
		{
			value = sign == '+' ? value : -value; //�p�G�O�t�����ܴN�n�ন�t��
			return value;
		}
		else //�D�k�r���N�����^��0
		{
			return 0;
		}
	}
	value = sign == '+' ? value : -value; //�p�G�O�t�����ܴN�n�ন�t��
	return value;
}