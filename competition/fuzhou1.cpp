#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 100;
int ar[maxn], sa[maxn];
int dp[maxn];
int main()
{
	int i, j, k, u, n, m, a;
	while (scanf("%d", &n) != EOF)
	{
		int cnt = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
			if (ar[i])
				cnt++;
		}
		dp[0] = 0;
		int maxb, maxe, max = -1;
		for (i = 1; i <= n; i++)
		{
			if (dp[i - 1] >= 0)
			{
				dp[i] = dp[i - 1] + (ar[i] == 0 ? 1 : -1);
			}
			else
			{
				dp[i] = (ar[i] == 0 ? 1 : -1);
			}
			if (max < dp[i])
			{
				max = dp[i];
			}
		}
		printf("%d\n", max + cnt);
	}
	return 0;
}