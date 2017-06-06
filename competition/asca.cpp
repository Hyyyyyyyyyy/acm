#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
typedef long long ll;
ll ar[300][2], sa[300][2];
int main()
{
    ll i, j, k, u, n, m, a, b, p, q, x, y, max, min, flag, res;
    while(scanf("%lld", &p) != EOF)
    {
        for(q = 1; q <= p; q++)
        {
            scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
            for(i = 1; i <= x; i++)
            {
                scanf("%lld %lld", &ar[i][0], &ar[i][1]);
            }
            for(i = 1; i <= y; i++)
            {
                scanf("%lld %lld", &sa[i][0], &sa[i][1]);
            }
            res = 0;
            for(i = 1; i <= x; i++)
            {
                for(j = 1; j <= y; j++)
                {
                    if(ar[i][0] <= sa[j][0] && ar[i][1] >= sa[j][1])
                    {
                        if(sa[j][1] - sa[j][0] + 1 >= m)
                        {
                            res += sa[j][1] - sa[j][0] + 1 - m + 1;
                        }
                    }
                    else if(ar[i][0] <= sa[j][0] && ar[i][1] < sa[j][1])
                    {
                        if(ar[i][1] - sa[j][0] + 1 >= m)
                        {
                            res += ar[i][1] - sa[j][0] + 1 - m + 1;
                        }
                    }
                    else if(ar[i][0] > sa[j][0] && ar[i][1] >= sa[j][1])
                    {
                        if(sa[j][1] - ar[i][0] + 1 >= m)
                        {
                            res += sa[j][1] - ar[i][0] + 1 - m + 1;
                        }
                    }
                    else if(ar[i][0] >sa[j][0] && ar[i][1] < sa[j][1]  )
                    {
                        if(ar[i][1] - ar[i][0] + 1 >= m)
                        {
                            res += ar[i][1] - ar[i][0] + 1 - m + 1;
                        }
                    }
                }
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}
