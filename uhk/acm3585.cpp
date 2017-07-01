#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 60;
struct Point
{
	int x;
	int y;
};
Point point[maxn];
int N, K, cnt, RES;
int stack[maxn][maxn];
int ar[maxn][maxn], edge[maxn*maxn], dp[maxn];
void dfs(int dep, int num, int x)
{
	int i, j, u, v;
	if (num == 0)
	{
		if (RES < dep)
			RES = dep;
		return;
	}
	for (i = 0; i < num; i++)
	{
		u = stack[dep][i];
		if (dep + dp[u] <= RES)
			return;
		if (dep + N - u + 1 <= RES)
			return;
		int top = 0;
		for (j = i + 1; j < num; j++)
		{
			v = stack[dep][j];
			if (ar[u][v] >= x)
				stack[dep + 1][top++] = v;
		}
		dfs(dep + 1, top, x);
	}
}
bool check(int x)
{
	int i, j, k;
	RES = 0;
	for (i = N; i >= 1; i--)
	{
		int top = 0;
		for (j = i+1; j <= N; j++)
			if (ar[i][j] >= edge[x])
				stack[1][top++] = j;
		dfs(1, top, edge[x]);
		dp[i] = RES;
		if (RES >= K)
			return true;
	}
	return false;
}
int main()
{
	int i, j, k, u, a, b, c;
	while (scanf("%d %d", &N, &K) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &point[i].x, &point[i].y);
		}
		cnt = 0;
		for (i = 1; i <= N; i++)
		{
			ar[i][i] = 0;
			for (j = i + 1; j <= N; j++)
			{
				ar[i][j] = ar[j][i] = (point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y);
				edge[++cnt] = ar[i][j];
			}
		}
		sort(edge + 1, edge + cnt + 1);
		int l = 1;
		int r = cnt;
		int mid;
		int ans;
		while (r >= l)
		{
			mid = (l + r) / 2;
			if (check(mid))
			{
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%.2f\n", sqrt(edge[r]));
	}
	return 0;
}