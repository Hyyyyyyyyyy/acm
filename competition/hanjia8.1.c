#include <stdio.h>

int main()
{
    int i, j, k, u, n, m, L;
    double x, y, l, sum;
    while(scanf("%d %d %lf", &n, &m, &x) != EOF)
    {
        sum = 0.0;
        for(i = n; i >= m; i--)
        {
            sum += pow(x, i) * pow(1 - x, n - i);
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}