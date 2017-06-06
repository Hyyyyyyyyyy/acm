#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -10000000;
int visit[10][10][4];
int vis[10][10][4];
int ar[10][10];
int dir[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
int xb, yb, a, b, xr, yr;
struct point
{
	int x;
	int y;
	int step;
	int renx;
	int reny;
	friend bool operator < (point a, point b)
	{
		return a.step > b.step;
	}
};
point now, after;
struct node
{
	int x;
	int y;
	int step;
	friend bool operator < (node t, node s)
	{
		return t.step > s.step;
	}
};
bool r_bfs();
void x_bfs();
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			for (i = 1; i <= a; i++)
			{
				for (j = 1; j <= b; j++)
				{
					scanf("%d", &ar[i][j]);
					if (ar[i][j] == 2)
					{
						xb = i;
						yb = j;
					}
					if (ar[i][j] == 4)
					{
						xr = i;
						yr = j;
					}
				}
			}
			x_bfs();
			if (ar[now.x][now.y] == 3)
				printf("%d\n", now.step);
			else
				printf("-1\n");
		}
	}
	return 0;
}
void x_bfs()
{
	int i, j, k, u;
	priority_queue<point>q;
	for (i = 0; i <= a + 1; i++)
	{
		for (j = 0; j <= b + 1; j++)
		{
			for (u = 0; u < 4; u++)
			{
				visit[i][j][u] = MAX;
			}
		}
	}
	for (u = 0; u < 4; u++)
	{
		now.x = xb;
		now.y = yb;
		now.step = 0;
		now.renx = xr;
		now.reny = yr;
		visit[xb][yb][u] = 0;
		q.push(now);
		while (!q.empty())
		{
			now = q.top();
			q.pop();
			if (ar[now.x][now.y] == 3)
				return;
			for (i = 0; i < 4; i++)
			{
				after.x = now.x + dir[i][0];
				after.y = now.y + dir[i][1];
				after.step = now.step + 1;
				after.renx = now.x - dir[i][0];
				after.reny = now.y - dir[i][1];
				if (after.x > a || after.y > b || after.x < 1 || after.y < 1 || ar[after.x][after.y] == 1)
					continue;
				if (after.step <= visit[after.x][after.y][i] && r_bfs())
				{
					after.renx = now.x;
					after.reny = now.y;
					q.push(after);
					visit[after.x][after.y][i] = after.step;
				}
			}
		}
	}
	now.step = MAX;
	return;
}
bool r_bfs()
{
	int i, j, k, u;
	node qq, hh;
	priority_queue<node>p;
	memset(vis, 0, sizeof(vis));
	qq.x = now.renx;
	qq.y = now.reny;
	qq.step = 0;
	for (u = 0; u < 4; u++)
	{
		vis[qq.x][qq.y][u] = 1;
		p.push(qq);
		while (!p.empty())
		{
			qq = p.top();
			p.pop();
			if (qq.x == after.renx && qq.y == after.reny)
				return true;
			for (i = 0; i < 4; i++)
			{
				hh.x = qq.x + dir[i][0];
				hh.y = qq.y + dir[i][1];
				hh.step = qq.step + 1;
				if (hh.x > a || hh.y > b || hh.x < 1 || hh.y < 1 || ar[hh.x][hh.y] == 1 || (hh.x == now.x && hh.y == now.y))
					continue;
				if (vis[hh.x][hh.y][i])
					continue;
				p.push(hh);
				vis[hh.x][hh.y][i] = 1;
			}
		}
	}
	return false;
}
