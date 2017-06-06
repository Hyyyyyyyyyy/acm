#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
class Shape
{
public:
	Shape() {}
	Shape(double a, double b) : L(a), W(b) {}
	double getArea()
	{
		return L * W;
	}
	double & getL() { return L; }
	double & getW() { return W; }
	~Shape() {}
private:
	double L;
	double W;
};
class Rectangle : public Shape
{
public:
	Rectangle() {}
	Rectangle(double a, double b) : Shape(a, b) {}
	~Rectangle() {}
};
class Circle : public Shape
{
public:
	Circle() {}
	Circle(double a, double b) : Shape(a, b) {}
	double getArea()
	{
		return PI * getL() * getW();
	}
	~Circle() {}
};
class Square : public Rectangle
{
public:
	Square() {}
	Square(double a, double b) : Rectangle(a, b) {}
	~Square() {}
};
int main()
{
	Shape t0(2.5, 6.4);
	Rectangle t1(2.2, 4.0);
	Circle t2(3.0, 3.0);
	Square t3(2.0, 2.0);
	cout << t0.getArea() << endl;
	cout << t1.getArea() << endl;
	cout << t2.getArea() << endl;
	cout << t3.getArea() << endl;
	return 0;
}