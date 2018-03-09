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
const int maxn = 10000 + 100;
const int maxm = 100000 + 100;
struct Node
{
	int u;
	int v;
	int w;
	Node() {}
	Node(int a, int b, int c) : u(a), v(b), w(c) {}
};
vector<Node> G[maxn];
int dp[maxn][2];
int index[maxn][2];
int N;
void dfs1(int u, int fa)
{
	int i, j;
	for (i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i].v;
		int w = G[u][i].w;
		if (v == fa)
			continue;
		dfs1(v, u);
		if (dp[u][1] < dp[v][0] + w)
		{
			dp[u][1] = dp[v][0] + w;
			index[u][1] = v;
			if (dp[u][1] > dp[u][0])
			{
				swap(dp[u][0], dp[u][1]);
				swap(index[u][0], index[u][1]);
			}
		}
	}
}
void dfs2(int u, int fa)
{
	int i, j;
	for (i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i].v;
		int w = G[u][i].w;
		if (v == fa)
			continue;
		if (v == index[u][0])
		{
			if (dp[u][1] + w > dp[v][1])
			{
				dp[v][1] = dp[u][1] + w;
				index[v][1] = u;
				if (dp[v][1] > dp[v][0])
				{
					swap(dp[v][0], dp[v][1]);
					swap(index[v][0], index[v][1]);
				}
			}
		}
		else
		{
			if (dp[u][0] + w > dp[v][1])
			{
				dp[v][1] = dp[u][0] + w;
				index[v][1] = u;
				if (dp[v][1] > dp[v][0])
				{
					swap(dp[v][0], dp[v][1]);
					swap(index[v][0], index[v][1]);
				}
			}
		}
		dfs2(v, u);
	}
}
void solve()
{
	memset(dp, 0, sizeof(dp));
	memset(index, 0, sizeof(index));
	dfs1(1, 0);
	dfs2(1, 0);
}
int main()
{
	int i, j, v, w;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 0; i <= N; i++)
			G[i].clear();
		for (i = 2; i <= N; i++)
		{
			scanf("%d %d", &v, &w);
			G[i].push_back(Node( i, v, w ));
			G[v].push_back(Node( v, i, w ));
		}
		solve();
		for (i = 1; i <= N; i++)
			printf("%d\n", dp[i][0]);
	}
	return 0;
}