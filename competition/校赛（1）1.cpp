#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int dp[500000]
int main()
{
	int i, j, k, u, a, b, c, d, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			memset(dp, 0, sizeof(dp));
            dp[a] = 1;
            dp[b] = 1;
            dp[c] = 1;
            for(i = a; i <= n; i++)
            {
                dp[i] += dp[i-a];
            }
            for(i = b; i <= n; i++)
            {
                dp[i] += dp[i-b];
            }
            for(i = c; i <= n; i++)
            {
                dp[i] += dp[i-c];
            }
            if(dp[d])
                printf("Yes\n");
            else
                printf("No\n");
		}
	}
	return 0;
}