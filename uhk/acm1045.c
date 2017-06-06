#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct point
{
	int x;
	int y;
};
struct point ar[20];
char sa[10][10];
int n, res, cnt;
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
void dfs(int a, int num);
bool check(int c);
int main()
{
	int i, j, k, u, a, b;
	while (scanf("%d", &n) != EOF && n)
	{
		cnt = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%s", sa[i] + 1);
			for (j = 1; j <= n; j++)
			{
				if (sa[i][j] == '.')
				{
					ar[cnt].x = i;
					ar[cnt++].y = j;
				}
			}
		}
		res = 0;
		dfs(0, 0);
		printf("%d\n", res);
	}
	return 0;
}
void dfs(int a, int num)
{
	if (num > res)
		res = num;
	if (a == cnt)
		return;
	dfs(a + 1, num);
	if (check(a))
	{
		sa[ar[a].x][ar[a].y] = '#';
		dfs(a + 1, num + 1);
		sa[ar[a].x][ar[a].y] = '.';
	}

}
bool check(int c)
{
	int i, doudou = 0;
	struct point now;
	for (i = 0; i < 4; i++)
	{
		if (doudou)
			return false;
		now.x = ar[c].x + dir[i][0];
		now.y = ar[c].y + dir[i][1];
		while (now.x <= n && now.y <= n && now.x >= 1 && now.y >= 1)
		{
			if (sa[now.x][now.y] == '#')
			{
				doudou = 1;
				break;
			}
			if (sa[now.x][now.y] == 'X')
			{
				break;
			}
			now.x += dir[i][0];
			now.y += dir[i][1];
		}
	}
	if (doudou)
		return false;
	return true;
}