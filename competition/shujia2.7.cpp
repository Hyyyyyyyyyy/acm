#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
typedef long long ll;
const ll INF = 9223372036854775800;
const int maxn = 100000 + 100;
int ar[maxn];
ll sum1[maxn], sum2[maxn];
int num[maxn];
int N;
ll max(ll a, ll b)
{
	return (a > b ? a : b);
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			memset(sum1, 0, sizeof(sum1));
			memset(sum2, 0, sizeof(sum2));
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
				//sum[i] = sum[i - 1] + ar[i];
			}
			ll MAX = -INF;
			sum1[1] = ar[1];
			for (i = 2; i <= N; i++)
			{
				sum1[i] = max(sum2[i - 1] + ar[i], ar[i]);
				sum2[i] = sum1[i - 1] + ar[i];
			}
			for(i = 1; i <= N; i++)
				if (MAX < sum1[i])
					MAX = sum1[i];
			printf("%lld\n", MAX);
		}
	}
	return 0;
}