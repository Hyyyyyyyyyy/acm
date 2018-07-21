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
const int maxn = 3000 + 100;
const int maxm = 1000000 + 100;
int N, M;
int ar[maxn];
int dp[maxn];
int main()
{
	int i, j, k, cas, CAS, a, b;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &M);
			memset(ar, 0, sizeof(ar));
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &a, &b);
				ar[a + b] = 1;
			}
			memset(dp, 0, sizeof(dp));
			dp[0] = ar[0];
			for (i = 1; i < M; i++)
			{
				dp[i] = ar[i];
			}
			for (i = M; i <= 2010; i++)
			{
				for (j = 0; j <= i - M; j++)
				{
					dp[i] = max(dp[i], dp[j] + ar[i]);
				}
			}
			printf("%d\n", dp[2010]);
		}
	}
	return 0;
}
