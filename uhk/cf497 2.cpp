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
const int maxn = 300000 + 100;
const int maxm = 1000000 + 100;
int N;
struct Node
{
	int w;
	int h;
};
Node ar[maxn];
int dp[maxn][2];
int main()
{
	int i, j, k;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &ar[i].w, &ar[i].h);
		}
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j <= 1; j++)
				dp[i][j] = 1;
		}
		for (i = 2; i <= N; i++)
		{
			if (ar[i].h <= ar[i - 1].h)
				dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
			if (ar[i].h <= ar[i - 1].w)
				dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
			if (ar[i].w <= ar[i - 1].h)
				dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
			if (ar[i].w <= ar[i - 1].w)
				dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
		}
		if ((dp[N][0] == N || dp[N][1] == N))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}