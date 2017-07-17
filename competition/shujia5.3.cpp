#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 2147483640;
const int maxn = 5000 + 1000;
char s[maxn];
ll ar[maxn];
int visit[maxn][maxn];
unsigned long long dp[maxn];
int N;
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			scanf("%s", s + 1);
			int L = strlen(s + 1);
			memset(visit, 0, sizeof(visit));
			for (i = 1; i <= L; i++)
			{
				int t;
				visit[i][i] = 1;
				for (t = 1; i - t >= 1 && i + t <= L && t*2+1 <= N; t++)
				{
					if (s[i + t] == s[i - t])
					{
						visit[i + t][i - t] = 1;
					}
					else
					{
						break;
					}
				}
			}
			for (i = 1; i <= L; i++)
			{
				if (s[i] == s[i + 1])
				{
					visit[i + 1][i] = 1;
					int t;
					for (t = 1; i - t >= 1 && i + t + 1 <= L && t * 2 + 2 <= N; t++)
					{
						if (s[i - t] == s[i + t + 1])
						{
							visit[i + t + 1][i - t] = 1;
						}
						else
							break;
					}
				}
			}
			memset(dp, 0, sizeof(dp));
			dp[1] = ar[1];
			for (i = 2; i <= L; i++)
			{
				for (j = 1; j <= i; j++)
				{
					if (visit[i][j])
					{
						dp[i] = max(dp[i], dp[j-1] + ar[i - j + 1]);
					}
				}
			}
			printf("%llu\n", dp[L]);
		}
	}
	return 0;
}
