#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e6 + 100;
const int INF = 1e9;
typedef long long ll;
//int fa[maxn][100];
int dp[maxn], visit[maxn];
int N;
//void getfactor()
//{
//	int i, j;
//	fa[1][0] = 1;
//	fa[1][1] = 1;
//	for (i = 2; i < maxn; i++)
//	{
//		fa[i][0] = 2;
//		fa[i][1] = 1;
//		fa[i][2] = i;
//		int cnt = 2;
//		for (j = 2; j*j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				fa[i][0] += 2;
//				fa[i][++cnt] = j;
//				fa[i][++cnt] = i / j;
//			}
//		}
//		if (i % (j * j) == 0)
//		{
//			fa[i][0]++;
//			fa[i][++cnt] = j;
//		}
//	}
//}
int dfs(int n)
{
	int i, j;
	if (visit[n])
		return dp[n];
	visit[n] = 1;
	for (i = 1; i < n; i++)
	{
		if (n - i >= 0 && n % i == 0)
			dp[n] |= (!dfs(n - i));
	}
	return dp[n];
}
int main()
{
	int i, j, k, n, m;
	//getfactor();
	dp[0] = 0;
	dp[1] = 0;
	//for (i = 1; i < maxn; i++)
	//{
	//	for (j = 1; j <= fa[i][0]; j++)
	//		printf("%d ", fa[i][j]);
	//	putchar('\n');
	//}
	memset(visit, 0, sizeof(visit));
	//for (i = 2; i < maxn; i++)
	//	dfs(i);
	while (scanf("%d", &N) != EOF)
	{
		if (N <= 1)
		{
			printf("G\n");
			continue;
		}
		dfs(N);
		if (dp[N])
			printf("H\n");
		else
			printf("G\n");
	}
	return 0;
}
