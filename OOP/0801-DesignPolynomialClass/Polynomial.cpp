// Name: 李聿鎧
// Date: 20180422
// Last Update: 20180422
// Problem statement: C++ Homework "0801"
#include "Polynomial.h"

// Intent: creates an empty polynomial
// Pre: NULL
// Post: creates an empty polynomial
Polynomial::Polynomial() 
{
	this->coef = new double[1];
	this->coef[0] = 0;
	this->size = 0;
}

// Intent: constructor for coefficient
// Pre: double coefficient
// Post: constructor for coefficient
Polynomial::Polynomial(double coefficient)
{
	this->coef = new double[1];
	this->size = 1;
	coef[0] = coefficient;
}

// Intent: constructor for const Polynomial& poly
// Pre: const Polynomial& poly
// Post: constructor for const Polynomial& poly
Polynomial::Polynomial(const Polynomial& poly)
{
	this->size = poly.size;
	this->coef = new double[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->coef[i] = poly.coef[i];
	}
}

// Intent: constructor for coefficient and size
// Pre: coefficient and size
// Post: constructor for coefficient and size
Polynomial::Polynomial(double coefficient[], int size)
{
	this->coef = new double[size];
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		coef[i] = coefficient[i];
	}
}

// Intent: destructor 
// Pre: NULL
// Post: delete coef 
Polynomial::~Polynomial()
{
	delete[] coef;
}

// Intent: operator overloading for "[]"
// Pre: int degree
// Post: operator overloading for "[]"
double& Polynomial::operator[](int degree)
{
	return this->coef[degree];
}

// Intent: operator overloading for "[]"
// Pre: int degree
// Post: operator overloading for "[]"
const double& Polynomial::operator[](int degree)const
{
	return this->coef[degree];
}

// Intent: operator overloading for "="
// Pre: rhs
// Post: operator overloading for "="
Polynomial& Polynomial::operator=(const Polynomial & rhs)
{
	this->coef = new double[rhs.size];
	this->size = rhs.size;
	for (int i = 0; i < rhs.size; i++)
	{
		this->coef[i] = rhs.coef[i];
	}
	return *this;
}

// Intent: get size
// Pre: NULL
// Post: return size
int Polynomial::mySize()
{
	return this->size;
}

// Intent: evaluate the polynomial
// Pre: lhs & rhs
// Post: return polynomial value
double evaluate(const Polynomial& poly, double arg)
{
	double value = 0;
	for (int i = 0; i < poly.size; i++)
	{
		value += poly.coef[i] * pow(arg, i);
	}
	return value;
}

// Intent: friend function operator overloading for "+"
// Pre: lhs & rhs
// Post: operator overloading for "+"
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
	int size = lhs.size > rhs.size ? lhs.size : rhs.size;
	Polynomial temp;
	temp.coef = new double[size];
	temp.size = size;
	//歸零
	for (int i = 0; i < size; i++)
	{
		temp.coef[i] = 0;
	}
	//兩多項式相加
	for (int i = 0; i < lhs.size; i++)
	{
		temp.coef[i] += lhs.coef[i];
	}
	for (int i = 0; i < rhs.size; i++)
	{
		temp.coef[i] += rhs.coef[i];
	}
	return temp;
}

// Intent: friend function operator overloading for "-"
// Pre: lhs & rhs
// Post: operator overloading for "-"
Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{
	int size = lhs.size > rhs.size ? lhs.size : rhs.size;
	Polynomial temp;
	temp.coef = new double[size];
	temp.size = size;
	//歸零
	for (int i = 0; i < size; i++)
	{
		temp.coef[i] = 0;
	}
	//兩多項式相減
	for (int i = 0; i < lhs.size; i++)
	{
		temp.coef[i] = lhs.coef[i];
	}
	for (int i = 0; i < rhs.size; i++)
	{
		temp.coef[i] -= rhs.coef[i];
	}
	return temp;
}

// Intent: friend function operator overloading for "*"
// Pre: lhs & rhs
// Post: operator overloading for "*"
Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{
	int size = lhs.size + rhs.size - 1 < 0 ? 0 : lhs.size + rhs.size - 1;
	Polynomial temp;
	//如果有empty就直接回傳empty
	if ((lhs.size == 0 && lhs.coef[0] == 0) || (rhs.size == 0 && rhs.coef[0] == 0))
	{
		return Polynomial();
	}
	temp.coef = new double[size];
	temp.size = size;
	//歸零
	for (int i = 0; i < size; i++)
	{
		temp.coef[i] = 0;
	}
	//多項式相乘
	for (int i = 0; i < lhs.size; i++)
	{
		for (int j = 0; j < rhs.size; j++)
		{
			temp.coef[i + j] += lhs.coef[i] * rhs.coef[j];
		}
	}
	return temp;
}
