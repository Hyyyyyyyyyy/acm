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
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 1e9;
const int INF = 2147483647;
const ll MOD = 365*24*60*60;
const int maxn = 100000 + 100;
struct Node
{
	ll a;
	ll b;
	bool operator < (const Node& p)
	{
		return a * p.b < p.a * b;
	}
};
Node ar[maxn];
int main()
{
	int i, j, k, n, m, N;
	while (scanf("%d", &N) != EOF && N)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%lld %lld", &ar[i].a, &ar[i].b);
		}
		sort(ar + 1, ar + 1 + N);
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			res = (res + ar[i].b*res%MOD + ar[i].a) % MOD;
		}
		printf("%lld\n", res);
	}
	return 0;
}