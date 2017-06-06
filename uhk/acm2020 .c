#include <stdio.h>
#include <math.h>
int main()
{
    int n, a, i, u, p, q, temp, d;
    int ar[99999];
    while(scanf("%d", &a) != EOF)
    {
        if (a == 0)
            break;
        else
        {
            for (u = 0; u < a; u++)
            {
                scanf("%d", &ar[u]);
            }
            for (p = 0; p < a; p++)
            {
                for (q = 0; q < (a - 1 - p); q++)
                {
                    if (abs(ar[q]) > abs(ar[q+1]))
                    {
                        temp = ar[q+1];
                        ar[q+1] = ar[q];
                        ar[q] = temp;
                    }
                }
            }
            d = 0;
            for (u = (a - 1); u >= 0; u--)
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
