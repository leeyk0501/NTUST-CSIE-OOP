// Name: χ馴
// Date: March 27, 2018
// Last Update: March 27, 2018
// Problem statement: C++ Homework "0402- Fraction"
#include"Header.h"
// Intent: 眔程そ计
// Pre: nぃ单0
// Post: 肚程そ计
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
// Intent: 砞﹚だ
// Pre: numint
// Post: 礚
void Fraction::setNumerator(int num)
{
	numerator = num;
}
// Intent: 砞﹚だダ
// Pre: denint
// Post: 礚
void Fraction::setDenominator(int den)
{
	denominator = den;
}
// Intent: 眔埃挡狦
// Pre: numerator籔denominatorぃ眔nulldenominatorぃ眔0
// Post: 肚
double Fraction::getDouble()
{
	double ans;
	ans = numerator / denominator;
	return ans;
}
// Intent: printて虏筁だ计
// Pre: numerator籔denominatorぃ眔nulldenominatorぃ眔0
// Post: printて虏筁だ计
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
	