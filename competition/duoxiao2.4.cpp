#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <cmath>  
#include <algorithm>  
#include <deque>  
using namespace std;
typedef long long ll;
const ll INF = 2147483640;
const ll maxn = 100000 + 100;
const ll MOD = 1e9 + 7;
ll N, M;
long long MUL(long long a, long long b, long long MOD)
{
	long long res = 1ll;
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

//a??n??????,?????-1
ll inv(ll a, ll n)
{
	ll x, y;
	ll t = Extend_Euclid(a, n, x, y);
	if (t != 1)
		return -1;
	return (x%n + n) % n;
}
int main()
{
	ll i, j, k, u, n, m;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &N, &M);
			if (N % 2ll == 0)
			{
				ll t = MUL(2ll, N);
				ll res = MUL(t - 1, M - 1);
				res = (res * 2) % MOD;
				res = res * inv(3ll, MOD) % MOD;
				printf("%lld\n", res);
			}
			else
			{
				ll t = MUL(2ll, N);
				ll res = MUL(t - 1, M - 1);
				res = ((res * 2) % MOD + 1) % MOD;
				res = res * inv(3ll, MOD) % MOD;
				printf("%lld\n", res);
			}
		}
	}
	return 0;
}