#include <stdio.h>
int main()
{
    int n, i;
    long long int ar[999];
    while (scanf("%d", &n) != EOF)
    {
        ar[1] = 3;
        ar[2] = 6;
        ar[3] = 6;
        if (n == 1)
            printf("3\n");
        else if (n == 2)
            printf("6\n");
        else if (n == 3)
            printf("6\n");
        else
        {
            for (i = 4; i <= n; i++)
            {
                ar[i] = ar[i-1] + 2 * ar[i-2];
            }
            printf("%lld\n", ar[i-1]);
        }

    }
    return 0;
}
