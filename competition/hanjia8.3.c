#include <stdio.h>
#include <math.h>
int main()
{
    long long int a, b, c, d, i, j, k, u, n, m, min, minx, miny, max,maxx, maxy, sum, S;
    while(scanf("%lld", &n) != EOF)
    {
        min = 10000000;
        max = -1;
        sum = 0;
        for(m = 1; m <= n; m++)
        {
            scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
            sum += abs((c-a)*(d-b));
            if(min > a+b)
            {
                min = a+b;
                minx = a;
                miny = b;
            }
            if(max < c + d)
            {
                max = c + d;
                maxx = c;
                maxy = d;
            }
        }
        if((maxx-minx)*(maxy-miny) == sum && (maxx-minx == maxy - miny))
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
