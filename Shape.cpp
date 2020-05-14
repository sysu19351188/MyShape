#include "shape.h"
#include "shape.h"
#include<iostream>
#include<math.h>
#include<vector>


using namespace std;


void Circle::Print()
{
	cout << "圆心坐标是："; center_.Print();
	cout << "半径是：" << radius_ << endl;
	cout << "圆周长是：" << Circumference() << endl;
	cout << "圆面积是：" << Area() << endl << endl;
}

Shape& operator &(Shape& s1, Shape& s2)
{
	Polygon& p1 = dynamic_cast<Polygon&>(s1);
	Polygon& p2 = dynamic_cast<Polygon&>(s2);
	if (&p1 != 0 && (&p2 != 0))
	{
		if (&p1 == &p2)
			return p1;
		else return s2;
	}
	else
	{
		Circle& p3 = dynamic_cast<Circle&>(s1);
		Circle& p4 = dynamic_cast<Circle&>(s1);
		if (&p3 == &p4)
			return p3;
		else return s2;
	}
}

Shape& operator |(Shape& s1, Shape& s2)
{
	Oval a;
	double x1, y1;
	Polygon& p1 = dynamic_cast<Polygon&>(s1);
	Polygon& p2 = dynamic_cast<Polygon&>(s2);
	if (&p1 != 0 && (&p2 != 0))
	{
		if (&p1 == &p2)
			return p1;
		else return s2;
	}
	else
	{
		Circle& p3 = dynamic_cast<Circle&>(s1);
		Circle& p4 = dynamic_cast<Circle&>(s1);
		if (&p3 == &p4)
			return p3;
		else
		{
			x1 = (p3.Center().Print_x() + p4.Center().Print_x()) / 2;
			y1 = (p3.Center().Print_y() + p4.Center().Print_y()) / 2;
			a.initOval(x1, y1);
			return a;
		}
	}
}

double Edge::Length()
{
	double x, y;
	x = p1.Print_x() - p2.Print_x();
	y = p1.Print_y() - p2.Print_y();
	return sqrt(x * x + y * y);
}

Polygon::Polygon()
{
	Edge e;
	edges_[0] = e;
}


double Polygon::Circumference()
{
	int s = size(edges_), i;
	double sum = 0;
	for (i = 0; i < s; i++)
		sum = sum + edges_[i].Length();
	return sum;
}

void Polygon::Print()
{

	int s = size(edges_), i;
	cout << "该多边形的信息如下：" << endl;
	for (i = 0; i < s; i++)
	{
		cout << "第" << i + 1 << "条边的信息：" << endl;
		edges_[i].Print_p1();
		edges_[i].Print_p2();
		edges_[i].Print_Length();
	}
	cout << "多边形周长是：" << Circumference() << endl;
	cout << "多边形面积是：" << Area() << endl << endl;
}

void Polygon::initPolygon(Point a, Point b, Point c)
{
	Edge e[3];
	e[0].initEdge(a, b);
	edges_[0] = e[0];
	e[1].initEdge(a, c);
	edges_[1] = e[1];
	e[2].initEdge(b, c);
	edges_[2] = e[2];
}

void Polygon::initPolygon(Point a, Point b, Point c, Point d)
{
	Edge ed[4];
	ed[0].initEdge(a, b);
	edges_[0] = ed[0];
	ed[1].initEdge(b, c);
	edges_[1] = ed[1];
	ed[2].initEdge(c, d);
	edges_[2] = ed[2];
	ed[3].initEdge(a, d);
	edges_[3] = ed[3];
}
