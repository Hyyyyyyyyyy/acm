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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ull MOD = (1ull << 64);
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int main()
{
	int i, j, k;
	double a, b, c;
	double res[5];
	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		res[0] = a - 60;
		res[1] = b - 60;
		res[2] = 180 - res[0] - res[1];
		sort(res, res + 3);
		printf("%.4f %.4f %.4f\n", res[0], res[1], res[2]);
	}
	return 0;
}