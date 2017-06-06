#include <stdio.h>
int Find(int a, int * b, int *c);
int main()
{
    int n, m, i, j, k, u, c, temp, ar[10010], r[10010], cas, max, maxi, maxj, sum;
    while(scanf("%d", &n) != EOF)
    {
        cas = 0;
        for(m = 1; m <= n; m++)
        {
            cas++;
            scanf("%d", &c);
            for(i = 1; i <= c; i++)
            {
                scanf("%d", &ar[i]);
            }
            max = -99999;

            for(i = c; i >= 1; i--)
            {
               for(j = 1; j <= i; j++)
               {
                   sum = 0;
                   for(k = j; k <= i; k++)
                   {
                       sum += ar[k];
                   }
                   if(max < sum)
                   {
                       max = sum;
                       maxi = i;
                       maxj = j;
                   }
               }
            }
            printf("Case %d:\n", cas);
            printf("%d %d\n", max, maxj, maxi);
        }
    }
    return 0;
}





#include <stdio.h>
int Find(int a, int * b, int *c);
int main()
{
    int n, m, i, j, k, u, c, temp, ar[10010], r[10010], cas, max, maxi, *p, *q;
    while(scanf("%d", &n) != EOF)
    {
        cas = 0;
        for(m = 1; m <= n; m++)
        {
            cas++;
            scanf("%d", &c);
            for(i = 1; i <= c; i++)
            {
                scanf("%d", &ar[i]);
                r[i] = -99999;
            }
            max = -99999;
            r[1] = ar[1];
            p = r;
            q = ar;

            for(i = c; i >= 1; i--)
            {
                temp = Find(i, q, p);
                if(max < temp)
                {
                    max = temp;
                    maxi = i;
                }
            }
            printf("Case %d:\n", cas);
            printf("%d %d\n", max, maxi);
        }
    }
    return 0;
}


int Find(int a, int * b, int *c)
{
    int m, i, temp;
    m = -99999;
    if(c[a] > -99999)
        return c[a];
    for(i = a-1; i >= 1; i--)
    {
        temp = Find(i, b, c);
        m = (m > temp) ? m:temp;
    }
    c[a] = m + b[a];
    return c[a];
}
