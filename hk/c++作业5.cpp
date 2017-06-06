#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
	Complex(const Complex &p)
	{
		real = p.real;
		imag = p.imag;
	}
	Complex operator + (const Complex &q) const
	{
		return Complex(real + q.real, imag + q.imag);
	}
	Complex operator - (const Complex &q) const
	{
		return Complex(real - q.real, imag - q.imag);
	}
	Complex operator * (const Complex &q) const
	{
		return Complex(real*q.real - imag*q.imag, real*q.imag + imag*q.real);
	}
	Complex operator / (const Complex &q) const
	{
		return Complex((real*q.real + imag*q.imag) / (q.real*q.real + q.imag*q.imag), (imag*q.real - real*q.imag) / (q.real*q.real + q.imag*q.imag));
	}
	Complex operator + (const double a) const
	{
		return Complex(real + a, imag);
	}
	Complex operator - (const double a) const
	{
		return Complex(real - a, imag);
	}
	Complex operator * (const double a) const
	{
		return Complex(real*a, imag*a);
	}
	Complex operator / (const double a) const
	{
		return Complex(real / a, imag / a);
	}
	friend Complex operator + (double a, Complex &q);
	friend Complex operator - (double a, Complex &q);
	friend Complex operator * (double a, Complex &q);
	friend Complex operator / (double a, Complex &q);
	bool operator == (const Complex &q) const
	{
		return (real == q.real && imag == q.imag);
	}
	bool operator != (const Complex &q) const
	{
		return !(real == q.real && imag == q.imag);
	}
	bool operator > (const Complex &q) const
	{
		return (real*real + imag*imag > q.real*q.real + q.imag*q.imag);
	}
	bool operator < (const Complex &q) const
	{
		return (real*real + imag*imag < q.real*q.real + q.imag*q.imag);
	}
	bool operator >= (const Complex &q) const
	{
		return (real*real + imag*imag >= q.real*q.real + q.imag*q.imag);
	}
	bool operator <= (const Complex &q) const
	{
		return (real*real + imag*imag <= q.real*q.real + q.imag*q.imag);
	}
	Complex operator - () const
	{
		return Complex((-1.0*real), (-1.0)*imag);
	}
	Complex operator ++ () const
	{
		return Complex(real + 1, imag + 1);
	}
	Complex operator -- () const
	{
		return Complex(real - 1, imag - 1);
	}
	Complex operator ++ (int a)
	{
		Complex temp(real, imag);
		real += 1;
		imag += 1;
		return temp;
	}
	Complex operator -- (int a)
	{
		Complex temp(real, imag);
		real -= 1;
		imag -= 1;
		return temp;
	}

	friend ostream & operator << (ostream &o, Complex &q);
	friend istream & operator >> (istream &i, Complex &q);
	~Complex() {}
private:
	double real;
	double imag;
};
Complex operator + (double a, Complex &q)
{
	return Complex(a + q.real, q.imag);
}
Complex operator - (double a, Complex &q)
{
	return Complex(a - q.real, q.imag);
}
Complex operator * (double a, Complex &q)
{
	return Complex(a*q.real, a*q.imag);
}
Complex operator / (double a, Complex &q)
{
	return Complex((a*q.real) / (q.real*q.real + q.imag*q.imag), -(a*q.imag) / (q.real*q.real + q.imag*q.imag));
}
ostream & operator << (ostream &o, Complex &q)
{
	if (q.imag >= 0)
	{
		if (q.real != 0 && q.imag != 0)
			o << q.real << "+" << q.imag << "i";
		else if (q.real == 0 && q.imag != 0)
			o << q.imag << "i";
		else if (q.imag == 0 && q.real != 0)
			o << q.real;
		else
			o << "0";
	}
	else
	{
		if (q.real != 0 && q.imag != 0)
			o << q.real << q.imag << "i";
		else if (q.real == 0 && q.imag != 0)
			o << q.imag << "i";
		else if (q.imag == 0 && q.real != 0)
			o << q.real;
		else
			o << "0";
	}
	return o;
}
istream & operator >> (istream &i, Complex &q)
{
	char ch1, ch2;
	i >> q.real >> ch1 >> q.imag >> ch2;
	return i;
}

int main()
{
	int i, j, k, n, m;
	double a, b, c;
	Complex x;
	Complex y;
	cout << "Please input two real numbers" << endl;
	cin >> a >> i;
	cout << "Please input two Complexs(like  a+bi)" << endl;
	cin >> x >> y;
	cout << "Now, let's see some computation" << endl;
	cout << fixed;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x + y = " << x + y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "x * y = " << x * y << endl;
	cout << "x / y = " << x / y << endl;
	cout << "x * a = " << x * a << endl;
	cout << "x / a = " << x / a << endl;
	cout << "a * x = " << a * x << endl;
	cout << "a / x = " << a / x << endl;
	cout << "x + a = " << x + a << endl;
	cout << "a / x = " << a / x << endl;
	cout << "y + i = " << y + i << endl;
	cout << "y * i = " << y * i << endl;
	x++;
	y--;
	cout << "x++ = " << x << endl;
	cout << "y-- = " << y << endl;
	cout << "-y = " << -y << endl;
	return 0;
}
