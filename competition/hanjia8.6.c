#include <stdio.h>
#include <stdlib.h>
int comp(const void * p1, const void * p2);
int main()
{
    int i, j, k, u, n, m, a, b, cost, ar[1010], sa[1010], sf[1010];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &a, &b);
            sa[0] = 0;
            for(i = 1; i <= b; i++)
            {
                scanf("%d", &ar[i]);
                sa[i] = ar[i] + sa[i-1];
            }
            qsort(&ar[1], b, sizeof(int), comp);
            for(i = 1; i <= b; i++)
            {
                sa[i] = ar[i] + sa[i-1];
            }
            if(b == 1)
                printf("0\n");
            else if(b == 2)
                printf("%d\n", a);
            else
            {
                sf[0] = 0;
                sf[1] = 0;
                sf[2] = a;
                for(i = 3; i <= b; i++)
                {
                    sf[i] = sf[sa[b]/2] + sf[i - sa[b]/2];
                }
                printf("%d\n", sf[b]);
            }
        }
    }
    return 0;
}
int comp(const void * p1, const void * p2)
{
    return *(int *)p1 - *(int *)p2;
}