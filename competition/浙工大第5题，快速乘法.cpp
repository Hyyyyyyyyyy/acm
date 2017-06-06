#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
long long MUL(long long a, long long b, long long c);
int main()
{
    int i, j, k, n, m, u;
    long long ar[100010], res, S, T, temp;
    while(scanf("%d", &n) != EOF)
    {
        for(m =  1; m <= n; m++)
        {
            scanf("%d", &k);
            S = 0;
            T = 1;
            for(u = 1; u <= k; u++)
            {
                scanf("%lld", &ar[u]);
                S += ar[u];
            }
            res = ar[1];
            for(i = 2; i <= k; i++)
            {
                res = MUL(res, ar[i], S);
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}
long long MUL(long long a, long long b, long long c)
{
    long long res = 0, temp, i, k;
    while(b)
    {
        if(b % 2)
        {
            res = (res + a) % c;
        }
        a = (a + a) % c;
        b /= 2;
    }
    return res;
}