#include <stdio.h>
int main()
{
    int n, m, i, j, u, ar[9999][4], key1, key2, key3, set[105], S, count;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        for (i = 1; i <= n*(n - 1) / 2; i++)
        {
            scanf("%d %d %d %d", &ar[i][0], &ar[i][1], &ar[i][2], &ar[i][3]);
            if (ar[i][3] == 1)
                ar[i][2] = 0;
            key3 = ar[i][2];
            key2 = ar[i][1];
            key1 = ar[i][0];
            j = i - 1;
            while (j > 0 && key3 < ar[j][2])
            {
                ar[j + 1][2] = ar[j][2];
                ar[j + 1][1] = ar[j][1];
                ar[j + 1][0] = ar[j][0];
                j--;
            }
            ar[j + 1][2] = key3;
            ar[j + 1][1] = key2;
            ar[j + 1][0] = key1;
        }
        for (u = 1; u <= 102; u++)
            set[u] = u;
        S = 0;
        count = 0;
        for (u = 1; u <= n*(n - 1) / 2; u++)
        {
            while (set[ar[u][0]] != ar[u][0])
                ar[u][0] = set[ar[u][0]];
            while (set[ar[u][1]] != ar[u][1])
                ar[u][1] = set[ar[u][1]];
            if (ar[u][0] != ar[u][1])
            {
                set[ar[u][1]] = ar[u][0];
                count++;
                S += ar[u][2];
                if (count == (n - 1))
                    break;
            }
        }
        printf("%d\n", S);
    }
    return 0;
}