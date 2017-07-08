#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 100;
ll ar[maxn], dp[maxn][2];  //dp[i][0]  为长度为i的颜色与固定点相同       dp[i][1]为长度为i的与固定点颜色不同
const ll mod = 1e9 + 7;
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		dp[1][0] = (ll)0;
		dp[1][1] = (ll)k - 1;
		for (i = 2; i <= n; i++)
		{
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][1] * (k - 2) % mod + dp[i - 1][0] * (k - 1) % mod;
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d", &a, &b);
			if (a > b)
				swap(a, b);
			int t1 = b - a - 1;
			int t2 = n - t1 - 2;
			printf("%lld\n", ((ll)k*dp[t1][1] % mod) * dp[t2][1] % mod);
		}
	}
	return 0;
}