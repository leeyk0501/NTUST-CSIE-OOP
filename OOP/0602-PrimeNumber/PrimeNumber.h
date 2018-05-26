// Name: ßı¶÷ÒZ
// Date: 2018/04/06
// Last Update: 2018/04/06
// Problem statement: C++ Homework "0602"
#include<iostream>

using namespace std;

class PrimeNumber
{
public:
	PrimeNumber();
	PrimeNumber(int);
	int get();
	bool isPrimeNumber(int);

	//operator overloading
	PrimeNumber operator++(int);
	//operator overloading
	PrimeNumber operator--(int);
	//operator overloading
	PrimeNumber operator++();
	//operator overloading
	PrimeNumber operator--();
	
private:
	int number;
};