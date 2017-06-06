#include <stdio.h>
int main()
{
    int n, u, i;
    long long int ar[999];
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
            printf("1\n");
        else if (n == 2)
            printf("2\n");
        else if (n == 3)
            printf("3\n");
        else
        {
            ar[1] = 1;
            ar[2] = 2;
            ar[3] = 3;
            for (i = 4; i <= n; i++)
            {
                ar[i] = ar[i-1] + ar[i-2];
            }
            printf("%lld\n", ar[i-1]);
        }
    }
    return 0;
}
