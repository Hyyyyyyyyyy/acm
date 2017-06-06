#include <stdio.h>
#include <string.h>
struct lose_weight
{
    int happy;
    int ka;
};
int main()
{
    int n, m, i, j, k, u, bag[100010], mka;
    struct lose_weight qq[110];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &qq[m].happy, &qq[m].ka);
        }
        scanf("%d", &mka);
        memset(bag, 0, sizeof(int)*100010);
        for(i = 1; i <= n; i++)
        {
            for(j = qq[i].ka; j <= mka; j++)
            {
                bag[j] = (bag[j] > bag[j-qq[i].ka]+qq[i].happy) ? bag[j]:(bag[j-qq[i].ka]+qq[i].happy);
            }
        }
        printf("%d\n", bag[mka]);
    }
    return 0;
}