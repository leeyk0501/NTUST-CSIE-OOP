// Name: �����Z
// Date: March 27, 2018
// Last Update: March 27, 2018
// Problem statement: C++ Homework "0402- Fraction"
#include"Header.h"
// Intent: ���o�̤j���]��
// Pre: n������0
// Post: �Ǧ^�̤j���]��
int gcd(int m, int n)
{
	while (n != 0)
	{
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}
// Intent: �]�w���l
// Pre: num��int
// Post: �L
void Fraction::setNumerator(int num)
{
	numerator = num;
}
// Intent: �]�w����
// Pre: den��int
// Post: �L
void Fraction::setDenominator(int den)
{
	denominator = den;
}
// Intent: ���o�۰����G
// Pre: numerator�Pdenominator���o��null�Adenominator���o��0
// Post: �^��
double Fraction::getDouble()
{
	double ans;
	ans = numerator / denominator;
	return ans;
}
// Intent: print�X��²�L������
// Pre: numerator�Pdenominator���o��null�Adenominator���o��0
// Post: print�X��²�L������
void Fraction::outputReducedFraction()
{
	int i = gcd(numerator, denominator);
	numerator /= i;
	denominator /= i;
	if (denominator == 1)
	{
		cout << numerator;
	}
	else
	{
		cout << numerator << "/" << denominator;
	}
}
	