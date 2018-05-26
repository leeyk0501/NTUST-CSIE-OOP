// Name: ßı¶÷ÒZ
// Date: 20180422
// Last Update: 20180422
// Problem statement: C++ Homework "0801"
#pragma once
#include<iostream> 
using namespace std;
class Polynomial
{
	public:
		Polynomial(); // creates an empty polynomial
		Polynomial(double coefficient);
		Polynomial(const Polynomial& poly);
		Polynomial(double coefficient[], int size);
		~Polynomial();
		//Use indexed polynomial as r-value to inspect coefficient
		//and as l-value to assign coefficient
		double& operator[](int degree);
		//This is required if we are to have const correctness
		const double& operator[](int degree)const;
		Polynomial& operator=(const Polynomial & rhs);
		int mySize();
		//friend functions:
		friend double evaluate(const Polynomial& poly, double arg);
		friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
		friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
		friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);
	private:
		double *coef;
		int size;
};