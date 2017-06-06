#include <stdio.h>
#include <stdlib.h>
int comp(const void * p1, const void * p2);
int main()
{
    int n, m, i, j, k, u, ar[999], row, line;
    while(scanf("%d", &n) != EOF)
    {
        for(m=1; m<= n; m++)
        {
            scanf("%d %d", &row, &line);
            k = 0;
            for(i=1; i <= row; i++)
            {
                for(j = 1; j<= line; j++)
                {
                    scanf("%d", &ar[k]);
                    k++;
                }
            }
            qsort(ar, i*j, sizeof(int), comp);
            
            k = 0;
            for(i = 1; i <= row; i++)
            {
                for(j = 1; j<= line; j++)
                {
                    if((line+1)%j == line)
                        putchar('\n');
                    printf("%d ", ar[k]);
                    k++;
                }
            }
        }
    }
    return 0;
}

int comp(const void * p1, const void * p2)
{
    const int * a1 = (const int *)p1;
    const int * a2 = (const int *)p2;

    if(*a1 < *a2)
        return -1;
    else if(*a1 == *a2)
        return 0;
    else
        return 1;
}