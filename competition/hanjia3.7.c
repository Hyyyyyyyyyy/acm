#include <stdio.h>
int main()
{
    int i, j, k, m, n, u, ar[1000000], set[1000000];
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(i = 1; i <= m; i++)
            ar[i] = i;
        for(i = m + 1; i <= n; i++)
        {
            scanf("%d", &ar[i]);
        }
        set[1] = 1;
        for(i = 2; i <= n; i++)
        {
            if(ar[m+i-1] == 1)
                set[2] = m+i-1;
            else
            {
                key = ar[m+i-1];
                for(j = m+i-2; j >= i; j--)
                    ar[j+1] = ar[j];
                ar[j] = key;
                set[i] = i;
            }
        }
        for(i = 1; i <= n; i++)
            printf("%d ", set[i]);
        putchar('\n');
    }
    return 0;
}