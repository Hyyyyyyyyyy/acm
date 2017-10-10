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
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const ll maxn = 1ll << 10;
ll ar[maxn];
int main()
{
	ll i, j, k, n, m;
	for (i = 0; i <= 255; i++)
	{
		ar[(i ^ (i << 1))   &    ((1ll << 8) - 1)] = i;
	}
	while (scanf("%lld", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &k);
			if (i == 1)
				printf("%lld", ar[k]);
			else
				printf(" %lld", ar[k]);
			putchar('\n');
		}
	}
	return 0;
}