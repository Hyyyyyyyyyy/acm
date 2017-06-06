#include <stdio.h>
int main()
{
    int t, count, i;
    long long int n, m;
    while (scanf("%d", &t) != EOF)
    {
        for (i = 1; i <= t; i++)
        {
            scanf("%lld %lld", &n, &m);
            count = 0;
            while (m > 0 && n > 0)
            {
                if (m > n)
                {
                    m = m - n;
                    count++;
                }
                else if (m < n)
                {
                    n = n - m;
                    count++;
                }
                else
                {
                    count = count + 2;
                    break;
                }
            }
            printf("%d\n", count);
        }
    }
    return 0;
}
