#include <stdio.h>
int main()
{
    int n, m, ave, a, b, u, i, d, S;
    int ar[100], sa[100];
    for (i = 0; i < 100; i++)
        ar[i] = 2 * (i + 1);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        d = 0;
        a = n / m;
        b = n % m;
        for(u = 0; u < a; u++)
        {
        	S = 0;
            ave = 0;
            for (i = (0 + m * u); i < (m + m * u); i++)
                S += ar[i];
            ave = S / m;
            sa[u] = ave;
        }
        if (b != 0)
        {
        	S = 0;
            ave = 0;
            for (u = (n - 1); u > (n - 1 - b); u--)
                S += ar[u];
            ave = S / b;
            sa[a] = ave;
            for (u = 0; u < (a + 1); u++)
            {
                if (d == 1)
                putchar(' ');
                printf("%d", sa[u]);
                d = 1;
            }
        }
        else
        {
            for (u = 0; u < a; u++)
            {
                if (d == 1)
                putchar(' ');
                printf("%d", sa[u]);
                d = 1;
            }
        }
        putchar('\n');
    }
    return 0;
}
