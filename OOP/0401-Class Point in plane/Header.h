// Name: 李聿鎧
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
// Intent: 設定座標 
// Pre: x跟y為int
// Post: 設定座標
void Point::set(int x, int y)
{
	pointX = x;
	pointY = y;
}
// Intent: 移動座標
// Pre: x跟y為int
// Post: 移動座標
void Point::move(int x, int y)
{
	pointX += x;
	pointY += y;
}
// Intent: 以(0,0)為中心順時針90度旋轉座標
// Pre: 無
// Post: 無
void Point::rotate()
{
	int temp;
	temp = pointX;
	pointX = pointY;
	pointY = temp * -1;
}
// Intent: 回傳x座標
// Pre: 無
// Post: 回傳x座標
int Point::retrieveVertical()
{
	return pointX;
}
// Intent: 回傳y座標
// Pre: 無
// Post: 回傳y座標
int Point::retrieveHorizontal()
{
	return pointY;
}

