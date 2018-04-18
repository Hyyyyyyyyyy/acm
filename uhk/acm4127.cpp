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
const int maxn = 10;
const int maxm = 1000000 + 100;
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int ar[maxn][maxn];
int visit[maxn][maxn];
int N, res;
void find_dfs(int x, int y, int val)
{
	int i, j, k;
	visit[x][y] = 1;
	for (i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx > N || xx < 1 || yy > N || yy < 1)
			continue;
		if (visit[xx][yy] == 1)
			continue;
		visit[xx][yy] = 2;
		if (ar[xx][yy] == val)
			find_dfs(xx, yy, val);
	}
}
int Select(int val)
{
	int i, j, k, cnt;
	cnt = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (visit[i][j] == 2 && ar[i][j] == val)
			{
				find_dfs(i, j, val);
				cnt++;
			}
		}
	}
	return cnt;
}
int getH()
{
	int i, j, k;
	int cnt = 0;
	int vis_color[maxn];
	memset(vis_color, 0, sizeof(vis_color));
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (!vis_color[ar[i][j]] && visit[i][j] != 1)
			{
				vis_color[ar[i][j]] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}
bool IDA_dfs(int dep)
{
	if (dep == res)
	{
		if (getH() == 0)
			return true;
		return false;
	}
	if (getH() + dep > res)
		return false;
	int i, j, k;
	int temp_vis[maxn][maxn];

	memcpy(temp_vis, visit, sizeof(temp_vis));
	for (i = 0; i <= 5; i++)
	{
		if (Select(i) == 0)
			continue;
		if (IDA_dfs(dep + 1))
			return true;
		memcpy(visit, temp_vis, sizeof(visit));
	}
	return false;
}
int main()
{
	int i, j, k, n;
	while (scanf("%d", &N) != EOF && N)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		memset(visit, 0, sizeof(visit));
		find_dfs(1, 1, ar[1][1]);
		for (res = getH(); ; res++)
		{
			if (IDA_dfs(0))
				break;
		}
		printf("%d\n", res);
	}
	return 0;
}