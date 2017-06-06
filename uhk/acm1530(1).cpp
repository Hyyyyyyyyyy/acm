#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 100000000;
const int maxn = 60;
int ar[maxn][maxn];
int dp[maxn], stack[maxn];
int N, RES, top;
vector<int>G[maxn];
bool check(int n)
{
	int i, j;
	for (i = 1; i <= top; i++)
		if (!ar[stack[i]][n])
			return false;
	return true;
}
void dfs(int n, int num)
{
	int i;
	if (num + G[n].size() <= RES)
		return;
	for (i = 0; i < G[n].size(); i++)
	{
		int j = G[n][i];
		if (num + dp[j] <= RES)
			continue;
		if (check(j))
		{
			stack[++top] = j;
			dfs(j, num + 1);
			top--;
		}
	}
	if (RES < num)
		RES = num;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &N) != EOF && N)
	{
		for (i = 1; i <= N; i++)
		{
			G[i].clear();
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &ar[i][j]);
				if (ar[i][j] && i < j)
					G[i].push_back(j);
			}
		}
		dp[N] = 1;
		RES = 1;
		for (i = N - 1; i >= 1; i--)
		{
			stack[1] = i;
			top = 1;
			dfs(i, 1);
			dp[i] = RES;
		}
		printf("%d\n", RES);
	}
	return 0;
}
