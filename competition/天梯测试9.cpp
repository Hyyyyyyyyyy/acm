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
const int maxn = 50001 + 100;
const int maxm = 1000000 + 100;
struct Edge
{
	int u;
	int v;
};
Edge edge[5010];
int N, M, Q;
int fa[maxn];
int Find(int x)
{
	if (fa[x] == x)
		return x;
	fa[x] = Find(fa[x]);
	return fa[x];
}
void Union(int a, int b)
{
	int u = Find(a);
	int v = Find(b);
	if (u != v)
	{
		fa[u] = v;
	}
}
int vis[550];
int main()
{
	int i, j, k, a, b, q;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		int tot = 0;
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < N; i++)
		{
			fa[i] = i;
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &a, &b);
			Union(a, b);
			edge[tot].u = a;
			edge[tot++].v = b;
		}
		scanf("%d", &Q);
		int num;
		int res = 0;
		for (i = 0; i < N; i++)
		{
			if (fa[i] == i)
				res++;
		}
		for (q = 1; q <= Q; q++)
		{
			scanf("%d", &a);
			vis[a] = 1;
			for (i = 0; i < N; i++)
			{
				fa[i] = i;
			}
			for (i = 0; i < tot; i++)
			{
				if (vis[edge[i].u] || vis[edge[i].v])
					continue;
				Union(edge[i].u, edge[i].v);
			}
			num = 0;
			for (i = 0; i < N; i++)
			{
				if (fa[i] == i)
					num++;
			}
			if (num > res + 1)
			{
				printf("Red Alert: City %d is lost!\n", a);
			}
			else
			{
				printf("City %d is lost.\n", a);
			}
			res = num;
		}
		if (Q == N)
			printf("Game Over.\n");
	}
	return 0;
}