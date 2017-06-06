#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
ll dp[20][2][2][2][20];
int ar[20];
ll dfs(int pos, int pre, int limit, int sta1, int stam, int mod);
int main()
{
	int i, j, u, count;
	ll n, m, k, t;
	while (scanf("%lld", &n) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		t = n;
		count = -1;
		while (t)
		{
			ar[++count] = t % 10;
			t /= 10;
		}
		printf("%lld\n", dfs(count, -1, 1, 0, 0, 0));
	}
	return 0;
}
ll dfs(int pos, int pre, int limit, int sta1, int stam, int mod)
{
	int i, j, k, u, t;
	ll res = 0;
	if (pos == -1)
		return (stam && mod == 0);
	if (dp[pos][limit][sta1][stam][mod] != -1)
		return dp[pos][limit][sta1][stam][mod];
	if (limit)
	{
		for (i = 0; i <= ar[pos]; i++)
		{
			t = (mod* 10 + i)%13;
			res += dfs(pos - 1, i, limit && (i == ar[pos]), i == 1, stam || (pre == 1 && i == 3), t);
		}
		dp[pos][1][sta1][stam][mod] = res;
		return res;
	}
	else
	{
		for (i = 0; i <= 9; i++)
		{
			t = (mod * 10 + i)%13;
			res += dfs(pos - 1, i, 0, i == 1, stam || (pre == 1 && i == 3), t);
		}
		dp[pos][0][sta1][stam][mod] = res;
		return res;
	}
}
