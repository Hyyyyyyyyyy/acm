#include <cstdio>
#include <iostream>
#include <istream>
#include <fstream>
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
	virtual void input() = 0;
	virtual double area() = 0;
	virtual void show() = 0;
	virtual ~Shape() {}
protected:
	double L;
	double W;
};
class Rectangle : public Shape
{
public:
	Rectangle() : Shape() {}
	Rectangle(double a, double b) : Shape(a, b) {}
	virtual void input()
	{
		cout << "Please input 2 double numbers : " << endl;
		cin >> L >> W;
	}
	virtual double area()
	{
		return L * W;
	}
	virtual void show()
	{
		cout << "L = " << L << "  W = " << W << "  S = " << area() << endl;
	}
	virtual ~Rectangle() {}
};
class Circle : public Shape
{
public:
	Circle() : Shape() {}
	Circle(double a, double b) : Shape(a, b) {}
	virtual void input()
	{
		cout << "Please input 1 double number\n";
		cin >> L;
	}
	virtual double area()
	{
		return PI * L * L;
	}
	virtual void show()
	{
		cout << "L = " << L << "  S = " << area() << endl;
	}
	virtual ~Circle() {}
};
class Square : public Shape
{
public:
	Square() : Shape() {}
	Square(double a, double b) : Shape(a, b) {}
	virtual void input()
	{
		cout << "Please input 1 double number:\n";
		cin >> L;
	}
	virtual double area()
	{
		return L * L;
	}
	virtual void show()
	{
		cout << "L = " << L << "  S = "<< area() << endl;
	}
	~Square() {}
};
int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	Rectangle p1;
	Circle p2;
	Square p3;
	Shape* p[3] = { &p1, &p2, &p3 };
	for (int i = 0; i < 3; i++)
	{
		p[i]->input();
	}
	double S = 0.0;
	for (int i = 0; i < 3; i++)
	{
		p[i]->show();
		S += p[i]->area();
	}
	cout << S << endl;
	return 0;
}


#include <cstdio>
#include <iostream>
using namespace std;
class BaseClass
{
public:
	virtual ~BaseClass() {
		cout << "BaseClass destruction\n";
	}
};
class DerivedClass : public BaseClass
{
public:
	DerivedClass()  {
		p = new int[10];
	}
	virtual ~DerivedClass() {
		cout << "DerivedClass destruction\n";
		delete[] p;
	}
private:
	int *p;
};
int main()
{
	DerivedClass *a = new DerivedClass;
	BaseClass *t = a;
	delete a;
	return 0;
}
B B A D A C A B\C C B
二
1\
A Constructorl
B Constructor2
x1=12
x2=2
2\
derived fun1
Derived fun2
base fun3
base fun4
3\
This is a head
This is a body
This is a footer
This is my header
This is a body
This is my footer
4\
A default constructor
A constructor,num=2
A destructor,num=2
Exiting main
A destructor,num=2
5\
三
1\
new Derived;
virtual ~Base()
2\
virtual void display() = 0;
A *p
3\
Rectangle(2)
Rectangle::show();
4\
virtual void area() = 0;
Shape &r
5\
Person(s)
Person::display();
