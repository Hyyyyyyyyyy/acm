#include <stdio.h>
int main()
{
    int c, n, m, i, u, p, q, t;
    long long int ar[9999], P, Q, T;
    while (scanf("%d", &c) != EOF)
    {
        for (i = 1; i <= c; i++)
        {
            P = 1;
            Q = 1;
            T = 1;
            scanf("%d %d", &n, &m);
            for (p = 1; p <= n; p++)
                P *= p;
            for (q = 1; q <= m; q++)
                Q *= q;
            for (t = 1; t <= n-m; t++)
                T *= t;
            ar[2] = 1;
            ar[3] = 2;
            if (m == 2)
                printf("%d\n", P / (Q * T));
            else if (m == 3)
                printf("%d\n",  2 * P / (Q * T));
            else
            {
                for (u = 4; u <= m; u++)
                {
                    ar[u] = (ar[u-1] + ar[u-2]) * (u-1);
                }
                printf("%lld\n", ar[u-1] * (P / (Q * T)));
            }
        }
    }
    return 0;
}
