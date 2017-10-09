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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int maxn = 1000000 + 100;
ll dp[maxn];
ll N, R, P;
ll dfs(ll n)
{
	if (n <= 1)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	ll i, j;
	ll res = INF;
	for (i = 1; i <= n - 1; i++)
	{
		ll t = dfs((n + i) / (i + 1)) + i*P + R;
		if (res > t)
			res = t;
	}
	dp[n] = res;
	return res;
}
int main()
{
	ll i, j, k, n, m;
	while (scanf("%lld %lld %lld", &N, &R, &P) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", dfs(N));
	}
	return 0;
}