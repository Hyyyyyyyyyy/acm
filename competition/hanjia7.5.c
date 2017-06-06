#include <stdio.h>
struct shu
{
    int id;
    int high;
};
int comp(const void * p1,const void * p2);
int main()
{
    int i, j, k, u, n, m, h, d, count;
    struct shu ar[110];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            count = 0;
            scanf("%d %d", &k, &d);
            for(u = 1; u <= k; u++)
            {
                scanf("%d %d", &ar[u].id, &ar[u].high);
            }
            qsort(&ar[1], k, sizeof(struct shu), comp);
            for(i = 1; i < k; i++)
            {
                if(ar[i+1].high - ar[i].high != d)
                {
                    count++;
                }
            }
            printf("%d\n", count);
        }
    }
    return 0;
}
int comp(const void * p1,const void * p2)
{
    return (shu*)p1->id > (shu*)p1->id ? 1:-1;
}
