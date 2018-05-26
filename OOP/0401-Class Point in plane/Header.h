// Name: �����Z
// Date: March 27, 2018
// Last Update: March 27, 2018
// Problem statement: C++ Homework "0401 - Class Point in plane"
#include<iostream>
using namespace std;
class Point
{
public:
	void set(int, int);
	void move(int, int);
	void rotate();
	int retrieveVertical();
	int retrieveHorizontal();
private:
	int pointX;
	int pointY;
};
// Intent: �]�w�y�� 
// Pre: x��y��int
// Post: �]�w�y��
void Point::set(int x, int y)
{
	pointX = x;
	pointY = y;
}
// Intent: ���ʮy��
// Pre: x��y��int
// Post: ���ʮy��
void Point::move(int x, int y)
{
	pointX += x;
	pointY += y;
}
// Intent: �H(0,0)�����߶��ɰw90�ױ���y��
// Pre: �L
// Post: �L
void Point::rotate()
{
	int temp;
	temp = pointX;
	pointX = pointY;
	pointY = temp * -1;
}
// Intent: �^��x�y��
// Pre: �L
// Post: �^��x�y��
int Point::retrieveVertical()
{
	return pointX;
}
// Intent: �^��y�y��
// Pre: �L
// Post: �^��y�y��
int Point::retrieveHorizontal()
{
	return pointY;
}

