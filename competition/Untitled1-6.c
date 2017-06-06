#include <stdio.h>
int main()
{
    int t, n, m, a[1000000], b[1000000], i, u, s, r, p;
    int doudou, count;

    while (scanf("%d", &t) != EOF)
    {
        for (i = 1; i <= t; i++)
        {
            scanf("%d %d %d", &n, &m, &p);
            for (u = 0; u < n; u++)
                scanf("%d", &a[u]);
            for (u = 0; u < m; u++)
                scanf("%d", &b[u]);
            count = 0;
            for (s = 0; s < (n - (m-1)*p); s++)
            {
                doudou = 1;
                for (r = 0; r < m; r++)
                {
                    if (b[r] == (a[s + r*p]))
                        continue;
                    else
                    {
                        doudou = 0;
                        break;
                    }
                }
                if (doudou == 1)
                    count++;
            }
            printf("Case #%d: %d\n", i, count);
        }
    }
    return 0;
}
