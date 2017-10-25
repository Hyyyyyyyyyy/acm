#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
ll P, Q, K;
ll Extend_Euclid(ll a, ll b, ll&x, ll& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll d = Extend_Euclid(b, a%b, x, y);
	ll t = x;
	x = y;
	y = t - a / b*y;
	return d;
}

//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
	ll x, y;
	ll t = Extend_Euclid(a, n, x, y);
	if (t != 1)
		return -1;
	return (x%n + n) % n;
}
long long MUL(long long a, long long b)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
long long MUL2(long long a, long long b)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * inv(a, MOD)) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int ans[200010];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld %lld", &P, &Q, &K);
			printf("%lld\n", (      (      (MUL(P, K) + MUL(P - 2 * Q, K) )       ) % MOD) * inv(2ll * MUL(P, K) % MOD, MOD) % MOD);
		}
	}
	return 0;
}
