#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
ll K, M, T;
ll dp[maxn];
ll cs[maxn];
int main()
{
	ll i, j, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			memset(dp, 0, sizeof(dp));
			scanf("%lld %lld %lld", &K, &M, &T);
			dp[0] = 0;
			dp[1] = 1;
			memset(cs, 0, sizeof(cs));
			cs[1] = 1;
			for (i = 2; i <= T + 1; i++)
			{
				dp[i] = dp[i - 1];
				if (i - M > 0)
					dp[i] = ((dp[i] - cs[i - M]) % MOD + MOD) % MOD;
				for (j = max(i-M+1, 0ll); j <= i - K; j++)
				{
					cs[i] = (cs[i] + cs[j]) % MOD;
				}
				dp[i] = (dp[i] + cs[i]) % MOD;
			}
			printf("%lld\n", dp[T + 1]);
		}
	}
	return 0;
}

//米波递推，抓住某一只米波是什么时候出生的
//dp[i]表示第i分钟共有多少只米波，cs[i]表示第i分钟出生的米波
//cs[i] += cs[j] (max(i-M+1, 0) <= j <= i-K);
//dp[i] = dp[i-1] + cs[i] - cs[i-M];