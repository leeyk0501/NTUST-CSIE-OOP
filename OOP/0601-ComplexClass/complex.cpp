// Name: 李聿鎧
// Date: 2018/04/06
// Last Update: 2018/04/07
// Problem statement: C++ Homework "0601"
#include"complex.h"

// Intent: operator overloading for "=="
// Pre: 運算子兩側必需為Complex型別
// Post: 兩個Complex相等回傳TRUE，反之FALSE
bool operator ==(const Complex& complex1, const Complex& complex2)
{
	return ((complex1.real_ == complex2.real_) && (complex1.imaginary_ == complex2.imaginary_));
}

// Intent: operator overloading for "+"
// Pre: 運算子兩側為Complex或double型別
// Post: 回傳兩變數相加結果，以Complex回傳
Complex operator+(const Complex& complex1, const Complex& complex2)
{
	return (Complex(complex1.real_ + complex2.real_, complex1.imaginary_ + complex2.imaginary_));
}

// Intent: operator overloading for "-"
// Pre: 運算子兩側為Complex或double型別
// Post: 回傳兩變數相減結果，以Complex回傳
Complex operator-(Complex complex1, Complex complex2)
{
	return (Complex(complex1.real_ - complex2.real_, complex1.imaginary_ - complex2.imaginary_));
}

// Intent: operator overloading for "*"
// Pre: 運算子兩側為Complex或double型別
// Post: 回傳兩變數相乘結果，以Complex回傳
Complex operator*(const Complex& complex1, const Complex& complex2)
{
	double realValue = (complex1.real_ * complex2.real_) - (complex1.imaginary_ * complex2.imaginary_);
	double imagValue = (complex1.real_ * complex2.imaginary_) + (complex1.imaginary_ * complex2.real_);
	return (Complex(realValue, imagValue));
}

// Intent: operator overloading for "+"
// Pre: 運算子兩側為Complex或double型別
// Post: 回傳兩變數相除結果，以Complex回傳
Complex operator/(const Complex& complex1, const Complex& complex2)
{
	double denominator = (complex2.real_ * complex2.real_) + (complex2.imaginary_*complex2.imaginary_);
	double realValue = (complex1.real_ * complex2.real_) + (complex1.imaginary_ * complex2.imaginary_);
	double imagValue = (complex1.imaginary_ * complex2.real_) - (complex1.real_ * complex2.imaginary_);
	realValue /= denominator;
	imagValue /= denominator;
	return (Complex(realValue, imagValue));
}

// Intent: operator overloading for ">>"
// Pre: cout兩數
// Post: 從Complex cout兩數
ostream& operator <<(ostream& outputStream, const Complex& complex)
{
	outputStream << complex.real_ << " + " << complex.imaginary_ << "*i" << endl;
	return outputStream;
}

// Intent: operator overloading for ">>"
// Pre: cin兩數
// Post: cin兩數，放入Complex
istream& operator >>(istream& inputStream, Complex& complex)
{
	inputStream >> complex.real_ >> complex.imaginary_;
	return inputStream;
}

// Intent: 得到複數的實部
// Pre: 型態為Complex
// Post: 回傳複數的實部
double real(const Complex& complex)
{
	return complex.real_;
}

// Intent: 得到複數的虛部
// Pre: 型態為Complex
// Post: 回傳複數的虛部
double imag(const Complex& complex)
{
	return complex.imaginary_;
}

// Intent: 得到(real^2+imag^2)^0.5
// Pre: 型態為Complex
// Post: 回傳(real^2+imag^2)^0.5
double norm(const Complex& complex)
{
	return pow(pow(complex.real_, 2) + pow(complex.imaginary_, 2), 0.5);
}

// Intent: 得到複數的實部
// Pre: NULL
// Post: 回傳複數的實部
double Complex::real()
{
	return this->real_;
}

// Intent: 得到複數的虛部
// Pre: NULL
// Post: 回傳複數的虛部
double Complex::imag()
{
	return this->imaginary_;
}
