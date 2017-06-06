#include <stdio.h>
struct cloth
{
    int x;
    int y;
    int value;
};
int main()
{
    int n, m, c, i, j, k, u, mx, my, bag[1010][1010];
    struct cloth girl[20];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &c, &mx, &my);
            for(u = 1; u <= c; u++)
            {
                scanf("%d %d %d", &girl[u].x, &girl[u].y, girl[u].value);
            }
            memset(bag, 0, sizeof(int)*1010*1010);
            for(i = 1; i <= c; i++)
            {
                for(j = mx; j >= girl[i].x; j--)
                {
                    for(k = my; k >= girl[i].y; k--)
                    {
                        bag[j][k] = (bag[j][k] > bag[j-girl[i].x][k-girl[i].y] + girl[i].value) ? bag[j][k]:(bag[j-girl[i].x][k-girl[i].y] + girl[i].value);
                    }
                }
            }
            printf("%d\n", bag[mx][my]);
        }
    }
    return 0;
}