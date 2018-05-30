// Name: �����Z
// Date: March 29, 2018
// Last Update: March 29, 2018
// Problem statement: C++ Homework "0501"
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Rectangle //�x��
{
	double x1, y1, x2, y2;
};
struct Circle //���
{
	double x, y, r;
};
struct Figure //�ϧ�(�t�x�λP���)
{
	int type; //0:Rectangle 1:Circle
	Rectangle rectangle;
	Circle circle;
};
struct Point //�y��
{
	double x, y;
};
vector<Figure> fig;
vector<Point> point;

// Intent: ��J�ϧήy�и�ơA�P�_��Ƭ��x�Ωζ��
// Pre: �L
// Post: ��J��ƦܦW��fig��vector
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
// Intent: ��J�ϧήy�и�ơA�P�_��Ƭ��x�Ωζ��
// Pre: �L
// Post: ��J��ƦܦW��fig��vector
void inputPoint()
{
	Point tempPoint;
	cin >> tempPoint.x;
	cin >> tempPoint.y;
	point.push_back(tempPoint);
}
// Intent: ��J��y�СA�^�Ǩ��I�Z��
// Pre: �|�ӿ�J��ƬҬ�double
// Post: �^�Ǩ��I�Z��
double twoPointLength(double x1, double y1, double x2, double y2) 
{
	double length = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
	length = sqrt(length);
	return length;
}
// Intent: �P�_p�O�_����start�Pend����
// Pre: �T�ӿ�J�ȬҬ�double
// Post: �p�Gp�bstart�Pend�����A�^��true�A�Ϥ��^��false
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
// Intent: �P�_�I�O�_�b�x�Τ�
// Pre:p�Ptect���o���ŭ�
// Post: �p�G�I�b�x�Τ�(�t��u)�A�^��true�A�Ϥ���false
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
// Intent: �P�_�I�O�_�b��Τ�
// Pre:p�Pcir���o���ŭ�
// Post: �p�G�I�b��Τ�(�t��u)�A�^��true�A�Ϥ���false
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
// Intent: �P�_point�O�_�bfigure�̭�
// Pre: �����ܼ�fig,point�Ҧܤ֭n���@�����
// Post: �p�Gpoint�bfigure���A��X�ӵ��G�A�p�G�S���b����ϧΤ��A��X�L���G
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
			//��J�ϧθ��
			inputFigure();
		}

		cin >> pointN;
		for (int i = 0; i < pointN; i++)
		{
			//��J�I���
			inputPoint();
		}

		for (int i = 0; i < pointN; i++)
		{
			//�P�_�C�I�O�_�b�Ҧ����ϧΤ�
			whereIsPoint(figureN, i);
		}
	}
	return 0;
}