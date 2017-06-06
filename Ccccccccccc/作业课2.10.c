#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, k, n, m, u;
    double sum, temp;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        sum = (double)n;
        temp = (double)n;
        for(i = 2; i <= m; i++)
        {
            temp = sqrt(temp);
            sum += temp;
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}
