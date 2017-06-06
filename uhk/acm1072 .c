#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct node
{
	int x;
	int y;
	int time;
	int step;
};

struct node now, after;
int visit[10][10], ar[10][10], dir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } }, beginx, beginy, a, b;
void bfs();
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			beginx = 1;
			beginy = 1;
			for (i = 1; i <= a; i++)
			{
				for (j = 1; j <= b; j++)
				{
					scanf("%d", &ar[i][j]);
					if (ar[i][j] == 2)
					{
						beginx = i;
						beginy = j;
					}
				}
			}
			bfs();
			printf("%d\n", now.step);
		}
	}
	return 0;
}
void bfs()
{
	int i;
	queue<node>q;
	now.x = beginx;
	now.y = beginy;
	now.time = 6;
	now.step = 0;
	memset(visit, 0, sizeof(visit));
	visit[now.x][now.y] = 1;
	q.push(now);
	while (q.empty() == 0)
	{
		now = q.front();
		q.pop();
		if (ar[now.x][now.y] == 3)
			return;
		if (now.time <= 1)
			continue;
		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			if (after.x < 1 || after.y < 1 || after.x > a || after.y > b)
				continue;
			if (visit[after.x][after.y] == 1)
				continue;
			if (ar[after.x][after.y] == 0)
				continue;
			after.step = now.step + 1;
			after.time = now.time - 1;
			if (ar[after.x][after.y] == 4)
			{
				after.time = 6;
				visit[after.x][after.y] = 1;
			}
			q.push(after);
		}
	}
	now.step = -1;
}
