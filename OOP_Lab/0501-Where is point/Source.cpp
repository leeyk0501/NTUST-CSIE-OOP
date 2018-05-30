// Name: 李聿鎧
// Date: March 29, 2018
// Last Update: March 29, 2018
// Problem statement: C++ Homework "0501"
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Rectangle //矩形
{
	double x1, y1, x2, y2;
};
struct Circle //圓形
{
	double x, y, r;
};
struct Figure //圖形(含矩形與圓形)
{
	int type; //0:Rectangle 1:Circle
	Rectangle rectangle;
	Circle circle;
};
struct Point //座標
{
	double x, y;
};
vector<Figure> fig;
vector<Point> point;

// Intent: 輸入圖形座標資料，判斷資料為矩形或圓形
// Pre: 無
// Post: 輸入資料至名為fig的vector
void inputFigure()
{
	Figure tempFig;
	char c;
	cin >> c;
	if (c == 'r')
	{
		tempFig.type = 0;
		cin >> tempFig.rectangle.x1;
		cin >> tempFig.rectangle.y1;
		cin >> tempFig.rectangle.x2;
		cin >> tempFig.rectangle.y2;
	}
	else if (c == 'c') 
	{
		tempFig.type = 1;
		cin >> tempFig.circle.x;
		cin >> tempFig.circle.y;
		cin >> tempFig.circle.r;
	}
	fig.push_back(tempFig);
}
// Intent: 輸入圖形座標資料，判斷資料為矩形或圓形
// Pre: 無
// Post: 輸入資料至名為fig的vector
void inputPoint()
{
	Point tempPoint;
	cin >> tempPoint.x;
	cin >> tempPoint.y;
	point.push_back(tempPoint);
}
// Intent: 輸入兩座標，回傳兩點距離
// Pre: 四個輸入資料皆為double
// Post: 回傳兩點距離
double twoPointLength(double x1, double y1, double x2, double y2) 
{
	double length = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
	length = sqrt(length);
	return length;
}
// Intent: 判斷p是否介於start與end之間
// Pre: 三個輸入值皆為double
// Post: 如果p在start與end之間，回傳true，反之回傳false
bool pointInLine(double start, double end, double p)
{
	if (start > end)
	{
		double temp;
		temp = start;
		start = end;
		end = temp;
	}
	if (start <= p && end >= p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Intent: 判斷點是否在矩形中
// Pre:p與tect不得為空值
// Post: 如果點在矩形中(含邊線)，回傳true，反之為false
bool pointInRectangle(Point p, Rectangle rect)
{
	if (pointInLine(rect.x1, rect.x2, p.x) && pointInLine(rect.y1, rect.y2, p.y)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Intent: 判斷點是否在圓形中
// Pre:p與cir不得為空值
// Post: 如果點在圓形中(含邊線)，回傳true，反之為false
bool pointInCircle(Point p, Circle cir) 
{
	if (twoPointLength(p.x, p.y, cir.x, cir.y) <= cir.r) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Intent: 判斷point是否在figure裡面
// Pre: 全域變數fig,point皆至少要有一筆資料
// Post: 如果point在figure中，輸出該結果，如果沒有在任何圖形中，輸出無結果
void whereIsPoint(int figureN, int pointIndex) 
{
	bool notContained = true;
	Point p = point[pointIndex];
	for (int i = 0; i < figureN; i++)
	{
		if (fig[i].type == 0) //Rectangle
		{
			Rectangle rect = fig[i].rectangle;
			if (pointInRectangle(p, rect))
			{
				cout << "Point (" << p.x << ", " << p.y << ") is contained in figure " << i + 1 << endl;
				notContained = false;
			}
		}
		else //Circle
		{
			Circle cir = fig[i].circle;
			if (pointInCircle(p, cir))
			{
				cout << "Point (" << p.x << ", " << p.y << ") is contained in figure " << i + 1 << endl;
				notContained = false;
			}
		}
	}
	if (notContained)
	{
		cout << "Point (" << p.x << ", " << p.y << ") is not contained in any figure" << endl;
	}
}
int main()
{
	int figureN, pointN;
	
	while (cin >> figureN)
	{
		fig.clear();
		point.clear();

		for (int i = 0; i < figureN; i++)
		{
			//輸入圖形資料
			inputFigure();
		}

		cin >> pointN;
		for (int i = 0; i < pointN; i++)
		{
			//輸入點資料
			inputPoint();
		}

		for (int i = 0; i < pointN; i++)
		{
			//判斷每點是否在所有的圖形中
			whereIsPoint(figureN, i);
		}
	}
	return 0;
}