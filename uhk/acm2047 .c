#include <stdio.h>
int main()
{
    int n, i;
    long long ar[999], sa[999];
    while (scanf("%d", &n) != EOF)
    {
        if (n == 1)
            printf("3\n");
        else if (n == 2)
            printf("8\n");
        else
        {
            ar[1] = 3;
            ar[2] = 8;
            sa[1] = 1;
            sa[2] = 2;
            for (i = 3; i <= n; i++)
            {
                sa[i] = ar[i-1] - sa[i-1];
                ar[i] = 3 * ar[i-1] - sa[i-1];
            }
            printf("%lld\n", ar[i-1]);
        }
    }
    return 0;
}
