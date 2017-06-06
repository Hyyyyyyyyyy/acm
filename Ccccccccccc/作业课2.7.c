#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d %d", &n, &m) != EOF && (n || m))
    {
        long long res, temp;
        res = 1;
        while(m)
        {
            if(m % 2 != 0)
            {
                res *= n;
                res %= 1000;
            }
            n *= n;
            n %= 1000;
            m /= 2;
        }
        printf("%d\n", res);
    }
    return 0;
}