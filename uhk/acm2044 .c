#include <stdio.h>
int main()
{
    int n, a, b, c, i, u;
	long long int ar[9999];
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            scanf("%d %d", &a, &b);
            c = b - a;
            if (c == 1)
                printf("1\n");
            else if (c == 2)
                printf("2\n");
            else
            {
                ar[0] = 1;
                ar[1] = 2;
                for (u = 2; u < c; u++)
                {
                    ar[u] = ar[u-1] + ar[u-2];
                }
                printf("%lld\n", ar[c-1]);
            }
        }
    }
    return 0;
}
