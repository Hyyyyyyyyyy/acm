#include <stdio.h>
#include <stdlb.h>
#include <string.h>
struct ss
{
    char a[110];
};
int comp(const void * p1,const void * p2);
int main()
{
    int i, j, k, n, m, u;
    struct ss ar[100];
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            for(u = 0; u < k; u++)
            {
                scanf("%s", ar[u].a);
            }
            qsort(ar, k, sizeof(ar), comp);
            for(i = 0; i < k; i++)
            {
                printf("%s", ar[i].a);
            }
            putchar('\n');
        }
    }
    return 0;
}
int comp(const void * p1,const void * p2)
{
    return strcmp((ss*)p1->str, (ss*)p2->str);
}
