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
const int maxn = 50000 + 100;
const int maxm = 100000 + 100;
int N, M;
struct Node
{
	int u;
	int v;
	int w;
	Node() {}
	Node(int a, int b, int c) : u(a), v(b), w(c) {}
};
vector<Node> G[maxn];
int dis[maxn][2];
int maxpre[maxn][2];
int stdpmax[maxn][20];
int Log2[maxn];
int stdpmin[maxn][20];
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
		if (dis[u][1] < dis[v][0] + w)
		{
			dis[u][1] = dis[v][0] + w;
			maxpre[u][1] = v;
			if (dis[u][0] < dis[u][1])
			{
				swap(dis[u][0], dis[u][1]);
				swap(maxpre[u][0], maxpre[u][1]);
			}
		}
	}
}
void dfs2(int u, int fa)
{
	int i, j, k;
	for (i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i].v;
		int w = G[u][i].w;
		if (v == fa)
			continue;
		if (maxpre[u][0] == v)
		{
			if (dis[v][1] < dis[u][1] + w)
			{
				dis[v][1] = dis[u][1] + w;
				maxpre[v][1] = u;
				if (dis[v][0] < dis[v][1])
				{
					swap(dis[v][1], dis[v][0]);
					swap(maxpre[v][1], maxpre[v][0]);
				}
			}
		}
		else
		{
			if (dis[v][1] < dis[u][0] + w)
			{
				dis[v][1] = dis[u][0] + w;
				maxpre[v][1] = u;
				if (dis[v][0] < dis[v][1])
				{
					swap(dis[v][1], dis[v][0]);
					swap(maxpre[v][1], maxpre[v][0]);
				}
			}
		}
		dfs2(v, u);
	}
}
void solve_dis()
{
	memset(dis, 0, sizeof(dis));
	memset(maxpre, 0, sizeof(maxpre));
	dfs1(1, 0);
	dfs2(1, 0);
}
void initRMQ()
{
	int i, j, k;
	memset(stdpmax, 0, sizeof(stdpmax));
	memset(stdpmin, 0, sizeof(stdpmin));
	for (i = 1; i <= N; i++)
		stdpmin[i][0] = stdpmax[i][0] = dis[i][0];
	Log2[0] = -1;
	for (i = 1; i <= N; i++)
	{
		Log2[i] = (i & (i - 1)) == 0 ? (Log2[i - 1] + 1) : Log2[i - 1];
	}
	for (j = 1; j <= Log2[N]; j++)
	{
		for (i = 1; i + (1 << j) - 1 <= N; i++)
		{
			stdpmax[i][j] = max(stdpmax[i][j - 1], stdpmax[i + (1 << (j - 1))][j - 1]);
			stdpmin[i][j] = min(stdpmin[i][j - 1], stdpmin[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int querymaxRMQ(int l, int r)
{
	int k = Log2[r - l + 1];
	return max(stdpmax[l][k], stdpmax[r - (1 << k) + 1][k]);
}
int queryminRMQ(int l, int r)
{
	int k = Log2[r - l + 1];
	return min(stdpmin[l][k], stdpmin[r - (1 << k) + 1][k]);
}
int main()
{
	int i, j, k, m, Q, res;
	while (scanf("%d %d", &N, &M) != EOF && N + M)
	{
		for (i = 1; i <= N; i++)
		{
			G[i].clear();
		}
		int a, b, c;
		for (i = 1; i <= N - 1; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(Node(a, b, c));
			G[b].push_back(Node(b, a, c));
		}
		solve_dis();
		initRMQ();
		for (m = 1; m <= M; m++)
		{
			scanf("%d", &Q);
			res = 0;
			for (i = 1, j = 1; i <= N; i++)
			{
				while (querymaxRMQ(i, j) - queryminRMQ(i, j) <= Q && j <= N)
				{
					j++;
				}
				if (res < j - i)
					res = j - i;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}