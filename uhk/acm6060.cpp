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
const int maxn = 1000000 + 100;
struct Edge
{
	int u;
	int v;
	int w;
	Edge(int a, int b, int c) : u(a), v(b), w(c) {}
};
vector<Edge>G[maxn];
int cost[maxn], Size[maxn];
int N, K;
void dfs(int u, int fa)
{
	int i, j, sz = G[u].size();
	for (i = 0; i < sz; i++)
	{
		int v = G[u][i].v;
		if (v == fa)
			continue;
		cost[v] = G[u][i].w;
		dfs(v, u);
		Size[u] += Size[v];
	}
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d", &N, &K) != EOF)
	{
		for (i = 0; i <= N; i++)
		{
			G[i].clear();
			Size[i] = 1;
		}
		for (i = 1; i <= N - 1; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(Edge(a, b, c));
			G[b].push_back(Edge(b, a, c));
		}
		dfs(1, -1);
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			res += (ll)cost[i] * min(K, Size[i]);
		}
		printf("%lld\n", res);
	}
	return 0;
}