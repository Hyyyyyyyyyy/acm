#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100000 + 1000;
double dp[maxn];
int visit[maxn];
vector<int>G[maxn];
int N, M;
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d", &N, &M) != EOF && N + M)
	{
		for (i = 0; i <= N + 10; i++)
			G[i].clear();
		memset(visit, 0, sizeof(visit));
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &a, &b);
			G[b].push_back(a);
		}
		for (i = 0; i < G[N].size(); i++)
			visit[G[N][i]] = 1;
		visit[N] = 1;
		for (i = N - 1; i >= 0; i--)
		{
			if (!visit[i])
			{
				for (j = i + 1; j <= i + 6; j++)
					dp[i] += dp[j] / 6.0;
				dp[i] += 1.0;
				visit[i] = 1;
			}
			for (j = 0; j < G[i].size(); j++)
			{
				dp[G[i][j]] = dp[i];
				visit[G[i][j]] = 1;
			}
		}
		printf("%.4f\n", dp[0]);
	}
	return 0;
}