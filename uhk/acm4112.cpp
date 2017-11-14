#include <cstdio>
#include <cstring>
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
#define foR for
#define for9 for
typedef long long ll;
typedef unsigned long long ull;
const int inf = (1ll << 31) - 1;
const ll INF = (1ull << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int X, Y, Z;
int main()
{
	int i, j, k, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &X, &Y, &Z);
			printf("Case #%d: ", m);
			ll res1, res2;
			res2 = ceil(log2(X)) + ceil(log2(Y)) + ceil(log2(Z));
			res1 = ((ll)X - 1)*(ll)Y*(ll)Z + ((ll)Y - 1)*(ll)Z + (ll)Z - 1;
			printf("%lld %lld\n", res1, res2);
		}
	}
	return 0;
}