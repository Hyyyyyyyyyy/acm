#include <stdio.h>
int main()
{
    int n, t, i, u;
    long long ar[40];
    while (scanf("%d", &t) != EOF)
    {
        for (i = 1; i <= t; i++)
        {
            scanf("%d", &n);
            if (n == 1)
                printf("1\n");
            else if (n == 2)
                printf("3\n");
            else
            {
                ar[1] = 1;
                ar[2] = 3;
                for (u = 3; u <= n; u++)
                {
                    ar[u] = ar[u-1] + ar[u-2] * 2;
                }
                printf("%lld\n", ar[u-1]);
            }
        }
    }
    return 0;
}
