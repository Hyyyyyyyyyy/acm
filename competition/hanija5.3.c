#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i, j, k, n, m,x, y, set[100010], doudou, count;
    while(scanf("%d", &n) != EOF)
    {
        memset(set, 0, sizeof(set));
        count = 0;
        doudou = 0;
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            memset(set, 0, sizeof(set));
            count = 0;
            doudou = 0;
            for(u = 1; u <= k; u++)
            {
                scanf("%d %d", &x, &y);
                if(x > y)
                {
                    temp = x;
                    x = y;
                    y = temp;
                }
                for(i = x; i <= y; i++)
                {
                    if(set[i] == 1)
                        doudou = 1;
                    set[i] = 1;
                }
                if(doudou)
                {
                    count++;
                    doudou = 0;
                }
            }
            printf("%d\n", count);
        }
    }
    return 0;
}