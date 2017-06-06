#include <stdio.h>
int main()
{
    int n, i, ar[9999];
    long long T;
    while (scanf("%d", &n) != EOF)
    {
        T = 1;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &ar[i]);
            if(ar[i] % 2 != 0)
                T *= ar[i];
        }
        printf("%lld\n", T);

    }
    return 0;
}
