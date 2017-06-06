#include <stdio.h>
int main()
{
    int ar[20][20], i, j, k, u, n, m, count;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &ar[i][j]);
            }
        }
        count = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(ar[i][j] == 1)
                {
                    if(ar[i-1][j] == 1)
                        ar[i-1][j] = 2;
                    if(ar[i][j-1] == 1)
                        ar[i][j-1] = 2;
                    if(ar[i+1][j] == 1)
                        ar[i+1][j] = 2;
                    if(ar[i+1][j] == 1)
                        ar[i+1][j] = 2;
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}