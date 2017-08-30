#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;

const double PI = acos(-1.0);
int sgn(double x)
{
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	else return 1;
}
struct Point
{
	double x, y;
	Point() {}
	Point(double _x, double _y)
	{
		x = _x; y = _y;
    }
    Point operator + (const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }
	Point operator - (const Point &b) const
	{
		return Point(x - b.x, y - b.y);
	}

	double operator ^ (const Point &b) const
	{
		return x*b.y - y*b.x;
	}

	double operator * (const Point &b) const
	{
		return x*b.x + y*b.y;
	}

	void transXY(double B)
	{
		double tx = x, ty = y;
		x = tx* cos(B) - ty*sin(B);
		y = tx* sin(B) + ty*cos(B);
	}
};

double dist(Point a, Point b)
{
	return sqrt((a - b)*(a - b));
}

double getS(Point c1, double r1, Point c2, double r2)
{
	double d = dist(c1, c2);
	if (r1 + r2 < d + eps) return 0;
	if (d < fabs(r1 - r2) + eps)
	{
		double r = min(r1, r2);
		return PI*r*r;
	}
	double x = (d*d + r1*r1 - r2*r2) / (2 * d);
	double t1 = acos(x / r1);
	double t2 = acos((d - x) / r2);
	return r1*r1*t1 + r2*r2*t2 - d*r1*sin(t1);
}
int main()
{
	int i, j, n, m;
	double r, R, xa, ya, xb, yb;
	Point c1, c2;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lf %lf", &r, &R);
			scanf("%lf %lf %lf %lf", &xa, &ya, &xb, &yb);
			c1.x = xa;
			c1.y = ya;
			c2.x = xb;
			c2.y = yb;
			printf("Case #%d: ", m);
			printf("%.6f\n", getS(c1, R, c2, R) - 2.0*getS(c1, r, c2, R) + getS(c1, r, c2, r));
		}
	}
	return 0;
}
