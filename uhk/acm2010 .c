#include <stdio.h>
#include <math.h>
int main()
{
    int m, n, i, t, u, doudou;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        doudou = 0;
        for (i = m; i <= n; i++)
        {
            u = i;
            t = 0;
            while (u != 0)
            {
                t += (u % 10) * (u % 10) * (u % 10);
                u = u / 10;
            }
            if (i == t)
            {
                if (doudou == 1)
                    putchar(' ');
                printf("%d", i);
                doudou = 1;
            }
        }
        if (doudou == 0)
                printf("no");
        putchar('\n');
    }
    return 0;
}
