#include <stdio.h>
int main()
{
    int n, i, u, count;
    unsigned long long int ar[610], l, temp, S, T;
    while (scanf("%llu %d", &l, &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%llu", &ar[i]);
        }
        T = 0;
        for (i = 0; i < n; i++)
            T += ar[i];
        if(T < l)
        {
            printf("impossible\n");
            continue;
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                for (u = 0; u < n - 1 - i; u++)
                {
                    if (ar[u] > ar[u+1])
                    {
                        temp = ar[u+1];
                        ar[u+1] = ar[u];
                        ar[u] = temp;
                    }
                }
            }
            S = 0;
            count = 0;
            for (i = n-1; i >= 0; i--)
            {
                S += ar[i];
                count++;
                if (S >= l)
                    break;
            }
            if (S >= l)
                printf("%d\n", count);
        }
    }
    return 0;
}
