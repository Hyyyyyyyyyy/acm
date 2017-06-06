#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
ll dp[30][2][2];
ll ar[30];
int cnt;
ll dfs(int pos, int pre, int limit, int sta);
int main()
{
	int i, j, u, n, m, count, a, b, c;
	ll k, t;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &k);
			t = k;
			memset(dp, -1, sizeof(dp));
			cnt = 0;
			count = 0;
			while (k)
			{
				ar[count++] = k % 10;
				k /= 10;
			}
			printf("%lld\n", t - dfs(count - 1, -1, 1, 0) + 1);
		}
	}
	return 0;
}
ll dfs(int pos, int pre, int limit, int sta)
{
	int i, j, k, max;
	ll res = 0;
	if (pos == -1)
		return 1;
	if (dp[pos][limit][sta] != -1)
		return dp[pos][limit][sta];
	if (limit)
	{
		for (i = 0; i <= ar[pos]; i++)
		{
			if (pre == 4 && i == 9)
				continue;
			res += dfs(pos - 1, i, limit && (i == ar[pos]), i == 4);
		}
		dp[pos][1][sta] = res;
		return res;
	}
	else
	{
		for (i = 0; i <= 9; i++)
		{
			if (pre == 4 && i == 9)
				continue;
			res += dfs(pos - 1, i, 0, i == 4);
		}
		dp[pos][0][sta] = res;
		return res;
	}
}
