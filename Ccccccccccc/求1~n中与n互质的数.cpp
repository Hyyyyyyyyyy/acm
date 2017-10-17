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
const ll INF = 1e18;
const ll MOD = 1000000007;
const int maxn = 10010;
bool check[maxn + 10];
ll prime[maxn + 10];
ll tot;
void phi_and_prime_table(ll N)
{
	memset(check, false, sizeof(check));
	tot = 0;
	for (ll i = 2; i <= N; i++)
	{
		if (!check[i])
		{
			prime[tot++] = i;
		}
		for (ll j = 0; j < tot; j++)
		{
			if (i * prime[j] > N)
				break;
			check[i * prime[j]] = true;
		}
	}
}
//质数个数 < tot
vector<ll>G;
long long MUL2(long long a, long long b)
{
	long long res = 0;
	while (b)
	{
		if (b & 1)
		{
			res = (res + a) % MOD;
		}
		a = (a + a) % MOD;
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

//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
	ll x, y;
	ll t = Extend_Euclid(a, n, x, y);
	if (t != 1)
		return -1;
	return (x%n + n) % n;
}
ll Sum(ll n)
{
	ll res = n;
	res = (res * (n + 1)) % MOD;
	res = (res * (2ll * n + 1)) % MOD;
	res = (res * ((3ll * n * n % MOD + 3ll * n % MOD - 1) % MOD)) % MOD;
	res = (res * inv(30ll, MOD)) % MOD;
	return res;
}
ll Pow(ll n)
{
	return (n * n % MOD * n % MOD * n % MOD) % MOD;
}
ll dfs(ll n, int start, int count) //容斥原理  
{
	ll ans = 0;
	int i;
	for (i = start; i<count; i++)
	{
		ll temp = Pow(G[i]);
		ans = (ans + (temp*Sum(n / G[i])) % MOD -
			(temp*dfs(n / G[i], i + 1, count)) % MOD + MOD) % MOD;
	}
	return ans;
}
int main()
{
	ll i, j, n, m, N;
	phi_and_prime_table(10001ll);
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			ll T = N;
			G.clear();
			for (i = 0; i < tot; i++)
			{
				if (N % prime[i] == 0)
				{
					G.push_back(prime[i]);
					while (N % prime[i] == 0)
					{
						N /= prime[i];
					}
				}
			}
			if (N != 1)
				G.push_back(N);
			ll res = Sum(T);
			// ll total = 1ll << G.size();
			// for (i = 1; i < total; i++)
			// {
			// 	ll t = i;
			// 	ll count = 0;
			// 	ll temp = 1ll;
			// 	for (j = 0; j < G.size(); j++)
			// 	{
			// 		if (t & (1ll << j))
			// 		{
			// 			count++;
			// 			temp *= G[j];
			// 		}
			// 	}
			// 	if (count & 1)
			// 	{
			// 		ll tt = temp;
			// 		ll u = T / temp;
			// 		for (j = 1; j <= u; j++)
			// 		{
			// 			res = (res - Pow(tt)) % MOD;
			// 			tt *= temp;
			// 		}
			// 	}
			// 	else
			// 	{
			// 		ll tt = temp;
			// 		ll u = T / temp;
			// 		for (j = 1; j <= u; j++)
			// 		{
			// 			res = (res + Pow(tt)) % MOD;
			// 			tt *= temp;
			// 		}
			// 	}
			// }
			printf("%lld\n", ((res - dfs(T, 0, G.size())) % MOD + MOD) % MOD);
		}
	}
	return 0;
}