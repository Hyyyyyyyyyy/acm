#include <stdio.h>
#include <string.h>
struct moive
{
    int time;
    int value;
};
int main()
{
    int n, m, i, j, k, u, bag[120][1200], mtime, mnum, c;
    struct moive duoduo[120];
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &c, &mnum, &mtime);
            for (u = 1; u <= c; u++)
            {
                scanf("%d %d", &duoduo[u].time, &duoduo[u].value);
            }
            for (i = 0; i < 120; i++)
            {
                for (j = 0; j < 1200; j++)
                    bag[i][j] = -10000000;
            }
            for (j = 0; j < 1200; j++)
                bag[0][j] = 0;
            for (i = 1; i <= c; i++)
            {
                for (j = mnum; j >= 1; j--)
                {
                    for (k = mtime; k >= duoduo[i].time && k >= 0; k--)
                        bag[j][k] = (bag[j][k] > bag[j - 1][k - duoduo[i].time] + duoduo[i].value) ? bag[j][k] : (bag[j - 1][k - duoduo[i].time] + duoduo[i].value);
                }
            }
            if (bag[mnum][mtime] < 0)
                bag[mnum][mtime] = 0;
            printf("%d\n", bag[mnum][mtime]);
        }
    }
    return 0;
}