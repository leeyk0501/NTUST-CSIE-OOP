// Name: ßı¶÷ÒZ
// Date: 2018/04/02
// Last Update: 2018/04/04
// Problem statement: C++ Homework "0501"
#include<iostream>
#include<string>
using namespace std;

//test HotDogStand Class
class HotDogStand
{
public:
	HotDogStand(string setName, int setSold) :name(setName), sold(setSold)
	{
		totalSold += setSold;
	}
	HotDogStand(string setName) :name(setName), sold(0) {}
	static int allStandsoldAmount();
	void justSold();
	void print();
	int thisStandSoldAmount();
private:
	static int totalSold;
	string name;
	int sold;
};

