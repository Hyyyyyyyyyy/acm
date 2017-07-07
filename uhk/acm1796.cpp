#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 20;
ll ar[maxn];
ll N, M, res, cnt;
ll gcd(ll x, ll y)
{
	ll t;
	while (y)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return  x;
}
void dfs(ll n, ll lcm, ll sta)
{
	ll i;
	lcm = ar[n] / gcd(ar[n], lcm) * lcm;
	if (sta & 1)
		res += (N - 1) / lcm;
	else
		res -= (N - 1) / lcm;
	for (i = n + 1; i < cnt; i++)
		dfs(i, lcm, sta + 1);
}
int main()
{
	ll i, j, k, u, n, m, a, b;
	while (scanf("%lld %lld", &N, &M) != EOF)
	{
		cnt = 1;
		for (i = 1; i <= M; i++)
		{
			scanf("%lld", &a);
			if (a != 0)
				ar[cnt++] = a;
		}
		res = 0;
		for (i = 1; i < cnt; i++)
		{
			dfs(i, ar[i], 1);
		}
		printf("%lld\n", res);
	}
	return 0;
}
