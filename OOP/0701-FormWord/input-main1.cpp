// Name: �����Z
// Date: 2018/04/16
// Last Update: 2018/04/16
// Problem statement: C++ Homework "0701"
#include "Form.h"
//FormWord-inputmain1.cpp

int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING");//�]�wInput
	form1.ProcessInputWord();//�B�zInput��T
	form1.SetFileName("word.txt");//�]�w�ɮצW��
	form1.Load_CompaerWord();//Ū�ɨåB���
	form1.PrintFoundWords();//�L�X�ŦX���r
	return 0;
}