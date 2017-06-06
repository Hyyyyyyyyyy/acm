#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct wen 
{
    int value, weight, num;
};

int main()
{
    int n, m, sum, money, c, i, j, k, u, bag[40010];
    struct wen di[105];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &money, &c);
            snum = 0;
            for(u = 1; u <= c; u++)
            {
                scanf("%d %d %d", &di[u].value, &di[u].weight, &di[u].num);
                snum += di[u].num;
            }
            memset(bag, 0, sizeof(int)*40010);
            sum = 0;
            for(i = 1; i <= c; i++)
            {
                for(k = 1; k <= di[i].num; k++)
                {
                    for(j = money; j >= di[i].value; j--)
                    {
                        if(bag[j] < bag[j-di[i].value]+di[i].value)
                        {
                            bag[j] = bag[j-di[i].value]+di[i].value;
                            sum += di[i].weight;
                        }
                    }
                }
            }
            printf("%d\n", bag[money]);
        }
    }
    return 0;
}
