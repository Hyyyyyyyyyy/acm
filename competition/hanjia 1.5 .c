#include <stdio.h>
int main()
{
    int n, m, i, j, k, u;
    long long sum;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            sum = 0;
            scanf("%d", &k);
            for(i = 1; i <= k; i++)
            {
                sum += (i*i) % 10;
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}