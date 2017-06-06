#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int i, j, k, u, n, m, a, b, c;
    double x, Y;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%lf", &Y);
            if (Y < 6 || Y >(8 * 100000000 + 7 * 1000000 + 2 * 10000 + 3 * 100 + 6))
            {
                printf("No solution!\n");
                continue;
            }
            double l = 0;
            double r = 100;
            double mid = (l + r) / 2.0;
            while (r - l > 1e-6)
            {
                if (8 * mid*mid*mid*mid + 7 * mid*mid*mid + 2 * mid*mid + 3 * mid + 6 < Y)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
                mid = (l + r) / 2.0;
            }
            printf("%.4lf\n", mid);
        }
    }
    return 0;
}
