#include <stdio.h>
int main()
{
    int i, j, k, u, n, m;
    char ar[20];
    while(scanf("%d", &n)!= EOF && n)
    {
        scanf("%d", &k);
        
        for(i = 0; i < k; i++)
        {
            ar[i] = '0';
        }
        puts(ar);
        for(i = 0; i < k; i++)
        {
            for(j = i; j < k; j++)
            {
                for(u = j; u < k; u++)
                {
                    ar[u] = '1';
                }
                puts(ar);
            }
            
        }
    }
    return 0;
}