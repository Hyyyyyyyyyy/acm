#include <stdio.h>
#define MAXINT 100000000
void floyd(int(*dist)[205], int n);
int main()
{
    int i, j, k, u, n, m, a, b, c, begin, end, dist[205][205];
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
        for (u = 1; u <= m; u++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (dist[a][b] > c)
            {
                dist[a][b] = c;
                dist[b][a] = c;
            }
        }
        scanf("%d %d", &begin, &end);
        floyd(dist, n);
        if (dist[begin][end] != MAXINT)
            printf("%d\n", dist[begin][end]);
        else
            printf("-1\n");
    }
    return 0;
}
void floyd(int(*dist)[205], int n)
{
    int i, j, k, u;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}