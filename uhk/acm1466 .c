#include <stdio.h>
int main()
{
    int n, i, u, p, a, k, q, temp;
    int S[30][17000], c[30];
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
            printf("0\n");
        else if (n == 2)
            printf("0 1\n");
        else
        {
            S[0][0] = 0;
            S[1][0] = 0;
            S[2][0] = 1;
            S[2][1] = 1;
            c[1] = 1;
            c[2] = 2;
            for (u = 3; u <= n; u++)
            {
                a = 0;
                for (i = 0; i < u; i++)
                {
                    for (p = 0; p <= c[i]; p++)
                    {
                        S[u][a] = (u - i) * i + S[i][p];
                        a++;
                    }
                }
                c[u] = a;
            }
            
            for (i = 0; i < c[u-1]; i++)
            {
                for (k = 0; k < c[u-1] - i - 1; k++)
                {
                    if (S[u-1][k] > S[u-1][k+1])
                    {
                        temp = S[u-1][k+1];
                        S[u-1][k+1] = S[u-1][k];
                        S[u-1][k] = temp;
                    }
                }
            }
            //合并
            for (i = 0; i < c[u-1]; i++)
            {
                for (k = (i+1); k < c[u-1]; k++)
                {
                    if (S[u-1][i] == S[u-1][k])
                        S[u-1][k] = -1;
                }
            }
            //打印
            for (i = 0; i < c[u-1]; i++)
            {
                if (S[u-1][i] == -1)
                    continue;
                printf("%d ", S[u-1][i]);
            }
            putchar('\n');
        }
    }
    return 0;
}
