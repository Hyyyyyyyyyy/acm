#include <stdio.h>
int main()
{
    int n, a, i, u, p, q, temp, d;
    int ar[99999];
    while (scanf("%d", &n) != EOF)
    {
            for (i = 1; i <= n; i++)
            {
            scanf("%d", &a);
            for (u = 0; u < a; u++)
            {
                scanf("%d", &ar[u]);
            }
            for (p = 0; p < a; p++)
            {
                for (q = 0; q < (a - 1 - p); q++)
                {
                    if (ar[q] > ar[q+1])
                    {
                        temp = ar[q+1];
                        ar[q+1] = ar[q];
                        ar[q] = temp;
                    }
                }
            }
            d = 0;
            for (u = 0; u < a; u++)
            {    
                if (d == 1)
                putchar(' ');
                printf("%d", ar[u]);
                d = 1;
            }
            printf("\n");

            }
    }
    return 0;
}
