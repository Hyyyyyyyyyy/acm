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
#include <stack>
#include <deque>
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
#define retrun return
const double inf = 1e8;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
int a, b, c, d;
double solve(int d1, int d2, int y1, int y2)
{
	int x = abs(d1 - d2);
	if (x + y1 <= y2 || x + y2 <= y1 || y1 + y2 <= x)
		return -inf;
	double C = ((double)y1 + (double)y2 + (double)x) / 2.0;
	double S = sqrt(C * (C - (double)y1) * (C - (double)y2) * (C - (double)x));
	double h = S / x;
	return ((double)d1 + (double)d2) * h;
}
int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			double res = -1.0;
			res = max(res, solve(a, b, c, d));
			res = max(res, solve(a, c, b, d));
			res = max(res, solve(a, d, b, c));
			res = max(res, solve(b, c, a, d));
			res = max(res, solve(b, d, a, c));
			res = max(res, solve(c, d, a, b));
			if (res < 0.0)
				printf("IMPOSSIBLE\n");
			else
				printf("%.2f\n", res);
		}
	}
	return 0;
}
//给4个数，判断能否组成梯形，把上底平移到下底，形成一个平行四边形和一个三角形，若该三角形成立则能够成梯形
//求梯形的最大面积，三角形面积用海伦公式，再求出三角形的高，即为梯形的高，求面积即可