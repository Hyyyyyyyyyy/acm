#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;
class String
{
public:
	String()
	{
		ss = new char[1];
	}
	String(const char *s)
	{
		ss = new char[strlen(s) + 1];
		strcpy(ss, s);
	}
	String(const String &rhs, unsigned int pos, unsigned int n)
	{
		ss = new char[n + 1];
		strncpy(ss, rhs.ss + pos, n);
	}
	String(const char *s, unsigned int n)
	{
		ss = new char[n + 1];
		strncpy(ss, s, n);
	}
	String(unsigned int n, char c)
	{
		int i;
		ss = new char[n + 1];
		for (i = 0; i < n; i++)
			ss[i] = c;
		ss[i] = '\0';
	}
	String(const String &rhs)
	{
		ss = new char[strlen(rhs.ss) + 1];
		strcpy(ss, rhs.ss);
	}
	void addlen(int i)
	{
		if (i <= 0)
			return;
		char *sss = new char[strlen(ss) + 1];
		strcpy(sss, ss);
		delete[] ss;
		ss = new char[i + strlen(sss) + 1];
		strcpy(ss, sss);
		delete[] sss;
	}
	String operator + (const String &rhs)
	{
		char *l;
		l = new char[strlen(ss) + strlen(rhs.ss) + 1];
		strcpy(l, ss);
		strcat(l, rhs.ss);
		String t(l);
		delete[] l;
		return t;
	}
	String operator = (const String &rhs)
	{
		addlen(strlen(rhs.ss));
		return String(strcpy(ss, rhs.ss));
	}
	String operator += (const String &rhs)
	{
		addlen(strlen(rhs.ss));
		return String(strcat(ss, rhs.ss));
	}
	bool operator == (const String &rhs) const
	{
		if (!strcmp(ss, rhs.ss))
			return true;
		else
			return false;
	}
	bool operator != (const String &rhs) const
	{
		if (strcmp(ss, rhs.ss))
			return true;
		else
			return false;
	}
	bool operator < (const String &rhs) const
	{
		if (strcmp(ss, rhs.ss) < 0)
			return true;
		else
			return false;
	}
	bool operator <= (const String &rhs) const
	{
		if (strcmp(ss, rhs.ss) <= 0)
			return true;
		else
			return false;
	}
	bool operator > (const String &rhs) const
	{
		if (strcmp(ss, rhs.ss) > 0)
			return true;
		else
			return false;
	}
	bool operator >= (const String &rhs) const
	{
		if (strcmp(ss, rhs.ss) >= 0)
			return true;
		else
			return false;
	}
	char operator [] (int i)
	{
		return ss[i];
	}
	friend istream & operator >> (istream & in, const String &c);
	friend ostream & operator << (ostream & out, const String &c);
	String append(const char *s)
	{
		addlen(strlen(s));
		return String(strcat(ss, s));
	}
	String assign(const char *s)
	{
		return String(strcpy(ss, s));
	}
	int compare(const String &str) const
	{
		if (strcmp(ss, str.ss) < 0)
			return -1;
		else if (!strcmp(ss, str.ss))
			return 0;
		else
			return 1;
	}
	String insert(unsigned int p0, const  char *s)
	{
		if (p0 == 0)
		{
			char *a = new char[strlen(ss) + strlen(s) + 1];
			strcpy(a, s);
			strcat(a, ss);
			String t(a);
			delete[] a;
			return t;
		}
		else
		{
			char *a = new char[strlen(ss) + strlen(s) + 1];
			int i, j;
			strncpy(a, ss, p0);
			a[p0] = '\0';
			strcat(a, s);
			strcat(a, ss + p0);
			String t(a);
			delete[] a;
			return t;
		}
	}
	String substr(unsigned int pos, unsigned int n)
	{
		char *q = new char[strlen(ss) + 1];
		strncpy(q, ss + pos, n);
		q[n + 1] = '\0';
		String t(q);
		delete[] q;
		return t;
	}
	unsigned int find(char *str) const
	{
		char *a;
		unsigned int c = 0;
		a = strstr(ss, str);
		for (char *b = ss; b != a; b++)
			c++;
		return c;
	}
	unsigned int len() const
	{
		return strlen(ss);
	}
	void swap(String &str)
	{
		char *a = new char[strlen(ss) + strlen(str.ss) + 1];
		addlen(strlen(str.ss));
		strcpy(a, ss);
		strcpy(ss, str.ss);
		strcpy(str.ss, a);
		delete[] a;
	}
	~String() {}
private:
	char *ss;
	int nn;
	int poss;
	char cc;
};
istream & operator >> (istream & in, const String &c)
{
	in >> c.ss;
	return in;
}
ostream & operator << (ostream & out, const String &c)
{
	out << c.ss;
	return out;
}
int main()
{
	String a("12"), b("34"), t;
	int c = 2;
	char *d = "56";
	//puts(d);
	cout << "a = " << a << " b = " << b << endl;
	cout << "a+b = " << a + b << endl;
	if(a == b)
		cout << "a == b ? " << "YES"<< endl;
	else
		cout << "a == b ? " << "NO" << endl;
	a += b;
	cout << "a += b = " << a << endl;
	a = b;
	cout << "a = b " << a << endl;
	if (a < b)
		cout << "a < b ? YES\n";
	else
		cout << "a < b ? NO\n";
	cout << "a[1] = " << a[1] << endl;
	cout << "append()" << a.append(d) << endl;
	cout << "a = " << a << " b = " << b << endl;
	cout << "assign() " << a.assign(d) << endl;
	cout << "a = " << a << " b = " << b << endl;
	cout << "compare() " << a.compare(b) << endl;
	cout << "a = " << a << " b = " << b << endl;
	cout << "insert() " << a.insert(1, d) << endl;
	cout << "a = " << a << " b = " << b << endl;
	cout << "substr() " << a.substr(0, 1) << endl;
	cout << "a = " << a << " b = " << b << endl;
	cout << "find() " << a.find(d) << endl;
	cout << "len() " << a.len() << endl;
	a.swap(b);
	cout << "swap() " << "a = " << a << " b = " << b << endl;
	return 0;
}





#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;
class IntArray
{
public:
	IntArray() {}
	IntArray(int *a, int b)
	{
		buf = new int[b];
		for (int i = 0; i < b; i++)
			buf[i] = a[i];
		size = b;
	}
	IntArray(const IntArray &p)
	{
		buf = new int[p.size + 1];
		for (int i = 0; i < size; i++)
			buf[i] = p.buf[i];
		size = p.size;
	}
	int operator = (const IntArray &p)
	{
		delete[] buf;
		buf = new int[p.size];
		for (int i = 0; i < size; i++)
			buf[i] = p.buf[i];
		size = p.size;
		return 1;
	}
	int operator [] (int i)
	{
		return buf[i];
	}
	bool operator == (const IntArray &p)
	{
		if (size == p.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (buf[i] != p.buf[i])
					return false;
			}
			return true;
		}
		return false;
	}
	void Resize(int newSize)
	{
		if (newSize <= 0)
		{
			delete[] buf;
			buf = NULL;
			size = 0;
			return;
		}
		IntArray t;
		t.buf = new int[size];
		for (int i = 0; i < size; i++)
			t.buf[i] = buf[i];
		t.size = size;
		delete[] buf;
		buf = new int[newSize];
		for (int i = 0; i < t.size; i++)
			buf[i] = t.buf[i];
		for (int i = t.size; i < newSize; i++)
			buf[i] = 0;
		size = newSize;
		delete [] t.buf;
	}
	friend istream & operator >> (istream & in, IntArray & p);
	friend ostream & operator << (ostream & out, const IntArray & p);
	~IntArray() {}
private:
	int *buf;
	int size;
};
istream & operator >> (istream & in, IntArray & p)
{
	in >> p.size;
	for (int i = 0; i < p.size; i++)
		in >> p.buf[i];
	return in;
}
 ostream & operator << ( ostream & out, const IntArray &p)
{
	out << "size=" << p.size << " ";
	for (int i = 0; i < p.size; i++)
		out << p.buf[i] << " ";
	return out;
}

int main()
{
	int c[5] = { 1, 2, 3, 4, 5 };
	int d[5] = { 2, 4, 6, 8, 10 };
	IntArray a(c, 5), b(d, 5);
	cout << "a  " << a << endl << "b  " << b << endl;
	cout << "a[1] = " << a[1] << endl;
	a = b;
	cout << "a = b  " << a << endl;
	a.Resize(10);
	cout << "Resize()  " << a << endl;
	return 0;
}
