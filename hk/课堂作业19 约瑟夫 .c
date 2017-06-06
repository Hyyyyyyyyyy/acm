#include <stdio.h>
int main()
{
    int m, n, i, u, c, doudou;

    printf("Please enter the number of people:\n");
    scanf("%d", &m);
    int ar[m], sa[m];

    printf("Please choose the division:\n");
    while (scanf("%d", &n) != EOF)
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
            printf("%d", sa[i]);
            doudou = 1;
        }
    }
    return 0;
}
