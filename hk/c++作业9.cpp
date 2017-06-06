#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
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
	double Val()
	{
		return sqrt(real*real + imag*imag);
	}
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
	friend ostream & operator << (ostream &o, Complex &q);
	friend istream & operator >> (istream &i, Complex &q);
	~Complex() {}
private:
	double real;
	double imag;
};
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
template<class T>
void PickSort(T *ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (ar[j] < ar[j-1])
			{
				T temp;
				temp = ar[j];
				ar[j] = ar[j - 1];
				ar[j - 1] = temp;
			}
		}
	}
}
int main()
{
	int a[] = { 61,651654,5465,5465,231,7,7,561,7845,1259,-45,-231,-78451 };
	Complex b[] = { Complex(1,2), Complex(2,8), Complex(-4 , 1), Complex(6 , 9), Complex(-7 ,-5) };
	PickSort(a, 13);
	PickSort(b, 5);
	for (int i = 0; i < 13; i++)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}




#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
template<class T>
class Set
{
public:
	Set() {
		size = 0;
		ar = new T[10];
		for (int i = 0; i < 10; i++)
			ar[i] = 0;
	}
	Set(T* a, int b)
	{
		ar = new T[b + 1];
		for (int i = 0; i < b; i++)
			ar[i] = a[i];
		size = b;
	}
	Set<T>(const Set<T>& p)
	{
			ar = new T[p.size + 1];
			for (int i = 0; i < p.size; i++)
				ar[i] = p.ar[i];
			size = p.size;
	}
	void Addlen(int n);
	void Show();
	void Add(const T a);
	void Del(const T a);
	Set<T> operator && (const Set<T>& p);
	Set<T> operator || (const Set<T>& p);
	Set<T> operator - (const Set<T>& p);
	void operator = (const Set<T>& p);
	bool Belong(const Set<T>& p);
	friend bool operator == (Set<T>& p, Set<T>& q)
	{
		if (q.Belong(p) && p.Belong(q))
			return true;
		return false;
	}
	~Set() {
		delete[] ar;
	}
private:
	int size;
	T *ar;
};
template<class T>
void Set<T>::Addlen(int n)
{
	T *q = new T[n + 1];
	for (int i = 0; i < size; i++)
		q[i] = ar[i];
	delete[] ar;
	ar = new T[n + 1];
	for (int i = 0; i < size; i++)
		ar[i] = q[i];
	delete[] q;
}
template<class T>
void Set<T>::Show()
{
	cout << "size = " << size << endl;
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
}
template<class T>
void Set<T>::Add(const T a)
{
	int i, j;
	for (i = 0; i < size; i++)
		if (ar[i] == a)
			return;
	Addlen(size + 1);
	ar[size] = a;
	size++;
}
template<class T>
void Set<T>::Del(const T a)
{
	int i, j;
	for (i = 0; i < size; i++)
		if (ar[i] == a)
			break;
	if (i != size)
	{
		for (j = i; j < size; j++)
			ar[j] = ar[j + 1];
		size--;
	}
}
template<class T>
Set<T> Set<T>::operator && (const Set<T>& p)
{
	int i, j;
	T *q = new T[size + p.size + 1];
	int cnt = 0;
	for (i = 0; i < p.size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (ar[j] == p.ar[i])
				break;
		}
		if (j != size)
			q[cnt++] = p.ar[i];
	}
	Set<T>temp(q, cnt);
	return temp;
}
template<class T>
Set<T> Set<T>::operator || (const Set<T>& p)
{
	int i, j;
	T *q = new T[size + p.size + 1];
	int cnt = size;
	for (i = 0; i < size; i++)
		q[i] = ar[i];
	for (i = 0; i < p.size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (ar[j] == p.ar[i])
				break;
		}
		if (j == size)
			q[cnt++] = p.ar[i];
	}
	Set<T>temp(q, cnt);
	return temp;
}
template<class T>
Set<T> Set<T>::operator - (const Set<T>& p)
{
	int i, j;
	T *q = new T[size + 1];
	int cnt = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < p.size; j++)
		{
			if (ar[j] == p.ar[i])
				break;
		}
		if (j == size)
			q[cnt++] = ar[i];
	}
	Set<T>temp(q, cnt);
	return temp;
}
template<class T>
void Set<T>::operator = (const Set<T>& p)
{
	if (size != p.size)
	{
		delete[] ar;
		size = p.size;
		ar = new T[size + 1];
		for (int i = 0; i < size; i++)
			ar[i] = p.ar[i];
	}
	else
	{
		for (int i = 0; i < size; i++)
			ar[i] = p.ar[i];
	}
}
template<class T>
bool Set<T>::Belong(const Set<T>& p)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < p.size; j++)
		{
			if (ar[i] == p.ar[j])
				break;
		}
		if (j == p.size)
			return false;
	}
	return true;
}

int main()
{
	int ar[9] = { 1, 3, 2, 4, 5, 9, 6, 8, 7 };
	int sa[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sf[3] = { 0, 8, 6 };
	Set<int>a(ar, 9);
	Set<int>b(sf, 3);
	Set<int>c(sa, 9);
	Set<int>d;
	if (a == b)
		cout << "a == b" << endl;
	else
		cout << "a != b" << endl;
	a.Add(10);
	a.Show();
	c.Del(9);
	c.Show();
	d = a && c;
	d.Show();
	d = a || c;
	d.Show();
	d = a - b;
	d.Show();
	return 0;
}