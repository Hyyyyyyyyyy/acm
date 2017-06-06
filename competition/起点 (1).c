#include <stdio.h>
#include <string.h>
int main()
{
    int n, m, i, j, *p, *q, ar[100010], set[100010], sa[100010], doudou;
    while (scanf("%d", &n) != EOF)
    {
        for(m = 1; m<= n; m++)
        {
            scanf("%d", &i);
            memset(set, 0, sizeof(int)*100010);
            memset(sa, 0, sizeof(int)*100010);
            for(j = 1; j<= i; j++)
            {
                scanf("%d", &ar[j]);
                if(ar[j] >= 0)
                    set[ar[j]]++;
                else
                    sa[(-1)*ar[j]]++;
            }
            doudou = 0;
           for(i = 0; i < 100010; i++)
            {
                if(set[i]%2 != 0 && doudou == 1)
                {
                    printf("No\n");
                    doudou = 2;
                    break
                }
                else if(set[i]%2 != 0 && doudou == 0)
                {
                    doudou = 1;
                }
            }
            if(doudou == 2)
                continue;
            for(i = 0; i < 100010; i++)
            {
                if(sa[i]%2 != 0 && doudou == 1)
                {
                    printf("No\n");
                    doudou = 2;
                    break;
                }
                else if(sa[i]%2 != 0 && doudou == 0)
                {
                    doudou = 1;
                }
            }
            if(doudou != 2)
            printf("Yes\n");
        }
    }
    return 0;
}
