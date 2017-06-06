#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int i, j, k, n, m, u, a, b, c, x, y, ta, tb, sum;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d %d", &x, &y, &a, &b);
            if((x == 1 && a > 0) || (y == 1 && b > 0) || (x == (x*x - a) / b * y))
            {
                printf("INF\n");
                continue;
            }
            sum=0;
            while(a >= x || b >= y)
            {
                i = a / x;
                j = b / y;
                sum += i;
                sum += j;
                a = a % x + j + i;
                b = b % y + i + j;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
