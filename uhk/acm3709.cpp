#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
typedef __int64 ll;
ll dp[20][20][3005];
int ar[20];
ll solve(ll n);
ll dfs(int pos, int limit, int stand, int L);
int main()
{
	int i, j, u, max, a, b, c;
	ll n, m, k, s, res;
	memset(dp, -1, sizeof(dp));
	while (scanf("%d", &a) != EOF)
	{
		for (b = 1; b <= a; b++)
		{
			scanf("%I64d %I64d", &n, &m);
			//if (n == 0)
			//{
			//	printf("%I64d\n", solve(m));
			//	continue;
			//}
			//printf("%I64d %I64d\n", solve(n - 1), solve(m));
			printf("%I64d\n", solve(m) - solve(n-1));
		}
	}
	return 0;
}
ll solve(ll n)
{
	int i, j, count = 0;
	ll res = 0;
	//memset(ar, 0, sizeof(ar));
	while (n)
	{
		ar[count++] = n % 10;
		//printf("%I64d\n", n % 10);
		n /= 10;
	}
	for (i = 0; i < count; i++)
	{
		res += dfs(count - 1, 1, i, 0);
	}
	return (res - count + 1);
}
ll dfs(int pos, int limit, int stand, int L)
{
	int i, j, k, u, max;
	ll res = 0;
	if (pos == -1)
		return (L == 0);
	if (L < 0)
		return 0;
	if (!limit && dp[pos][stand][L] != -1)
		return dp[pos][stand][L];
	max = (limit) ? ar[pos] : 9;
	for (i = 0; i <= max; i++)
	{
		res += dfs(pos - 1, limit && i == ar[pos], stand, L + i*(pos - stand));
	}
	if (!limit)
		dp[pos][stand][L] = res;
	return res;
}

