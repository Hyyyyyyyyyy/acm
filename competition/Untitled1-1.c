#include <stdio.h>
int main()
{
    int n, i, count;
    long long int ar[300], S;
    while (scanf("%d", &n) != EOF && n > 0)
    {
        S = 0;
        count = 1;
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &ar[i]);
        }
        for (i = 0; i < n; i++)
            S += ar[i];
        printf("Sum of #%d is %lld\n", count, S);
        count++;
    }
    return 0;
}
