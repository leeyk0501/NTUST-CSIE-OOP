// Name: ßı¶÷ÒZ
// Date: March 27, 2018
// Last Update: March 27, 2018
// Problem statement: C++ Homework "0401 - Class Point in plane"
#include "Header.h"
int main(void) 
{
	Point point;

	point.set(0, 5);
	cout << point.retrieveVertical() << " " << point.retrieveHorizontal() << endl;
	
	point.move(1, 2);
	cout << point.retrieveVertical() << " " << point.retrieveHorizontal() << endl;
	for (int i = 0; i < 4; i++) 
	{
		point.rotate();
		cout << point.retrieveVertical() << " " << point.retrieveHorizontal() << endl;
	}
	
	return 0;
}