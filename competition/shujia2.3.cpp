#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
const int maxn = 100000 + 10;
const int INF = 1000000000;
struct Node
{
	int u1;
	int u2;
	int v;
	int next;
};
Node edge[maxn * 2];
int visit[maxn], head[maxn * 2], ar[maxn];
int cnt, N, M;
void addedge(int a, int b, int c)
{
	edge[cnt].u1 = a;
	edge[cnt].u2 = b;
	edge[cnt].v = c;
	edge[cnt].next = head[a];
	head[a] = cnt++;
	edge[cnt].u1 = b;
	edge[cnt].u2 = a;
	edge[cnt].v = c;
	edge[cnt].next = head[b];
	head[b] = cnt++;
}
struct Point
{
	int x;
	int y;
	int z;
};
Point point[maxn];
void dfs(int n)
{
	int i, j;
	for (i = head[n]; i != -1; i = edge[i].next)
	{
		int u1 = edge[i].u1;
		int u2 = edge[i].u2;
		int v = edge[i].v;
		if (ar[v] > ar[u1] + ar[u2])
		{
			ar[v] = ar[u1] + ar[u2];
			dfs(v);
		}
	}
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	scanf("%d", &n);
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			memset(head, -1, sizeof(head));
			cnt = 0;
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d %d", &a, &b, &c);
				addedge(a, b, c);
				point[i].x = a;
				point[i].y = b;
				point[i].z = c;
			}
			for (i = 1; i <= M; i++)
			{
				if (ar[point[i].z] > ar[point[i].x] + ar[point[i].y])
				{
					ar[point[i].z] = ar[point[i].x] + ar[point[i].y];
					dfs(point[i].z);
				}
			}
			for (i = 1; i <= N; i++)
			{
				if (i != 1)
					putchar(' ');
				printf("%d", ar[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}