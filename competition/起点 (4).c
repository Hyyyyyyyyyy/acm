#include <stdio.h>
int main()
{
    int n, m, i, j, k, l, ar[999][999];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &a, &b);
            for(i = 1; i<= a; i++)
            {
                for(j = 1; j<= b; j++)
                {
                    scanf("%d", &ar[i][j]);
                }
            }
            p = &ar[a][b];
            for(i = a; i >= 1; i--)
            {
                for(j = b; b >= 1; j--)
                {
                    if(ar[i-1][j] == 0 && ar[i][j-1] == 0)
                    {
                        
                    }
                    if(ar[i][j-1] == 1)
                    {
                        p = &ar[i-1][j];
                    }
                    else
                        p = &ar[j-1][i];
                }
            }
        }
    }
}
