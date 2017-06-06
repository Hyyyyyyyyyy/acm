#include <stdio.h>
int main()
{
    int a, b, c, n, i, ar[105], S;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        S = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &ar[i]);
            S += ar[i]/100;
            if(ar[i]%100 != 0)
            {
                S += (ar[i]%100)/50;
                if (ar[i]%50 != 0)
                {
                    S += (ar[i]%50)/10;
                    if (ar[i]%10 != 0)
                    {
                        S += (ar[i]%10)/5;
                        if (ar[i]%5 != 0)
                        {
                            S += (ar[i]%5)/2;
                            if(ar[i]%2 != 0)
                            {
                                S += ar[i]%2;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", S);
    }
    return 0;
}
