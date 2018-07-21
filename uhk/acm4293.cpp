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
const int maxn = 500 + 100;
int dp[maxn];
int sp[maxn][maxn];
int main()
{
	int i, j, k, a, b, N;
	while (scanf("%d", &N) != EOF)
	{
		memset(sp, 0, sizeof(sp));
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &a, &b);
			if (a + b + 1 <= N && sp[a + 1][N - b] < N - a - b)
				sp[a+1][N-b]++;
		}
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j < i; j++)
			{
				dp[i] = max(dp[i], dp[j] + sp[j + 1][i]);
			}
		}
		printf("%d\n", dp[N]);
	}
	return 0;
}
//4293    区间dp
/*思路：区间DP，定义dp[i] 表示前i个人中最多有多少人说了真话，sp[i][j] 表示第i到第j个人为一群时，i到j最多有多少人说了真话
状态转移方程：dp[i]=dp[j]+sp[j+1][i];*/