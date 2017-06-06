#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, n, m, u, temp, flag;
    long long sum;
    while(scanf("%d", &n) != EOF)
    {
    	flag = 0;
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &u);
            sum = 0;
            for(j = 0; j < u; j++)
            {
                scanf("%d", &temp);
                sum += temp;
            }
            if(flag)
                putchar('\n');
            flag = 1;
            printf("%lld\n", sum);
        }
    }
    return 0;
}