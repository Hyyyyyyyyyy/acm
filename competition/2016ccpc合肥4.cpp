#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 220;
ll N, M;
ll A[maxn], B[maxn];
int main()
{
    ll i, j, k, n, m, u;
    while(scanf("%lld", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            memset(A, 0, sizeof(A));
            memset(B, 0, sizeof(B));
            scanf("%lld %lld", &N, &M);
            if(N > M)
            {
                ll t = N;
                N = M;
                M = t;
            }
            i = 0;
            while(N)
            {
                if(N & 1)
                {
                    A[i++] = 1;
                }
                else
                    i++;
                N >>= 1;
            }
            j = 0;
            while(M)
            {
                if(M & 1)
                {
                    B[j++] = 1;
                }
                else
                    j++;
                M >>= 1;
            }
            bool x1, x2, y1, y2;
            x1 = x2 = y1 = y2 = false;
            ll res1, res2;
            res1 = res2 = 0;
            for(u = j-1; u >= 0; u--)
            {
                if(A[u] == B[u])
                {
                    res1 |= A[u];
                    res2 |= B[u];
                }
                else
                {
                    break;
                }
                res1 <<= 1;
                res2 <<= 1;
            }
            if(u < 0)
            {
                res1 >>= 1;
                res2 >>= 1;
                printf("%lld\n", res1 | res2);
            }
            else
            {
                for(k = u; k >= 0; k--)
                {
                    if(A[u] == 1 && B[u] == 1)
                    {
                        res1 |= 1;
                        res2 |= 0;
                    }
                    if(A[u] == 0 && B[u] == 1)
                    {
                        res1 |= 0;
                        res2 |= 1;
                    }
                    if(A[u] == 1 && B[u] == 0)
                    {
                        res1 |= 1;
                        res2 |= 0;
                    }
                    if(A[u] == 0 && B[u] == 0)
                    {
                        res1 |= 1;
                        res2 |= 0;
                    }
                    res1 <<= 1;
                    res2 <<= 1;
                }
                res1 >>= 1;
                res2 >>= 1;
                printf("%lld\n", res1 | res2);
            }
        
        }
    }
    return 0;
}