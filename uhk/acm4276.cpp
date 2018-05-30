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
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 500 + 100;
const int maxm = 1000000 + 100;
int N, T, V;
int ar[maxn];
vector<int> G[maxn];
int cost[maxn][maxn];
int dp[maxn][maxn];
bool shorest_road(int u, int fa)
{
	if (u == N)
		return true;
	int i;
	for (i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (v == fa)
			continue;
		if (shorest_road(v, u))
		{
			V += cost[u][v];
			cost[u][v] = cost[v][u] = 0;
			return true;
		}
	}
	return false;
}
void dfs(int u, int fa)
{
	int i, j, k;
	for (i = 0; i <= T; i++)
		dp[u][i] = ar[u];
	for (i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		int w = cost[u][v] * 2;
		if (v == fa)
			continue;
		dfs(v, u);
		for (j = T; j >= w; j--)
		{
			for (k = 0; k <= j - w; k++)
			{
				dp[u][j] = max(dp[u][j], dp[v][k] + dp[u][j - k - w]);
			}
		}
	}
}
int main()
{
	int i, j, k, a, b, c;
	while (scanf("%d %d", &N, &T) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			G[i].clear();
			for (j = 1; j <= N; j++)
			{
				if (i != j)
					cost[i][j] = inf;
				else
					cost[i][j] = 0;
			}
		}
		memset(dp, 0, sizeof(dp));
		for (i = 1; i < N; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(b);
			G[b].push_back(a);
			cost[a][b] = cost[b][a] = min(cost[a][b], c);
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		V = 0;
		shorest_road(1, 0);
		if (V > T)
		{
			printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
			continue;
		}
		T -= V;
		dfs(1, 0);

		printf("%d\n", dp[1][T]);
	}
	return 0;
}