#include <stdio.h>
#define MAXINT 100000000
void floyd(int(*dist)[1002], int n);
int main()
{
	int i, j, k, u, n, m, a, b, c, ar[1002], sa[1002], dist[1002][1002], S, D, T, min, max;
	while (scanf("%d %d %d", &T, &S, &D) != EOF)
	{
		for (i = 1; i <= 1000; i++)
		{
			for (j = 1; j <= 1000; j++)
			{
				dist[i][j] = MAXINT;
				if (i == j)
					dist[i][j] = 0;
			}
		}
		max = 0;
		for (u = 1; u <= T; u++)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (dist[a][b] > c)
			{
				dist[a][b] = c;
				dist[b][a] = c;
			}
			max = (max > a) ? max : a;
			max = (max > b) ? max : b;
		}
		
		for (u = 1; u <= S; u++)
		{
			scanf("%d", &ar[u]);
		}
		for (u = 1; u <= D; u++)
			scanf("%d", &sa[u]);
		floyd(dist, max);
		min = MAXINT;
		for (i = 1; i <= S; i++)
		{
			for (j = 1; j <= D; j++)
			{
				if (min > dist[ar[i]][sa[j]])
					min = dist[ar[i]][sa[j]];
			}
		}
		printf("%d\n", min);
	}
	return 0;
}
void floyd(int(*dist)[1002], int n)
{
	int i, j, k, u;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			if (dist[i][k] != MAXINT)
			{
				for (j = 1; j <= n; j++)
				{
					if (dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}
}
