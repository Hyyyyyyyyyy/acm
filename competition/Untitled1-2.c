#include <stdio.h>
int main()
{
    int n, a, b, c, i, x, count, u;
    int ar[9999];
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            count = 0;
            scanf("%d %d %d", &a, &b, &c);
            for (x = 1000; x <= 9999; x++)
            {
                if (x % a == 0 && (x+1) % b == 0 && (x+2) % c == 0)
                {
                    ar[count] = x;
                    count++;
                }
            }
            if (count == 0)
                printf("Impossible\n");
            else
            {
                for (u = 0; u < count; u++)
                {
                    ar[0] = (ar[0] < ar[u]) ? ar[0]:ar[u];
                }
                printf("%d\n", ar[0]);
            }
        }
    }
    return 0;

}
