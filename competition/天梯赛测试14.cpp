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
const ll MOD = 1000000007ll;
const int maxn = 10000 + 1;
const int maxm = 1000000 + 100;
vector<int> G[maxn];
int dp[maxn];
int vis[maxn];
queue<int> Q;
int N;
int bfs(int n)
{
	int i, j, k;
	int res = 0;
	int id = 0;
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	while (!Q.empty())
	{
		Q.pop();
	}
	Q.push(n);
	vis[n] = 1;
	dp[n] = 0;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for (i = 0; i < G[now].size(); i++)
		{
			int v = G[now][i];
			if (!vis[v])
			{
				Q.push(v);
				vis[v] = 1;
				dp[v] = dp[now] + 1;
			}
		}
	}
	for(i = 1; i <= N; i++)
		if (res < dp[i])
		{
			res = dp[i];
			id = i;
		}
	return id;
}
int main()
{
	int i, j, k, M, K, a, b;
	while (scanf("%d %d %d", &N, &M, &K) != EOF)
	{
		for (i = 1; i <= N; i++)
			G[i].clear();
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for (i = 1; i <= K; i++)
		{
			scanf("%d", &k);
			printf("%d\n", bfs(k));
		}
	}
	return 0;
}