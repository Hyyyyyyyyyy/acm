#include <stdio.h>
#include <stdlib.h>
int comp(const void * p1, const void * p2);
int main()
{
    int n, m, i, k, j, u, ar[1005];
    while(scanf("%d %d %d", &n, &m, &k) != EOF)
    {
        for(i = 1; i <= n; i++)
            scanf("%d", &ar[i]);
        qsort(&ar[1], n, sizeof(int), comp);
        if((k*(k-1)/2)+m > ar[1])
            printf("Yes\n");
        else
            printf("Impossible\n");
    }
    return 0;
}

int comp(const void * p1, const void * p2)
{
    return *(int *)p2 - *(int *)p1;
}
