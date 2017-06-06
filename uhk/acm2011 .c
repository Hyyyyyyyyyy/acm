#include <stdio.h>
#include <math.h>
int main()
{
    int m, n, i, u;
    double S;
    while (scanf("%d", &m) != EOF)
    {
        for (i = 1; i <= m; i++)
        {
            scanf("%d", &n);
            S = 0.0;
            for (u = 1; u <= n; u++)
                S += (1.0 / u) * pow(-1.0, (u + 1));
            printf("%.2lf\n", S);
        }
    }
    return 0;
}
