#include <stdio.h>
int main()
{
    double a, b, c;
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lf %lf %lf", &a, &b, &c);
            printf("%.6lf\n", 0.25*a+0.25*b-0.5*c);
        }
    }
    return 0;
}
