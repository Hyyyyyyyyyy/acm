#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Mod = 100000000;
ll dp[110][10][110];
char a[110], b[110], c[110];
int ar[110];
int Len;
bool check(int pre, int cur, char s);
ll dfs(int pos, int pre, int limit, int p, int first);
ll solve(char *s, bool d);
int main()
{
	int i, j, u;
	ll n, m, k, res;
	while (scanf("%s", c) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		Len = strlen(c);
		scanf("%s %s", a, b);
		printf("%08lld\n", (solve(b, false) - solve(a, true) + Mod) % Mod);
	}
	return 0;
}
ll solve(char *s, bool d)
{
	int L, i, j, u, count = 0;
	L = strlen(s);
	i = 0;
	while (s[i] == '0')
		i++;
	for (j = L - 1; j >= i; j--)
		ar[count++] = s[j] - '0';
	if (d)
	{
		for (i = 0; i < count; i++)
		{
			if (ar[i])
			{
				ar[i]--;
				break;
			}
			else
				ar[i] = 9;
		}
		if (i == count - 1 && ar[i] == 0)
			count--;
	}
	return dfs(count - 1, -1, 1, 0, 1);
}
ll dfs(int pos, int pre, int limit, int p, int first)
{
	int i, j, u, max;
	ll res = 0;
	if (pos == -1)
		return p == Len;
	if (!limit && dp[pos][pre][p] != -1)
		return dp[pos][pre][p];
	max = limit ? ar[pos] : 9;
	for (i = 0; i <= max; i++)
	{
		if (first)
		{
			res = (res + dfs(pos - 1, i, limit && i == ar[pos], p, first && i == 0)) % Mod;
		}
		else if (p < Len && check(pre, i, c[p]))
		{
			res = (res + dfs(pos - 1, i, limit && i == ar[pos], p + 1, first && i == 0)) % Mod;
		}
		else if (p > 0 && check(pre, i, c[p - 1]))
		{
			res = (res + dfs(pos - 1, i, limit && i == ar[pos], p, first && i == 0)) % Mod;
		}
	}
	if (!limit)
		dp[pos][pre][p] = res;
	return res;
}
bool check(int pre, int cur, char s)
{
	if (s == '/')
		return pre < cur;
	if (s == '\\')
		return pre > cur;
	if (s == '-')
		return pre == cur;
}
