// Name: �����Z
// Date: 20180508
// Last Update: 20180508
// Problem statement: C++ Homework "0902-CopyCat"
#include<iostream>
#include<fstream>
using namespace std;
//�`�N:�Х�cmd����exe
int main(int argc, char *argv[])
{
	ifstream input(argv[1], ios::binary);
	ofstream output(argv[2], ios::binary);
	output << input.rdbuf(); //�ɮ׽ƻs��output
	return 0;
}