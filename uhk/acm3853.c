#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
    int i, j, k, u, n, m;
    double a, b, c, ar[1002][1002][3], bag[1002][1002];
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                scanf("%lf %lf %lf", &ar[i][j][0], &ar[i][j][1], &ar[i][j][2]);
            }
        }
        memset(bag, 0, sizeof(bag));
        for (i = n; i > 0; i--)
        {
            for (j = m; j > 0; j--)
            {
                if (i == n && j == m)
                    continue;
                if (fabs(1 - ar[i][j][0]) < 1e-8)
                    continue;
                bag[i][j] = (bag[i + 1][j] * ar[i][j][2] + bag[i][j + 1] * ar[i][j][1] + 2.0) / (1.0 - ar[i][j][0]);
            }
        }
        printf("%.3lf\n", bag[1][1]);
    }
    return 0;
}