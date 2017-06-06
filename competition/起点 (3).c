#include <stdio.h>
int main()
{
    int m, n, i, u, c, doudou, a, b;
    int ar[110], sa[110];
    while(scanf("%d", &a) != EOF)
    {
        for(b = 1; b <= a; b++)
        {
           
            scanf("%d", &m);

            
            scanf("%d", &n);
            {
                doudou = 0;
                for (i = 0; i < m; i++)
                    ar[i] = i + 1;
                c = 0;
                u = 0;
                for (i = 0;; i++)
                {
                    if (i == m)
                        i = 0;
                    if (ar[i] == 0)
                        continue;
                    c++;
                    if (c % n == 0)
                    {
                        sa[u] = ar[i];
                        u++;
                        ar[i] = 0;
                    }
                    if (u == m)
                        break;
                }
                for (i = 0; i < m; i++)
                {
                    if (doudou)
                        printf(", ");
                    printf("%d", sa[i]-1);
                    doudou = 1;
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
