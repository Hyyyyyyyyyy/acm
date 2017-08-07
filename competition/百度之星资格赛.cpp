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
					else if(dp[j] == dp[j - cost[i]] + sco[i] && ar[j].sum > ar[j - cost[i]].sum + i)
					{
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
typedef long long ll;
const ll INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int maxn = 100000 + 10;
struct mon
{
	ll xue;
	ll fang;
};
mon ar[maxn];
struct ji
{
	ll jing;
	ll shang;
};
ji sa[1000 + 10];
ll dp[15][1010];		//dp[i][j]是对于i的护甲造成j的伤害，最少需要花多少晶石
ll min(ll a, ll b)
{
	if (a < b)
		return a;
	else
		return b;
}
int main()
{
	ll i, j, k, u, n, m, a, b, maxxue, maxshang, maxjia, N, M;
	while (scanf("%lld %lld", &N, &M) != EOF)
	{
		maxxue = -INF;
		maxshang = -INF;
		maxjia = -INF;
		for (i = 1; i <= N; i++)
		{
			scanf("%lld %lld", &ar[i].xue, &ar[i].fang);
			maxxue = max(maxxue, ar[i].xue);
			maxjia = max(maxjia, ar[i].fang);
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%lld %lld", &sa[i].jing, &sa[i].shang);
			maxshang = max(maxshang, sa[i].shang);
		}
		if (maxjia >= maxshang)
		{
			printf("-1\n");
			continue;
		}
		for (i = 0; i <= 10; i++)
		{
			for (j = 0; j <= maxxue; j++)
			{
				dp[i][j] = INF;
			}
		}
		for (i = 0; i <= 10; i++)
		{
			for (j = 1; j <= maxxue; j++)
			{
				for (k = 1; k <= M; k++)
				{
					if (sa[k].shang - i >= j)
					{
						dp[i][j] = min(dp[i][j], sa[k].jing);
					}
					else if (sa[k].shang - i > 0)
					{
						dp[i][j] = min(dp[i][j], dp[i][j - (sa[k].shang - i)] + sa[k].jing);
					}
				}
			}
		}
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			res += dp[ar[i].fang][ar[i].xue];
		}
		printf("%lld\n", res);
	}
	return 0;
}






