#include <stdio.h>
#include <string.h>

void floyd(double(*dist)[31], int(*path)[31], int n);
int main()
{	int i, j, k, u, m, n, x, y, path[31][31], (*pat)[31], doudou, cas = 0;
	double dist[31][31], temp, (*dis)[31];

	char ar[31][100], a[100], b[100];
	while (scanf("%d", &n) != EOF && n)
	{
		cas++;
		for (i = 1; i <= n; i++)
		{
			scanf("%s", ar[i]);
		}
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				dist[i][j] = 0;
				if (i == j)
					dist[i][j] = 0;
				path[i][j] = j;
			}
		}
		scanf("%d", &m);
		for (i = 1; i <= m; i++)
		{
			scanf("%s %lf %s", a, &temp, b);
			for (j = 1; j <= n; j++)
			{
				if (strcmp(ar[j], a) == 0)
				{
					x = j;
					break;
				}
			}
			for (j = 1; j <= n; j++)
			{
				if (strcmp(ar[j], b) == 0)
				{
					y = j;
					break;
				}
			}
			dist[x][y] = temp;
		}
		dis = dist;
		pat = path;
		floyd(dis, pat, n);
		doudou = 0;
		for (i = 1; i <= n; i++)
			if (dist[i][i] > 1)
				doudou = 1;
		if (doudou)
			printf("Case %d: Yes\n", cas);
		else
			printf("Case %d: No\n", cas);
	}
	return 0;
}
void floyd(double(*dist)[31], int(*path)[31], int n)
{
	int i, j, k, u;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (dist[i][j] < dist[i][k] * dist[k][j])
				{
					dist[i][j] = dist[i][k] * dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}
