#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int maxn = 100000 + 100;
const int MOD = 1e9 + 7;
int N, K;
ll cuo[10010];
ll C[10010];
void quancuo()
{
	int i, j;
	cuo[0] = 1;
	cuo[1] = 0;
	cuo[2] = 1;
	for (i = 3; i <= 10000; i++)
	{
		cuo[i] = ((cuo[i - 1] + cuo[i - 2]) % MOD) * (i - 1) % MOD;
	}
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

//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
	ll x, y;
	ll t = Extend_Euclid(a, n, x, y);
	if (t != 1)
		return -1;
	return (x%n + n) % n;
}
void getC(ll n)
{
	ll i, j, k;
	C[0] = 1;
	C[1] = n;
	for (i = 2; i <= n; i++)
	{
		C[i] = C[i - 1] * (n - i + 1) % MOD * inv(i, MOD) % MOD;
	}
}
int main()
{
	int i, j, k, u, n, m, a, b;
	quancuo();
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &K);
			ll res = 0;
			getC((ll)N);
			for (i = K; i <= N; i++)
			{
				res = (res + C[i] * cuo[N - i] % MOD) % MOD;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}