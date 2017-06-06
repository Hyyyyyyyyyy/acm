#include <stdio.h>
int main()
{
    int n, m, i, u;
    long long int ar[999];

    while (scanf("%d", &n) != EOF)
    {
        ar[1] = 1; 
        ar[2] = 2;
        ar[3] = 3;
        for(i = 4; i <= n; i++)
        {
            ar[i] = ar[i-1] + ar[i-3] + 1;

        }
        printf("%lld\n", ar[n]);
    }
    return 0;
}