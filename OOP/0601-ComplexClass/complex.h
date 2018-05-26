// Name: ßı¶÷ÒZ
// Date: 2018/04/06
// Last Update: 2018/04/07
// Problem statement: C++ Homework "0601"
#include<iostream>
using namespace std;

class Complex
{
	public:
		//constructors
		Complex() :real_(0), imaginary_(0) {}
		Complex(double aValue) :real_(aValue), imaginary_(0) {}
		Complex(double aValue, double bValue) :real_(aValue), imaginary_(bValue) {}
	
		//operator overloading == , + , - , * , / , >> ,<< 
		friend bool operator ==(const Complex&, const Complex&);
		friend Complex operator+(const Complex&, const Complex&);
		friend Complex operator-(Complex, Complex);
		friend Complex operator*(const Complex&, const Complex&);
		friend Complex operator/(const Complex&, const Complex&);
		friend ostream& operator <<(ostream&, const Complex&);
		friend istream& operator >>(istream&, Complex&);
	
		friend double real(const Complex&);
		friend double imag(const Complex&);
		friend double norm(const Complex&);

		double real();
		double imag();

	private:
		double real_, imaginary_;
};