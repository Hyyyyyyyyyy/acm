#include <stdio.h>
int main()
{
    int c, n, i, u, p;
    long long int S, ar[100];
    while (scanf("%d", &c) != EOF)
    {
        for (i = 1; i <= c; i++)
        {
            scanf("%d", &n);
            if (n == 2)
                printf("%.2lf%%\n", (1.0 / 2.0) * 100);
            else if (n == 3)
                printf("%.2lf%%\n", (2.0 / 6.0) * 100);
            else
            {
                ar[2] = 1;
                ar[3] = 2;
                for (u = 4; u <= n; u++)
                    ar[u] = (ar[u-1] + ar[u-2]) * (u-1);
                S = 1;
                for (p = 1; p <= n; p++)
                    S *= p;
                printf("%.2lf%%\n", ((double)ar[u-1] / (double)S) * 100);
            }
        }
    }
    return 0;
}
