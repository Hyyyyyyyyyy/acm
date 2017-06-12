#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
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
		{
			if (q.imag != 1)
				o << q.real << "+" << q.imag << "i";
			else
				o << q.real << "+" << "i";
		}
		else if (q.real == 0 && q.imag != 0)
		{
			if (q.imag != 1)
				o << q.imag << "i";
			else
				o << "i";
		}
		else if (q.imag == 0 && q.real != 0)
			o << q.real;
		else
			o << "0";
	}
	else
	{
		if (q.real != 0 && q.imag != 0)
		{
			if (q.imag != -1)
				o << q.real << q.imag << "i";
			else
				o << q.real << "-i";
		}
		else if (q.real == 0 && q.imag != 0)
		{
			if (q.imag != -1)
				o << q.imag << "i";
			else
				o << "-i";
		}
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
class Matrix
{
public:
	Matrix<T>() {}
	Matrix<T>(T **a, int n, int m) : N(n), M(m)
	{
		P = new T*[n];
		for (int i = 0; i < n; i++)
		{
			P[i] = new T[m];
			for (int j = 0; j < m; j++)
			{
				P[i][j] = a[i][j];
			}
		}
	}
	Matrix<T>(const Matrix<T>& q)
	{
		P = new T*[q.N];
		for (int i = 0; i < q.N; i++)
		{
			P[i] = new T[q.M];
			for (int j = 0; j < q.M; j++)
			{
				P[i][j] = q.P[i][j];
			}
		}
		N = q.N;
		M = q.M;
	}
	T* operator [] (int n)
	{
		return P[n];
	}
	void show(ofstream& OUT);
	Matrix<T> multiply(Matrix<T>& q);
	Matrix<T> transpose();
	~Matrix()
	{
		for (int i = 0; i < N; i++)
		{
			delete[] P[i];
		}
	}
private:
	T** P;
	int N;
	int M;
};
template<class T>
void Matrix<T>::show(ofstream& OUT)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			OUT << P[i][j] << " ";
		}
		OUT << endl;
	}
}
template<class T>
Matrix<T> Matrix<T>::multiply(Matrix<T>& q)
{
	if (M != q.N)
	{
		throw 0;
	}
	T** tt = new T*[N];
	for (int i = 0; i < N; i++)
		tt[i] = new T[q.M];
	Matrix<T> t(tt, N, q.M);
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < q.M; k++)
		{
			t[i][k] = 0;
			for (int j = 0; j < M; j++)
			{
				t[i][k] += P[i][j] * q[j][k];
			}
		}
	}
	return t;
}
template<class T>
Matrix<T> Matrix<T>::transpose()
{
	T** tt = new T*[M];
	for (int i = 0; i < M; i++)
	{
		tt[i] = new T[N];
		for (int j = 0; j < N; j++)
		{
			tt[i][j] = P[j][i];
		}
	}
	return Matrix(tt, M, N);
}
int main()
{
	ofstream OUT;
	OUT.open("OUT.txt", ios_base::out);
	int a1[3] = { 1, 2, 3 };
	int a2[3] = { 3, 4, 5 };
	int* a[2] = { a1, a2 };
	Matrix<int> A(a, 2, 3);
	Matrix<int> B(A.transpose());
	OUT << "A : " << endl;
	A.show(OUT);
	OUT << "B : " << endl;
	B.show(OUT);
	OUT << "A[1][2] = " << A[1][2] << endl;
	try
	{
		Matrix<int>C = A.multiply(B);
		OUT << "A * B : " << endl;
		C.show(OUT);
	}
	catch (int)
	{
		OUT << "Can't multiply, error row and column" << endl;
	}
	catch (...)
	{
		OUT << "Can't multiply, unexpected error" << endl;
	}
	Complex a3[3] = { Complex(0, 1), Complex(1, 2), Complex(2, 3) };
	Complex a4[3] = { Complex(0, 1), Complex(1, 2), Complex(2, 3) };
	Complex* a5[2] = { a3, a4 };
	Matrix<Complex>D(a5, 2, 3);
	Matrix<Complex>E(D);
	D.show(OUT);
	E.show(OUT);
	return 0;
}