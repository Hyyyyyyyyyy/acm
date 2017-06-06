#include <stdio.h>
double calculate(double *a, double *b);
int main()
{
    int n, m, i, u;
    double ar[3005], c[3005], *p, *q, A1;
    for(i = 0; i < 3005; i++)
        ar[i] = 0;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%lf %lf", &ar[0], &ar[n+1]);
        for(m = 1; m <= n; m++)
            scanf("%lf", &c[m]);
        p = &ar[0];
        q = &c[1];
        A1 = calculate(q, p);
        printf("%.2lf\n", A1);
    }
    return 0;
}

double calculate(double *a, double *b)
{
    if(*(b+2) != 0)
        return ((*b + *(b+2))/2.0 - *a);
    else
        return ((*b + calculate(a+1, b+1))/2.0 - *a));
}
