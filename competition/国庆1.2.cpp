#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1000000007;
const int maxn = 10000 + 100;
const int maxm = 5000000 + 100;
char s[maxn];
int ar[maxn];
int N;
ll dp[1020][1020];
ll sum[1020][1020];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%s", s) != EOF)
	{
		N = strlen(s);
		ll res = 0;
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		dp[1][1] = 1;
		sum[1][1] = 1;
		for (i = 2; i <= N+1; i++)
		{
			for (j = 1; j <= i; j++)
			{
				if (s[i - 2] == 'I' || s[i - 2] == '?')
				{
					dp[i][j] = (dp[i][j] + sum[i - 1][j - 1]) % MOD;
				}
				if (s[i - 2] == 'D' || s[i - 2] == '?')
				{
					dp[i][j] = ((dp[i][j] + sum[i - 1][i - 1] - sum[i - 1][j - 1]) % MOD + MOD)%MOD;
				}
				sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD;
			}
		}
		printf("%lld\n", sum[N+1][N+1]);
	}
	return 0;
}