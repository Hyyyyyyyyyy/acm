#include <stdio.h>
int main()
{
    int n, m, i, j, count, ar[30001], num[30001];
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &ar[m]);
            num[m] = 1;
        }
        for (i = n; i >= 1; i--)
        {
            for (j = n; j > i; j--)
            {
                if (ar[i] < ar[j] && num[i] < num[j] + 1)
                {
                    num[i] = num[j] + 1;
                }
            }
            
        }
        count = 0;
        for (i = 1; i <= n; i++)
            if (count < num[i])
                count = num[i];
        printf("%d\n", count);
    }
    return 0;
}
