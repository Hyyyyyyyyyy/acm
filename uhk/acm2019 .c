#include <stdio.h>
int main()
{
    int n, m, ar[9999], temp, i, u, doudou;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (m == 0 && n == 0)
            break;
        for (i = 0; i < n; i++)
            scanf("%d", &ar[i]);
        for (u = 0; u <= (n-1); u++)
        {
            for(i = 0; i < (n-1-u); i++)
            if (ar[i] > ar[i+1])
            {
                temp = ar[i+1];
                ar[i] = ar[i+1];
                ar[i] = temp;
            }
        }
        ar[n] = m;
        for (u = (n - 1); u >= 0; u--)
        {
            if (ar[u+1] < ar[u])
            {
                temp = ar[u];
                ar[u] = ar[u+1];
                ar[u+1] = temp;
            }
            else
                break;
        }
        doudou = 0;
        for (u = 0; u < (n + 1); u++)
        {
        	if (doudou)
        		putchar(' ');
            printf("%d", ar[u]);
            doudou = 1;
        }
        putchar('\n');
    }
    return 0;
}
