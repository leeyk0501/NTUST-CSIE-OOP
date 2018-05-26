// Name: 李聿鎧
// Date: 2018/04/06
// Last Update: 2018/04/06
// Problem statement: C++ Homework "0602"
#include "PrimeNumber.h"

// Intent: 設定primenumber-default
// Pre: NULL
// Post: 設定primenumber為1(預設值)
PrimeNumber::PrimeNumber()
{
	this->number = 1;
}

// Intent: 設定primenumber-value
// Pre: NULL
// Post: 設定primenumber為value
PrimeNumber::PrimeNumber(int value)
{
	this->number = value;
}

// Intent: 取得目前的值
// Pre: NULL
// Post: 回傳目前的值(number)
int PrimeNumber::get()
{
	return number;
}

// Intent: 判斷該數字是否為質數
// Pre: number大於0
// Post: 如果數字為質數，回傳true，反之為false
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
// Post: 執行 operator overloading "a++"
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
// Post: 執行 operator overloading "a--"
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
// Post: 執行 operator overloading "++a"
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
// Post: 執行 operator overloading "--a"
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
