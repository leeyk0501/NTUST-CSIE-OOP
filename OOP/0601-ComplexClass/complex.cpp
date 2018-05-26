// Name: �����Z
// Date: 2018/04/06
// Last Update: 2018/04/07
// Problem statement: C++ Homework "0601"
#include"complex.h"

// Intent: operator overloading for "=="
// Pre: �B��l�ⰼ���ݬ�Complex���O
// Post: ���Complex�۵��^��TRUE�A�Ϥ�FALSE
bool operator ==(const Complex& complex1, const Complex& complex2)
{
	return ((complex1.real_ == complex2.real_) && (complex1.imaginary_ == complex2.imaginary_));
}

// Intent: operator overloading for "+"
// Pre: �B��l�ⰼ��Complex��double���O
// Post: �^�Ǩ��ܼƬۥ[���G�A�HComplex�^��
Complex operator+(const Complex& complex1, const Complex& complex2)
{
	return (Complex(complex1.real_ + complex2.real_, complex1.imaginary_ + complex2.imaginary_));
}

// Intent: operator overloading for "-"
// Pre: �B��l�ⰼ��Complex��double���O
// Post: �^�Ǩ��ܼƬ۴�G�A�HComplex�^��
Complex operator-(Complex complex1, Complex complex2)
{
	return (Complex(complex1.real_ - complex2.real_, complex1.imaginary_ - complex2.imaginary_));
}

// Intent: operator overloading for "*"
// Pre: �B��l�ⰼ��Complex��double���O
// Post: �^�Ǩ��ܼƬۭ����G�A�HComplex�^��
Complex operator*(const Complex& complex1, const Complex& complex2)
{
	double realValue = (complex1.real_ * complex2.real_) - (complex1.imaginary_ * complex2.imaginary_);
	double imagValue = (complex1.real_ * complex2.imaginary_) + (complex1.imaginary_ * complex2.real_);
	return (Complex(realValue, imagValue));
}

// Intent: operator overloading for "+"
// Pre: �B��l�ⰼ��Complex��double���O
// Post: �^�Ǩ��ܼƬ۰����G�A�HComplex�^��
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
// Pre: cout���
// Post: �qComplex cout���
ostream& operator <<(ostream& outputStream, const Complex& complex)
{
	outputStream << complex.real_ << " + " << complex.imaginary_ << "*i" << endl;
	return outputStream;
}

// Intent: operator overloading for ">>"
// Pre: cin���
// Post: cin��ơA��JComplex
istream& operator >>(istream& inputStream, Complex& complex)
{
	inputStream >> complex.real_ >> complex.imaginary_;
	return inputStream;
}

// Intent: �o��Ƽƪ��곡
// Pre: ���A��Complex
// Post: �^�ǽƼƪ��곡
double real(const Complex& complex)
{
	return complex.real_;
}

// Intent: �o��Ƽƪ��곡
// Pre: ���A��Complex
// Post: �^�ǽƼƪ��곡
double imag(const Complex& complex)
{
	return complex.imaginary_;
}

// Intent: �o��(real^2+imag^2)^0.5
// Pre: ���A��Complex
// Post: �^��(real^2+imag^2)^0.5
double norm(const Complex& complex)
{
	return pow(pow(complex.real_, 2) + pow(complex.imaginary_, 2), 0.5);
}

// Intent: �o��Ƽƪ��곡
// Pre: NULL
// Post: �^�ǽƼƪ��곡
double Complex::real()
{
	return this->real_;
}

// Intent: �o��Ƽƪ��곡
// Pre: NULL
// Post: �^�ǽƼƪ��곡
double Complex::imag()
{
	return this->imaginary_;
}
