#include <stdio.h>
#define MAXINT 10000000
void floyd(int(*dist)[101], int n);
int main()
{
	int i, j, k, u, n, m, a, b, dist[101][101], doudou;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				dist[i][j] = MAXINT;
				if (i == j)
					dist[i][j] = 0;
	
			}
		}
		for (u = 0; u < m; u++)
		{
			scanf("%d %d", &a, &b);
			dist[a][b] = 1;
			dist[b][a] = 1;
		}
		floyd(dist, n);
		doudou = 1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (dist[i][j] > 7)
				{
					doudou = 0;
					break;
				}
			}
			if (doudou == 0)
				break;
		}
		if (doudou == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
void floyd(int(*dist)[101], int n)
{
	int i, j, k, u;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
