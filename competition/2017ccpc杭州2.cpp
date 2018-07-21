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
const ll MOD = 998244353ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
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
	y = t - a / b * y;
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
ll ar[maxn];
ll N;
int main()
{
	ll i, j, k, CAS, cas;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			ll tot = 0;
			ll sum = 0;
			for (i = 0; i < N; i++)
			{
				scanf("%lld", &ar[i]);
				tot = (tot + 2*ar[i])%MOD;
				sum += ar[i];
			}
			tot -= ar[0];
			sum -= ar[0];
			ll res = tot * inv(N, MOD) % MOD;
			for (i = 1; i <= N - 2; i++)
			{
				res = (res + (sum - ar[i])*inv((i + 1)*N, MOD) % MOD) % MOD;
				sum -= ar[i];
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}