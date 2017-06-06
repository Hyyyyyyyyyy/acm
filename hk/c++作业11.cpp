#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;
const int maxn = 10;
const double eps = 1.0e-10;
class Fract
{
public:
	Fract() {}
	Fract(int a, int b) : num(a), den(b) {}
	double Val() const
	{
		return (double)num / (double)den;
	}
	bool operator == (const Fract& a)
	{
		return num == a.num && den == a.den;
	}
	friend class com;
	//friend bool com(const Fract& a);
	friend istream& operator >> (istream& in, Fract& a);
	friend ostream& operator << (ostream& out, Fract& a);
	~Fract() {}
private:
	int num;    //分子；
	int den;    //分母；
};
istream& operator >> (istream& in, Fract& a)
{
	in >> a.num >> a.den;
	return in;
}
ostream& operator << (ostream& out, Fract& a)
{
	out << a.num << "/" << a.den;
	return out;
}
bool comp(const Fract& a, const Fract& b)
{
	return a.Val() < b.Val();
}
class com
{
public:
	bool operator () (const Fract& a)
	{
		return a.Val() < 1.0;
	}
};
//bool com (const Fract& a)
//{
//	return a.Val() < 1.0;
//}
int main()
{
	int i, j;
	//freopen("IN.txt", "r", stdin);
	Fract x;
	vector<Fract>G;
	G.clear();
	vector<Fract>::iterator it;
	cout << "Please input 10 fracts\n";
	for (i = 0; i < maxn; i++)
	{
		cin >> x;
		G.push_back(x);
	}
	sort(G.begin(), G.end(), comp);
	for (it = G.begin(); it != G.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "Please input a fract to find: ";
	cin >> x;
	it = find(G.begin(), G.end(), x);
	if (it == G.end())
		cout << "NO\n";
	else
		cout << *it << endl;
	cout << "How many fracts < 1.0:\n";
	cout << count_if(G.begin(), G.end(), com()) << endl;
	return 0;
}
