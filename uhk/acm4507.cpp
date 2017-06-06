#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Mod = 1000000007;
struct node
{
	ll count;
	ll sum;
	ll square;
	ll visit;
	node() {}
	node(ll c, ll s, ll sq, ll v) : count(c), sum(s), square(sq), visit(v) {}
};
node dp[20][8][8];
ll Pow[20];
int ar[20];
ll solve(ll n);
node dfs(int pos, int limit, int sta1, int sta2);
int main()
{
	int i, j, u, count, k;
	ll n, m, res;
	Pow[0] = 1;
	for (i = 1; i < 20; i++)
		Pow[i] = Pow[i - 1] * 10;
	memset(dp, -1, sizeof(dp));
	while (scanf("%d", &k) != EOF)
	{
		for (u = 1; u <= k; u++)
		{
			scanf("%lld %lld", &n, &m);
			printf("%lld\n", ((solve(m) - solve(n - 1)) % Mod + Mod) % Mod);
		}
	}
	return 0;
}
ll solve(ll n)
{
	int count = 0, i, j;
	memset(ar, 0, sizeof(ar));
	while (n)
	{
		ar[++count] = n % 10;
		n /= 10;
	}
	return dfs(count, 1, 0, 0).square;
}
node dfs(int pos, int limit, int sta1, int sta2)
{
	int i, j, u, max;
	node res(0, 0, 0, 0);
	node next;
	if (pos == 0)
		return (sta1 && sta2) ? node(1, 0, 0, 0) : node(0, 0, 0, 0);
	if (!limit && dp[pos][sta1][sta2].visit != -1)
		return dp[pos][sta1][sta2];
	max = limit ? ar[pos] : 9;
	for (i = 0; i <= max; i++)
	{
		if (i == 7)
			continue;
		next = dfs(pos - 1, limit && i == ar[pos], (i + sta1) % 7, (i + 10 * sta2) % 7);
		ll temp = (i * Pow[pos - 1]) % Mod;
		res.count = (res.count + next.count) % Mod;
		res.sum = (res.sum + (next.sum + next.count * temp) % Mod) % Mod;
		res.square = (res.square + ((next.count*temp%Mod*temp%Mod + 2 *temp*next.sum%Mod) % Mod + next.square) % Mod) % Mod;
	}
	if (!limit)
	{
		res.visit = 1;
		dp[pos][sta1][sta2] = res;
	}
	return res;
}

