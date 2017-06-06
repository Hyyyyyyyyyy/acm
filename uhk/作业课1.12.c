#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, u, temp, n, m;
    long long sum;
    while(scanf("%d", &n) != EOF)
    {
        sum = 1;
        for(m = 0; m < n; m++)
        {
            scanf("%d", &temp);
            if(temp % 2 != 0)
            {
                sum *= temp;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
