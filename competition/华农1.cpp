#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
using namespace std;
const int MIN = -100000000;
const int MAX = 100000000;
typedef long long ll;
int ar[100005], dp[100005];
int Max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
int main()
{
    int i, j, k, u, n, m, a, b, p, q, doudou, flag, max;
    ll res;
    while(scanf("%d", &p) != EOF)
    {
        for(q = 1; q <= p; q++)
        {
            scanf("%d %d", &n, &k);
            k++;
            for(i = 1; i <= n; i++)
            {
                scanf("%d", &ar[i]);
            }
            memset(dp, 0, sizeof(dp));
            for(i = 1; i <= n; i++)
            {
                if(i <= k)
                {
                    dp[i] = Max(dp[i-1], ar[i]);
                }
                else
                {
                    dp[i] = Max(dp[i-1], ar[i] + dp[i-k]);
                }
            }
            printf("%d\n", dp[n]);
        }
    }
    return 0;
}