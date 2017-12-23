#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int inf = (1 << 31) - 1;
struct Edge
{
	int u;
	int v;
	int w;
	int next;
};
struct Edge edge[10010];
int head[510];
int visit[510];
int tot, RES, Min_road, Max_road, S, T, N_city, M_road;
void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void dfs(int n, int max, int min)
{
	if (n == T)
	{
		if (RES > max - min)
			RES = max - min;
		return;
	}
	int i, j, k, u, v, w, tempmax, tempmin;
	tempmax = max;
	tempmin = min;
	for (i = head[n]; i != -1; i = edge[i].next)
	{
		v = edge[i].v;
		w = edge[i].w;
		if (!visit[v])
		{
			if (tempmax < w)
				tempmax = w;
			if (tempmin > w)
				tempmin = w;
			visit[v] = 1;
			dfs(v, tempmax, tempmin);
			visit[v] = 0;
			tempmax = max;
			tempmin = min;
		}
	}
	return;
}
int main()
{
	int i, j, u, v, w, n, m;
	printf("Please input number of test case:\n");
	scanf("%d", &n);
	for (m = 1; m <= n; m++)
	{
		init();
		printf("Please input the number of cities and roads:\n");
		scanf("%d %d", &N_city, &M_road);
		printf("Please input the details:\n");
		for (i = 1; i <= M_road; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			addedge(u, v, w);
			addedge(v, u, w);
		}

		printf("Please input the start city and end city:\n");
		scanf("%d %d", &S, &T);
		memset(visit, 0, sizeof(visit));
		RES = inf;
		visit[S] = 1;
		dfs(S, -inf, inf);
		printf("Case #%d Result:%d\n", m, RES);
	}
	return 0;
}
