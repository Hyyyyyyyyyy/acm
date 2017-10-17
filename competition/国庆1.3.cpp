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
const int maxn = 1 << 20;
const int maxm = 5000000 + 100;
int ar[maxn];
int dp[50][maxn];
int main()
{
	int i, j, n, m, N, M;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			dp[0][0] = 1;
			for (i = 1; i <= N; i++)
			{
				for (j = 0; j < maxn; j++)
				{
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ ar[i]];
				}
			}
			ll res = 0;
			for (i = M; i < maxn; i++)
			{
				res += dp[N][i];
			}
			printf("Case #%d: %lld\n", m, res);
		}
	}
	return 0;
}
