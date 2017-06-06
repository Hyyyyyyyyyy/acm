#include <cstdio>
#include <iostream>
using namespace std;

class Square
{
	double len;
	double wid;
public:
	Square() {};
	Square(double l, double w = 0) : len(l), wid(w) {};
	double acreage()
	{
		return len * wid;
	}

	~Square() {};
};

int main()
{
	double n, m, area;
	cout << "Please enter the length and width\n";
	cin >> n >> m;
	Square square(n, m);
	cout << "area = " << square.acreage() << endl;
	return 0;
}
