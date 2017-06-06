#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int i, j, k, u, n, m, a, b, c,res;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &a, &b, &c);
            res = a * b;
            res += (a / 30) * c;
            printf("%d\n", res);
        }
    }
    return 0;
}
