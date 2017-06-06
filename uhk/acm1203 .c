#include <stdio.h>
struct offer
{
    int expense;
    double percent;
};
int main()
{
    int n, m, i, j, k, c;
    double bag[41000];
    struct offer sk[10010];
    while(scanf("%d %d", &n, &m) != EOF &&(n != 0 || m != 0))
    {
        for(c = 1; c <= m; c++)
        {
            scanf("%d %lf", &sk[c].expense, &sk[c].percent);
        }
        for(i = 0; i < 41000; i++)
            bag[i] = 1;

        for(i = 1; i <= m; i++)
        {
            for(j = n; j >= sk[i].expense; j--)
            {
                bag[j] = (bag[j] <= bag[j-sk[i].expense]*(1.0-sk[i].percent)) ? bag[j]:(bag[j-sk[i].expense]*(1.0-sk[i].percent));
            }
        }
        printf("%.1f%%\n", (1.0-bag[n])*100.0);
    }
    return 0;
}
