#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef unsigned long long ll;
const int maxn = 1000 + 10;
int dp[maxn];
int sco[110], cost[110];
struct Node
{
	int stack[110];
	int top;
	int sum;
};
Node ar[maxn];
int main()
{
	int i, j, k, u, n, m, cas = 1, N, B, T;
	while (scanf("%d", &T) != EOF)
	{
		for (m = 1; m <= T; m++)
		{
			scanf("%d", &B);
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &sco[i], &cost[i]);
			}
			for (i = 0; i <= B; i++)
			{
				ar[i].top = 0;
				ar[i].sum = 0;
				dp[i] = -INF;
			}
			dp[0] = 0;
			for (i = 1; i <= N; i++)
			{
				for (j = B; j >= cost[i]; j--)
				{
					if (dp[j] < dp[j - cost[i]] + sco[i])
					{
						dp[j] = dp[j - cost[i]] + sco[i];
						ar[j] = ar[j - cost[i]];
						ar[j].stack[++ar[j].top] = i;
						ar[j].sum += i;

					}
				}
			}
			printf("Case #%d:\n", m);
			int Max = -INF;
			int Maxi;
			int Maxs = INF;
			for (i = B; i >= 0; i--)
				if (Max < dp[i] || (Maxs > ar[i].sum && Max == dp[i] && ar[i].sum > 0))
					Max = dp[i], Maxi = i, Maxs = ar[i].sum;
			printf("%d %d\n", Max, Maxi);
			if (ar[Maxi].top > 0)
			{
				for (i = 1; i <= ar[Maxi].top; i++)
				{
					if (i != 1)
						putchar(' ');
					printf("%d", ar[Maxi].stack[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}