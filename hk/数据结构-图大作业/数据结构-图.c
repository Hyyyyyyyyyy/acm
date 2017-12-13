#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int inf = (1 << 31) - 1;
struct Edge
{
	int u;
	int v;
	int w;
};
struct Edge edge[5010];
int father[510];
int tot, RES, Min_road, Max_road, S, T, N_city, M_road;
void init()
{
	int i;
	tot = 1;
	RES = inf;
	Max_road = -inf;
	Min_road = inf;
	for (i = 1; i <= N_city; i++)
		father[i] = i;
}
void addedge(int u, int v, int w)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot++].w = w;
}
int merge(int n)
{
	if (father[n] != n)
		father[n] = merge(father[n]);
	return father[n];
}
int comp(const void *a, const void *b)
{
	return (((const struct Edge*)a)->w - ((const struct Edge*)b)->w);
}
int main()
{
	int i, j, u, v, w, n, m;
	printf("Please input number of test case:\n");
	scanf("%d", &n);
	for (m = 1; m <= n; m++)
	{
		printf("Please input the number of cities and roads:\n");
		scanf("%d %d", &N_city, &M_road);
		init();
		printf("Please input the details:\n");
		for (i = 1; i <= M_road; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			addedge(u, v, w);
		}
		qsort(edge + 1, M_road, sizeof(struct Edge), comp);
		printf("Please input the start city and end city:\n");
		scanf("%d %d", &S, &T);
		for (i = 1; i <= M_road; i++)
		{
			for (j = 1; j <= N_city; j++)
				father[j] = j;
			Max_road = -inf;
			Min_road = inf;
			for (j = i; j <= M_road; j++)
			{
				u = edge[j].u;
				v = edge[j].v;
				u = merge(u);
				v = merge(v);
				if (u != v)
				{
					father[u] = v;
					if (Max_road < edge[j].w)
						Max_road = edge[j].w;
					if (Min_road > edge[j].w)
						Min_road = edge[j].w;
				}
				u = S;
				v = T;
				u = merge(u);
				v = merge(v);
				if (u == v && RES > Max_road - Min_road)
				{
					RES = Max_road - Min_road;
				}
			}
		}
		printf("Case #%d Result:%d\n", m, RES);
	}
	return 0;
}