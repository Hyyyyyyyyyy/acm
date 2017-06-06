#include <stdio.h>
int main()
{
    int n, m, a, b, L, count;
    unsigned long long int ar;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            scanf("%llu", &ar);
            count = 0;
            for(u = 1; u <= ar; u++)
            {
                while (u>0)
                {
                    if(u % 2 == 0)
                    {
                        count++;
                        u /= 2;
                    }
                }
                
            }
            printf("%d\n", count);
        }
    }
    return 0;
}
