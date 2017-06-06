#include <stdio.h>
#include <math.h>
int main()
{
    int n, m, i;
    double S;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        S = n;
        for (i = 2; i <= m; i++)
        {
            S += pow(n, pow((1.0 / 2), (i - 1)));
        }
        printf("%.2lf\n", S);
    }
    return 0;
}
