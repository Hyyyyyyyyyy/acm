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
	virtual double getArea()
	{
		return L * W;
	}
	double & getL() { return L; }
	double & getW() { return W; }
	virtual ~Shape() {}
private:
	double L;
	double W;
};
class Rectangle : public Shape
{
public:
	Rectangle() {}
	Rectangle(double a, double b) : Shape(a, b) {}
	virtual double getArea()
	{
		return getL() * getW();
	}
	virtual ~Rectangle() {}
};
class Circle : public Shape
{
public:
	Circle() {}
	Circle(double a, double b) : Shape(a, b) {}
	virtual double getArea()
	{
		return PI * getL() * getW();
	}
	virtual ~Circle() {}
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
