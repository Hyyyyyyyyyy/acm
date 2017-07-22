#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, k, m;
    unsigned long long res, temp, n;
    while(scanf("%d", &m) != EOF)
    {
        for(i = 1; i <= m; i++)
        {
            scanf("%llu", &n);
            res = 1;
            temp = n;
            temp %= 10;
            while(n)
            {
                if(n % 2)
                {
                    res *= temp;
                    res %= 10;
                }
                temp *= temp;
                temp %= 10;
                n /= 2;
            }
            printf("%llu\n", res);
        }
    }
    return 0;
}
