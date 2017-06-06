#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
int main()
{
    int i, j, k, u, n, m, a, b, c, min, doudou, res, t, p, q;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &a, &b, &c);
            t = c / 4;
            p = t - b;
            q = (2*t - a) / 2;
            res = t - p - q;
            printf("%d\n", res);
        }
    }
    return 0;
}
