#include <stdio.h>
int main()
{
    int i,j;
    double n,m, p, k;
    while (scanf("%d", &i) != EOF)
    {
        for(j = 1; j <= i; j++)
        {
            scanf("%lf %lf %lf %lf", &n, &m, &p, &k);
            if(n/m >= p/k)
                printf("iphone 5S\n");
            else
                printf("iphone 5C\n");
        }
    }
    return 0;
}
