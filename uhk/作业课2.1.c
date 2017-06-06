#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
    int temp;
    while(b)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int main()
{
    int i, j, k, u, temp, sum, S, a, b, ar[1000010], n, m, max;
    long long ming;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            max = 0;
            for(i = 1; i <= k; i++)
            {
                scanf("%d", &ar[i]);
                max = (max < ar[i]) ? ar[i]:max;
            }
            ming = max;
            for(i = 1; i <= k; i++)
            {
                if(ar[i] < max)
                {
                    if(max % ar[i] != 0)
                    {
                        ming = ming * ar[i] / gcd(ming, ar[i]);
                    }
                }
            }
            printf("%d\n", ming);
        }
    }
    return 0;
}