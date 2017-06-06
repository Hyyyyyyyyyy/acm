#include <stdio.h>
#include <math.h>
int main()
{
    int x, y, i, ar[9999];
    long long S, T;

    while (scanf("%d %d", &x, &y) != EOF)
    {
        S = 0;
        T = 0;
        for (i = x; i <= y; i++)
        {
            ar[i] = i;
            if (ar[i] % 2 == 0)
                S += pow(ar[i], 2.0);
            else 
                T += pow(ar[i], 3.0);
        }
        printf("%lld %lld\n", S, T);
    }
    return 0;
}
