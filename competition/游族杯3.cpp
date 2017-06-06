#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxn = 110;
const int INF = 1000000000;
int dir[4][2] = { -1, 0, 0, -1, 0, 1, 1, 0 };    //up left right down;
int visit[maxn][maxn];
char ar[maxn][maxn];
struct Node
{
	int x;
	int y;
	int sta;
};
Node stack[maxn*maxn];
int top, N, M;
bool dfs(int x, int y)
{
	int i, j;
	if (x == 1 && y == 1)
		return true;
	visit[x][y] = 1;
	for (i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx < 1 || xx > N || yy < 1 || yy > M || ar[xx][yy] == '*' || visit[xx][yy])
			continue;
		stack[++top].x = x;
		stack[top].y = y;
		stack[top].sta = i;
		if (dfs(xx, yy))
			return true;
		top--;
	}
	visit[x][y] = 0;
	return false;
}
int main()
{
	int i, j, k, u, n, m, bx, by;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		bx = INF;
		by = INF;
		for (i = 1; i <= N; i++)
		{
			scanf("%s", ar[i] + 1);
			if (bx == INF)
				for (j = 1; j <= M; j++)
				{
					if (ar[i][j] == 'P')
					{
						bx = i;
						by = j;
					}
				}
		}
		top = 0;
		memset(visit, 0, sizeof(visit));
		if (dfs(bx, by))
		{
			for (i = 1; i <= top; i++)
			{
				if (stack[i].sta == 0)
				{
					printf("U");
				}
				else if (stack[i].sta == 1)
				{
					printf("L");
				}
				else if (stack[i].sta == 2)
				{
					printf("R");
				}
				else
				{
					printf("D");
				}
			}
			for (i = 1; i < M; i++)
				printf("R");
			for (i = 1; i < N; i++)
				printf("D");
			for (i = 1; i < M; i++)
				printf("L");
			for (i = 1; i < N; i++)
				printf("U");
			for (i = top; i >= 1; i--)
			{
				if (stack[i].sta == 0)
				{
					printf("D");
				}
				else if (stack[i].sta == 1)
				{
					printf("R");
				}
				else if (stack[i].sta == 2)
				{
					printf("L");
				}
				else
				{
					printf("U");
				}
			}
			putchar('\n');
		}
		else
			printf("error\n");
	}
	return 0;
}