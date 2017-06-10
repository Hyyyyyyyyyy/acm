#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 20;
ll dp[11][11][3][4][6][8];
int ar[20];
int Count;
ll dfs(int pos, int pre, int limit, int mod2, int mod3, int mod5, int mod7);
ll solve(ll n);
int main()
{
	int i, j, u, max, a, b;
	ll N;
	ll n, m, k, res;
	memset(dp, -1, sizeof(dp));
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			printf("%lld\n", solve(N)-1);
		}
	}
	return 0;
}
ll solve(ll n)
{
	int i, j;
	Count = 0;
	while (n)
	{
		ar[++Count] = n % 10;
		n /= 10;
	}
	return dfs(Count, 0, 1, 0, 0, 0, 0);
}
ll dfs(int pos, int pre, int limit, int mod2, int mod3, int mod5, int mod7)
{
	int i, j, k, max;
	ll res = 0;
	if (pos == 0)
		return (mod2 == 0 || mod3 == 0 || mod5 == 0 || mod7 == 0);
	if (!limit && dp[pos][pre][mod2][mod3][mod5][mod7] != -1)
		return dp[pos][pre][mod2][mod3][mod5][mod7];
	max = limit ? ar[pos] : 9;
	for (i = 0; i <= max; i++)
	{
		int t2 = (mod2 * 10 + i) % 2;
		int t3 = (mod3 * 10 + i) % 3;
		int t5 = (mod5 * 10 + i) % 5;
		int t7 = (mod7 * 10 + i) % 7;
		res += dfs(pos - 1, i, limit && (i == ar[pos]), t2, t3, t5, t7);
	}
	if (!limit)
		dp[pos][pre][mod2][mod3][mod5][mod7] = res;
	return res;
}