#include <stdio.h>
int main()
{
    int n, i;
    long long int ar[9999], sa[9999];
    while (scanf("%d", &n) != EOF)
    {
        ar[1] = 2;
        ar[2] = 4;
        sa[1] = 0;
        sa[2] = 1;
        if (n == 1)
            printf("2\n");
        else if (n == 2)
            printf("4\n");
        else
        {
            for (i = 3; i <= n; i++)
            {
            	sa[i] = sa[i-1] + i - 1;
                ar[i] = ar[i-1] + sa[i] + 1;
            }
            printf("%lld\n", ar[i-1]);
        }
    }
    return 0;
}
