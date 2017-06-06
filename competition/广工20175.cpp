#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int Two_Count(int a);
int main()
{
    int i, j, k, u, n, m, a, b, c, res, x;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &a, &b);
            res = 0;
            while(Two_Count(a) > b)
            {
                x = 1;
                while((a & x) == 0)
                {
                    x <<= 1;
                }
                res += x;
                a += x;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
int Two_Count(int a)
{
    int i, j, k, c;
    c = 0;
    while(a)
    {
        if(a & 1)
            c++;
        a >>= 1;
    }
    return c;
}
