#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
const int INF = 1000000000;
const int maxn = 15;
int dir[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
int visit[maxn][maxn];
char ar[maxn][maxn];
int N, M, K, bx, by;
bool check(int xx, int yy, int tt, int x, int y)
{
	int i, j, doudou = 0;
	if (xx < 1 || xx > N || yy < 1 || yy > M || visit[xx][yy])
		return false;
	if (xx == bx && yy == by && tt < K)
		return false;
	for (j = 0; j < 4; j++)
	{
		int xxx = xx + dir[j][0];
		int yyy = yy + dir[j][1];
		if (xxx < 1 || xxx > N || yyy < 1 || yyy > M)
			continue;
		if (visit[xxx][yyy])
		{
			if (xxx == x && yyy == y)
				continue;
			else
				return false;
		}
	}
}
bool dfs(int x, int y, int t)
{
	int i, j, k, doudou;
	if (x == bx && y == by && t >= K)
		return true;
	visit[x][y] = 1;
	for (i = 0; i < 4; i++)
	{
		int xx = dir[i][0] + x;
		int yy = dir[i][1] + y;
		int tt = t + 1;
		if (!check(xx, yy, tt,  x, y))
			continue;
		if (dfs(xx, yy, tt))
			return true;
	}
	visit[x][y] = 0;
	return false;
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		scanf("%d %d %d", &bx, &by, &K);
		memset(ar, '*', sizeof(ar));
		memset(visit, 0, sizeof(visit));
		if (abs(bx - 1 + by - 1) >= K)
		{
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
					putchar('.');
				putchar('\n');
			}
		}
		else
		{
			visit[1][1] = 1;
			dfs(1, 1, 0);
			visit[bx][by] = 1;
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					if (visit[i][j])
						printf(".");
					else
						printf("*");
				}
				printf("\n");
			}
		}
	}
	return 0;
}