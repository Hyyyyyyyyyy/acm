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
const ll MOD = 998244353;
ll N, M;
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
int main()
{
	ll i, j, k, u, n, m;
	while (scanf("%lld %lld", &N, &M) != EOF)
	{
		if ((N % 2 == 0 && M % 2 != 0) || (N % 2 != 0 && M % 2 == 0))
		{
			printf("0\n");
		}
		else
		{
			ll F;
			if ((((N - M) / 2) + 2) % 2 == 0)
			{
				F = 1;
			}
			else
				F = -1;
			F *= N;
			F %= MOD;
			if (M == 0)
			{
				printf("%lld\n", ((F + MOD) % MOD * inv(N, MOD) + MOD) % MOD);
			}
			else
			{
				ll T1, T2;
				T1 = T2 = 1ll;
				for (i = N + M - 2; i > N - M; i -= 2)
				{
					T1 = (T1 * i % MOD) % MOD;
				}
				for (i = M; i >= 1; i--)
				{
					T2 = (T2 * i % MOD) % MOD;
				}
				printf("%lld\n", ((F * T1 % MOD + MOD) % MOD * inv(T2, MOD) + MOD) % MOD);
			}
		}
	}
	return 0;
}