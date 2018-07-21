#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100 + 100;
const int maxm = 1000000 + 100;
int N;
int ar[maxn];
int sum[maxn];
int dp[maxn][maxn];
int main()
{
    int i, j, k, cas, CAS, L;
    while(scanf("%d", &CAS) != EOF)
    {
        for(cas = 1; cas <= CAS; cas++)
        {
            scanf("%d", &N);
            sum[0] = 0;
            for(i  =1; i <= N; i++)
            {
                scanf("%d", &ar[i]);
                sum[i] = sum[i-1]+ar[i];
            }
            memset(dp, 0, sizeof(dp));
            for(i = 1; i <= N; i++)
            {
                for(j = i+1; j <= N; j++)
                {
                    dp[i][j] = inf;
                }
            }
            for(L = 1; L < N; L++)
            {
                for(i = 1; i <= N && i+L <= N; i++)
                {
                    j = i+L;
                    for(k = 1; k <= L+1; k++)
                    {
                        dp[i][j] = min(dp[i][j], ar[i]*(k-1) + dp[i+1][i+1+k-1-1] + dp[i+k][j] + (sum[j] - sum[i+1+k-1-1])*k);
                    }
                }
            }
            printf("Case #%d: %d\n", cas, dp[1][N]);
        }
    }
    return 0;
}
