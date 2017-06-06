#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, i, u, k;
    int sa, sf[100][100];

    while (scanf("%d %d", &n, &m) != EOF)
    {
    	sa = 0;
        for (i = 1; i <= n; i++)
        {
            for (u = 1; u <= m; u++)
            {
                scanf("%lld", &sf[i][u]);
                sa = (abs(sa) > abs(sf[i][u])) ? sa:sf[i][u];
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (u = 1; u <= m; u++)
            {
                if (sa == sf[i][u])
                    break;
            }
            if (sa == sf[i][u])
                break;
        }
        printf("%d %d %d\n", i, u, sa);
    }
    return 0;
}
