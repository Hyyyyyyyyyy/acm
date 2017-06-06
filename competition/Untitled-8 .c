#include <stdio.h>
int F(unsigned long long int p);
int main()
{
    int n, m;
    unsigned long long int a, b;
    while (scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%llu", &a);
            printf("%llu\n", F(a));
        }
    }
    return 0;
}

unsigned long long int F(unsigned long long int p)
{
    unsigned long long int snum;
    int doudou1 = 1, doudou2 = 1, i;
    for (snum = p-1; snum > 0; snum--)
    {
        for (i = 2; (i * i)  <= snum; i++)
            if(snum % i == 0)
                doudou1 = 0;
                break;
        if(doudou1 == 1)
            break;
    }
    max = snum;
    for (snum = p+1;; snum++)
    {
        for (i = 2; (i * i)  <= snum; i++)
            if(snum % i == 0)
                doudou = 0;
                break;
        if(doudou2 == 1)
            break;
    }
    max = (max > snum) ? max:snum;

return max;
}