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
const int inf = 1000000000;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100 + 100;
const int maxm = 5000 + 100;
int ar[maxn][maxn];
int vis[maxn];
int N, M, H;
struct Node
{
	int id;
	int C;
	int D;
};
Node node[20];
void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (ar[i][k] + ar[k][j] < ar[i][j])
					ar[i][j] = ar[i][k] + ar[k][j];
			}
		}
	}
}
bool dfs(int u, int sta, int money)
{
	int i, j;
	if (sta == (1 << H) - 1)
	{
		if (money >= ar[u][1])
			return true;
		return false;
	}
	for (i = 1; i <= H; i++)
	{
		int v = node[i].id;
		if (vis[v] || money - ar[u][v] - node[i].D < 0)
			continue;
		vis[v] = 1;
		if (dfs(v, sta | (1 << (i - 1)), money - ar[u][v] - node[i].D + node[i].C))
		{
			return true;
		}
		vis[v] = 0;
	}
	return false;
}
int main()
{
	int i, j, k, cas, CAS, Money, a, b, w;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d %d", &N, &M, &Money);
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= N; j++)
				{
					if (i != j)
						ar[i][j] = inf;
					else
						ar[i][j] = 0;
				}
			}
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d %d", &a, &b, &w);
				ar[a][b] = ar[b][a] = min(ar[a][b], w);
			}
			Floyd();
			scanf("%d", &H);
			for (i = 1; i <= H; i++)
			{
				scanf("%d %d %d", &node[i].id, &node[i].C, &node[i].D);
			}
			memset(vis, 0, sizeof(vis));
			if (dfs(1, 0, Money))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}