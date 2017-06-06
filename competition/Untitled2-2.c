#include <stdio.h>
int main()
{
    int n, m, i, ar[1005], temp, u;
    long long int S;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &ar[i]);
        }
        for (i = 1; i <= n; i++)
        {
            if (ar[1] < ar[i])
            {
                temp = ar[1];
                ar[1] = ar[i];
                ar[i] = temp;
            }
        }
        for (u = 1; u <= n; u++)
            S += ar[u];
        if(S%ar[0] == 0)
            printf("%d/%d\n", (S%ar[0]+1), S/ar[0]);
        else
            printf("%d/%d\n", S%ar[0], S/ar[0])
    }
    return 0;
}
