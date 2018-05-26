// Name: �����Z
// Date: 2018/04/06
// Last Update: 2018/04/06
// Problem statement: C++ Homework "0602"
#include "PrimeNumber.h"

// Intent: �]�wprimenumber-default
// Pre: NULL
// Post: �]�wprimenumber��1(�w�]��)
PrimeNumber::PrimeNumber()
{
	this->number = 1;
}

// Intent: �]�wprimenumber-value
// Pre: NULL
// Post: �]�wprimenumber��value
PrimeNumber::PrimeNumber(int value)
{
	this->number = value;
}

// Intent: ���o�ثe����
// Pre: NULL
// Post: �^�ǥثe����(number)
int PrimeNumber::get()
{
	return number;
}

// Intent: �P�_�ӼƦr�O�_�����
// Pre: number�j��0
// Post: �p�G�Ʀr����ơA�^��true�A�Ϥ���false
bool PrimeNumber::isPrimeNumber(int number)
{
	bool isPrime = true;
	if (number == 0 || number == 1)
	{
		return false;
	}
	else if (number == 2)
	{
		return true;
	}
	for (int i = 2; i < number; i++)
	{
		if (number%i == 0)
		{
			isPrime = false;
		}
	}
	return isPrime;
}

// Intent: operator overloading "a++"
// Pre: int number
// Post: ���� operator overloading "a++"
PrimeNumber PrimeNumber::operator++(int number) 
{
	int nowPrime = this->number;
	int nextPrime = this->number + 1;
	for (; !isPrimeNumber(nextPrime); nextPrime++) 
	{
	}
	this->number = nextPrime;
	return PrimeNumber(nowPrime);
}

// Intent: operator overloading "a--"
// Pre: int number
// Post: ���� operator overloading "a--"
PrimeNumber PrimeNumber::operator--(int number)
{
	int nowPrime = this->number;
	int nextPrime = this->number - 1;
	for (; nextPrime > 1; nextPrime--) 
	{
		if (isPrimeNumber(nextPrime))
		{
			this->number = nextPrime;
			return PrimeNumber(nowPrime);
		}
	}
	this->number = nextPrime;
	return PrimeNumber(nowPrime);
}

// Intent: operator overloading "++a"
// Pre: int number
// Post: ���� operator overloading "++a"
PrimeNumber PrimeNumber::operator++()
{
	int nextPrime = this->number + 1;
	for (; !isPrimeNumber(nextPrime); nextPrime++)
	{
	}
	this->number = nextPrime;
	return PrimeNumber(nextPrime);
}

// Intent: operator overloading "--a"
// Pre: int number
// Post: ���� operator overloading "--a"
PrimeNumber PrimeNumber::operator--()
{
	int nextPrime = this->number - 1;
	for (; nextPrime > 1; nextPrime--)
	{
		if (isPrimeNumber(nextPrime))
		{
			this->number = nextPrime;
			return PrimeNumber(nextPrime);
		}
	}
	this->number = nextPrime;
	return PrimeNumber(nextPrime);
}
