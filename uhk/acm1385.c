#include <stdio.h>
#define MAXINT 10000000
void floyd(int(*dist)[1002], int(*path)[1002], int *ar, int n);
int main()
{
    int i, j, k, u, n, m, a, b, cost, dist[1002][1002], (*dis)[1002], path[1002][1002], (*pat)[1002], ar[1002];
    while (scanf("%d", &n) != EOF && n)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &dist[i][j]);
                if (dist[i][j] == -1)
                    dist[i][j] = MAXINT;
                path[i][j] = j;
            }
        }
        for (i = 1; i <= n; i++)
            scanf("%d", &ar[i]);
        dis = dist;
        pat = path;
        floyd(dis, pat, ar, n);
        while (scanf("%d %d", &a, &b) == 2 && (a != -1 && b != -1))
        {
            printf("From %d to %d :\n", a, b);
            printf("Path: %d", a);

            j = b;
            k = a;
            while (k != j)
            {
                printf("-->%d", path[k][j]);
                k = path[k][j];
            }
            printf("\n");
            printf("Total cost : %d\n\n", dist[a][b]);
        }
    }
    return 0;
}
void floyd(int(*dist)[1002], int(*path)[1002], int *ar, int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j] + ar[k] && dist[i][k] != MAXINT && dist[k][j] != MAXINT)
                {
                    dist[i][j] = dist[i][k] + dist[k][j] + ar[k];
                    path[i][j] = path[i][k];
                }
                else if (dist[i][j] == dist[i][k] + dist[k][j] + ar[k])
                {
                    if (path[i][j] > path[i][k])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j] + ar[k];
                        path[i][j] = path[i][k];
                    }
                }
            }
        }
    }
}