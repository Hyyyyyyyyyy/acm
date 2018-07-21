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
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
ll dp[20][20];
char ar[20];
ll N;
ll res;

void dfs_right(ll mid, ll right, ll presum, ll sum)
{
	if (right > N)
	{
		if (presum == sum)
			res++;
		return;
	}
	int i, j;
	for (i = right; i <= N; i++)
	{
		dfs_right(mid, i + 1, presum, sum + dp[right][i]);
	}
}
void dfs_left(ll left, ll mid, ll sum)
{
	if (left > mid)
	{
		dfs_right(mid, left, sum, 0);
	}
	int i, j;
	for (i = left; i <= mid; i++)
	{
		dfs_left(i + 1, mid, sum + dp[left][i]);
	}
}
int main()
{
	ll i, j, k;
	while (scanf("%s", ar + 1) != EOF && strcmp(ar + 1, "END"))
	{
		N = strlen(ar + 1);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= N; i++)
		{
			for (j = i; j <= N; j++)
			{
				dp[i][j] = dp[i][j - 1] * 10 + ar[j] - '0';
			}
		}
		res = 0;
		for (i = 1; i < N; i++)
		{
			dfs_left(1, i, 0);
		}
		printf("%lld\n", res);
	}
	return 0;
}
//4403		枚举等号的位置，左右递归求解加号的位置（分治的思想）