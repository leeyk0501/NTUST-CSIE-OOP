// Name: ßı¶÷ÒZ
// Date: 2018/04/02
// Last Update: 2018/04/04
// Problem statement: C++ Homework "0501"
#include "Header.h"

//----main function start----
int main(void)
{
	HotDogStand stand1("Stand1", 0);
	HotDogStand stand2("Stand2", 100);
	HotDogStand stand3("Stand3");
	stand1.justSold();
	stand2.justSold();
	stand3.justSold();
	stand1.print();
	stand2.print();
	stand3.print();
	std::cout << "Total Sold : " << HotDogStand::allStandsoldAmount() << std::endl;
	return 0;
}