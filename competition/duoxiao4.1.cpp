#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef unsigned long long ll;
const int maxn = 500000 + 10;
int main()
{
    int i, j, k, u, n, m;
    ll D1, D2, D3, D4, K;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%lld %lld %lld %lld", &K, &D1, &D2, &D3, &D4);
            ll t = INF;
            ll t1 = (D2 * 4 - K);
            if(t1 < 0)
                t = INF;
            t = min(t, t1);
            t1 = (D1 * 4 - K);
            if(t1 < 0)
                t1 = INF;
            t = min(t1, t);
            t1 = (D1 + D4) * 2 - K;
            if(t1 < 0)
                t1 = INF;
            t = min(t, t1);
            t1 = (D1 + D2 + D3 + D4) - K;
            if(t1 < 0)
                t1 = INF;
            t = min(t1, t);
            t1 = (D2 + D3) * 2 - K;
            if(t1 < 0)
                t1 = INF;
            t = min(t, t1);
            printf("%lld\n", t+K);
        }
    }
    return 0;
}