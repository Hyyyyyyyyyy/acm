#include <stdio.h>
int main()
{
    int ar[5][6], i, u, max[5];

    for (u = 0; u < 5; u++)
        for (i = 0; i < 6; i++)
            scanf("%d", &ar[u][i]);
    for (u = 0; u < 5; u++)
        for (i = 0; i < 6; i++)
            max[u] = (abs(ar[u][i]) > abs(ar[u][i+1])) ? ar[u][i]:ar[u][i+1]);
    for (i = 0; i < 5; i++)
        max[0] = (max[0] > max[i]) ? max[0]:max[i];
    for (u = 0; u < 5; u++)
        for (i = 0; i < 6; i++)
            if (max[0] == ar[u][i])
                printf("max = %d, row = %d, line = %d\n", max[0], u, i);

    return 0;
}
