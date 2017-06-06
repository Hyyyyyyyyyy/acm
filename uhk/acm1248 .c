#include <stdio.h>
#include <string.h>

int main()
{
    int n, m,i, j, k, u, bag[10010], ar[4], money;
    while(scanf("%d", &n) != EOF)
    {
        ar[1] = 150;
        ar[2] = 200;
        ar[3] = 350;
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &money);
            memset(bag, 0, sizeof(int)*10010);
            for(i = 1; i <= 3; i++)
            {
                for(j = ar[i]; j <= money; j++)
                {   
                    bag[j] = (bag[j] > bag[j - ar[i]] + ar[i]) ? bag[j] : bag[j - ar[i]] + ar[i];
                }
            }
            printf("%d\n", money-bag[money]);
        }

    } 
    return 0;
}