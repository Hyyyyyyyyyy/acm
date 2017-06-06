#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int i, j, k, u, n, m, a, b, c, ar[60];
    long long dp[60], res;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            memset(dp, 0, sizeof(dp));
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
            res = 1;
            for(i = 1; i < k; i++)
            {
                scanf("%d", &ar[i]);
                for(j = 4; j <= ar[i]; j++)
                {
                    if(dp[j])
                        continue;
                    dp[j] = dp[j-1]+dp[j-2]+dp[j-3];
                }
                res = (res * dp[ar[i]]) % 10007;
            }
            printf("%lld\n", res);
        }
        
    }
    return 0;
}
