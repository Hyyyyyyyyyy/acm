#include <stdio.h>
#include <math.h>

int main()
{
    long long int i, j, k, n, m, u, max, temp, sum;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lld", &k);
            sum = 0;
            max = 0;
            for(i = 1; i <= k; i++)
            {
                scanf("%lld", &temp);
                max = (max < temp) ? temp:max;
                sum += temp;
            }
            if(max - 1 <= sum - max)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}