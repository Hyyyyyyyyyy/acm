#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-8;
const ll MOD = 100000007ll;
const int maxn = 400 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	double x;
	double y;
	Node() {}
	Node(double a, double b) : x(a), y(b) {}
	Node(const Node& p)
	{
		x = p.x;
		y = p.y;
	}
};

double Length(Node A, Node B)               //两点距离
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}
double Angle(Node A, Node B, Node C)        //求最后一个参数点对应的角
{
	double a = Length(B, C);
	double b = Length(A, C);
	double c = Length(A, B);
	return acos((a*a + b*b - c*c) / (2.0 * a * b));
}
struct Triangle
{
	Node A;
	Node B;
	Node C;
	Triangle() {}
	Triangle(Node a, Node b, Node c) : A(a), B(b), C(c) {}
	bool IS()                           //判断是否是三角形
	{
		double a = Length(B, C);
		double b = Length(A, C);
		double c = Length(A, B);
		if (a + b > c && b + c > a && a + c > b)
			return true;
		else
			return false;
	}
};
bool XS(Triangle P, Triangle Q)         //判断两个三角形相似
{
	double a1 = Length(P.B, P.C);
	double b1 = Length(P.A, P.C);
	double c1 = Length(P.A, P.B);
	if (a1 > b1)
		swap(a1, b1);
	if (a1 > c1)
		swap(a1, c1);
	if (b1 > c1)
		swap(b1, c1);
	double a2 = Length(Q.B, Q.C);
	double b2 = Length(Q.A, Q.C);
	double c2 = Length(Q.A, Q.B);
	if (a2 > b2)
		swap(a2, b2);
	if (a2 > c2)
		swap(a2, c2);
	if (b2 > c2)
		swap(b2, c2);
	if (fabs(a1 * b2 - a2 * b1) < eps && fabs(a1 * c2 - a2 * c1) < eps && fabs(b1 * c2 - b2 * c1) < eps)
		return true;
	return false;
}
