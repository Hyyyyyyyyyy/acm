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
const int maxm = 1000000 + 100;
vector<pair<ll, ll> > G[maxn];
ll cur[maxn], tol[maxn], res, N;
bool vis[maxn];
void dfs(ll n, ll pre)
{
	ll i, j;
	if (vis[n])
		return;
	vis[n] = true;
	tol[n] = 1;
	for (i = 0; i < G[n].size(); i++)
	{
		ll fi = G[n][i].first;
		if (fi != pre)
		{
			dfs(fi, n);
			res += min(tol[fi], N - tol[fi]) * G[n][i].second;
			tol[n] += tol[fi];
		}
	}
	return;
}

int main()
{
	ll i, j, k, n, m, CAS, cas, a, b, c;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			for (i = 0; i <= N; i++)
				G[i].clear();
			for (i = 1; i <= N - 1; i++)
			{
				scanf("%lld %lld %lld", &a, &b, &c);
				G[a].push_back(make_pair(b, c));
				G[b].push_back(make_pair(a, c));
			}
			memset(cur, 0, sizeof(cur));
			memset(tol, 0, sizeof(tol));
			memset(vis, false, sizeof(vis));
			res = 0;
			dfs(1, 0);
			printf("Case #%lld: %lld\n", cas, res*2);
		}
	}
	return 0;
}