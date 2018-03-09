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
const ll MOD = 100000007ll;
const int maxn = 100000 + 100;
const int maxm = 100000 + 100;
ll N, M;
ll gcd(ll x, ll y)
{
	ll t;
	while (y)
	{
		t = x % y;
		x = y;
		y = t;
	}
	return  x;
}
ll ar[maxn];   //原始数据
ll dp[maxn][20];   //dp[i][j]表示以i开始连续j个元素的最值
				   //转移：dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);     相当于把区间[i,2^j-1]分成[i,2^(j-1)-1]和[i+2^(j-1), 2^j-1];
ll Log2[maxn];
void initRMQ(ll n)
{
	Log2[0] = -1;
	for (ll i = 1; i <= n; i++)
	{
		Log2[i] = ((i & (i - 1)) == 0) ? (Log2[i - 1] + 1) : Log2[i - 1];
		dp[i][0] = ar[i];
	}
	for (ll j = 1; j <= Log2[n]; j++)
	{
		for (ll i = 1; i + (1 << j) - 1 <= n; i++)
		{
			dp[i][j] = gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}
map<ll, ll> mp;
ll queryRMQ(ll b, ll e)
{
	ll k = Log2[e - b + 1];
	return gcd(dp[b][k], dp[e - (1 << k) + 1][k]);
}
void solve()
{
	ll l, r, mid, i, j, g;
	mp.clear();
	for (i = 1; i <= N; i++)
	{
		g = dp[i][0];
		j = i;
		while (j <= N)
		{
			l = j;
			r = N;
			while (l < r)
			{
				mid = (l + r + 1) / 2;
				if (queryRMQ(i, mid) == g)
					l = mid;
				else
					r = mid - 1;
			}
			mp[g] += l - j + 1;
			j = l + 1;
			g = queryRMQ(i, j);
		}
	}
}
int main()
{
	ll i, j, cas, CAS, L, R, m;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			initRMQ(N);
			solve();
			scanf("%lld", &M);
			printf("Case #%lld:\n", cas);
			for (m = 1; m <= M; m++)
			{
				scanf("%lld %lld", &L, &R);
				ll res = queryRMQ(L, R);
				printf("%lld %lld\n", res, mp[res]);
			}
		}
	}
	return 0;
}