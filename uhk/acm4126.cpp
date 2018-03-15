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
const ll MOD = 100000007ll;
const int maxn = 3000 + 100;
const int maxm = 9000000 + 100;
vector<ll> G[maxn];
ll ar[maxn][maxn];
ll dp[maxn][maxn];
ll dis[maxn];
bool vis[maxn];
ll pre[maxn];
ll N, M, Q;
void init()
{
	ll i, j, k;
	for (i = 0; i <= N; i++)
	{
		G[i].clear();
		vis[i] = false;
		pre[i] = -1;
		for (j = 0; j <= N; j++)
		{
			ar[i][j] = INF;
			dp[i][j] = INF;
		}
	}
}
ll Prime()
{
	ll i, j, k;
	ll res = 0;
	for (i = 2; i <= N; i++)
	{
		dis[i] = ar[1][i];
		pre[i] = 1;
	}
	vis[1] = true;
	for (i = 2; i <= N; i++)
	{
		ll k = -1;
		ll temp = INF;
		for (j = 1; j <= N; j++)
		{
			if (!vis[j] && temp > dis[j])
			{
				temp = dis[j];
				k = j;
			}
		}
		vis[k] = true;
		res += temp;
		if (pre[k] != -1)
		{
			G[k].push_back(pre[k]);
			G[pre[k]].push_back(k);
		}
		for (j = 1; j <= N; j++)
		{
			if (!vis[j] && dis[j] > ar[j][k])
			{
				dis[j] = ar[j][k];
				pre[j] = k;
			}
		}
	}
	return res;
}
ll dfs(ll pos, ll u, ll fa)
{
	ll i, j, k;
	ll res = INF;
	for (i = 0; i < G[u].size(); i++)
	{
		ll v = G[u][i];
		if (v == fa)
			continue;
		ll temp = dfs(pos, v, u);
		dp[u][v] = dp[v][u] = min(dp[u][v], temp);
		res = min(res, temp);
	}
	if (pos != fa)
		res = min(res, ar[pos][u]);
	return res;
}
int main()
{
	ll i, j, k, a, b, c, q;
	while (scanf("%lld %lld", &N, &M) != EOF && N + M)
	{
		init();
		for (i = 1; i <= M; i++)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			a++;
			b++;
			ar[a][b] = c;
			ar[b][a] = c;
		}
		ll P = Prime();
		for (i = 1; i <= N; i++)
			dfs(i, i, -1);
		scanf("%lld", &Q);
		ll res = 0;
		for (q = 1; q <= Q; q++)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			a++;
			b++;
			if (pre[a] != b && pre[b] != a)
			{
				res += P;
			}
			else
			{
				res += P - ar[a][b] + min(c, dp[a][b]);
			}
		}
		//printf("%lld %lld\n", P, res);
		printf("%.4f\n", (double)res / (double)Q);
	}
	return 0;
}