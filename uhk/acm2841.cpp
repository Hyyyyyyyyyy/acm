#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
vector<int>G[maxn];
ll Q[maxn];
ll cnt;
void Primefactor()      //筛出小于n的质因子
{
	ll i, j;
	for (i = 1; i < maxn; i++)
		G[i].clear();
	for (j = 2; j < maxn; j++)
	{
		cnt = 0;
		ll n = j;
		for (i = 2; i*i <= j; i++)
		{
			if (n % i == 0)
			{
				G[j].push_back(i);
				while (n % i == 0)
				{
					n /= i;
				}
			}
		}
		if (n > 1)
			G[j].push_back(n);
	}
}
ll solve(ll n, ll m)         //找出小于m的与n互质的数的个数
{
	ll i, j, t;
	ll count = 0;
	Q[0] = -1;
	for (i = 0; i < G[n].size(); i++)
	{
		if (G[n][i] > m)
			break;
		//if (G[n][i] < n)
		//	continue;
		t = count;
		for (j = 0; j <= t; j++)
		{
			Q[++count] = Q[j] * (-1) * G[n][i];
		}
	}
	ll sum = 0;
	for (i = 1; i <= count; i++)
	{
		sum += m / Q[i];
	}
	return m - sum;
}
int main()
{
	ll i, j, k, u, a, b, c, d, n, m;
	Primefactor();
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &k);
			if (k == 0)
			{
				printf("Case %lld: 0\n", m);
				continue;
			}
			b /= k;
			d /= k;
			if (b > d)
				swap(b, d);
			ll res = 0;
			for (i = 1; i <= d; i++)
			{
				res += solve(i, i < b ? i : b);
			}
			printf("Case %lld: %lld\n", m, res);
		}
	}
	return 0;
}