#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
	int x;
	int y;
	int time;
	int sta;
};
struct node now, after, temp;
queue<node>q;
int a, b, visit[25][25], dir[4][2] = { { 0, 1 },{ 0, -1 },{ -1, 0 },{ 1, 0 } };
char ar[25][25];
int bfs(int x1, int y1, int x2, int y2);
int main()
{
	int i, j, k, n, m, x1, x2, y1, y2;
	struct node temp;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		getchar();
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				scanf("%c", &ar[i][j]);
				if (ar[i][j] == 'S')
				{
					x1 = i;
					y1 = j;
				}
				if (ar[i][j] == 'T')
				{
					x2 = i;
					y2 = j;
				}
			}
			getchar();
		}
		/*printf("%d %d %d %d\n", x1, y1, x2, y2);
		printf("%c %c\n", ar[x1][y1], ar[x2][y2]);*/
		for (i = 0; i < 25; i++)
		{
			for (j = 0; j < 25; j++)
				visit[i][j] = 1000;
		}
		visit[x1][y1] = 0;
		while (!q.empty())
			q.pop();
		for (i = 0; i < 4; i++)
		{
			temp.x = x1;
			temp.y = y1;
			temp.sta = i;
			temp.time = 0;
			q.push(temp);
		}
		i = bfs(x1, y1, x2, y2);
		/*printf("%d\n", i);*/
		printf("%d\n", /*bfs(x1, y1, x2, y2)*/visit[x2][y2]);
	}
	return 0;
}
int bfs(int x1, int y1, int x2, int y2)
{
	int i, j;

	/*now.x = x1;
	now.y = y1;
	now.sta = -1;
	now.time = 0;
	visit[x1][y1] = 0;
	q.push(now);*/

	while (!q.empty())
	{
		now = q.front();
		q.pop();
		/*printf("%d %d\n", now.x, now.y);
		printf("%c\n", ar[now.x][now.y]);*/
		/*if (ar[now.x][now.y] == 'T' && now.time == visit[x2][y2])
			return now.time;*/

		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			after.sta = i;
			after.time = now.time + 1;

			if (after.x < 1 || after.x > a || after.y < 1 || after.y > b)
				continue;
			if (ar[after.x][after.y] == '*')
				continue;

			if (ar[after.x][after.y] == '|')
			{
				if (now.time % 2 == 0)
				{
					if (after.sta == 0)
						if (ar[after.x][after.y + 1] != '*')
						{
							after.y = after.y + 1;
							after.time++;
						}
					if (after.sta == 1)
						if (ar[after.x][after.y - 1] != '*')
						{
							after.y = after.y - 1;
							after.time++;
						}
					if (after.sta == 2)
					{
						if (ar[after.x - 1][after.y] != '*')
							after.x = after.x - 1;
					}
					if (after.sta == 3)
					{
						if (ar[after.x + 1][after.y] != '*')
							after.x = after.x + 1;
					}
				}
				if (now.time % 2 != 0)
				{
					if (after.sta == 0)
					{
						if (ar[after.x][after.y + 1] != '*')
							after.y = after.y + 1;
					}
					if (after.sta == 1)
					{
						if (ar[after.x][after.y - 1] != '*')
							after.y = after.y - 1;
					}
					if (after.sta == 2)
					{
						if (ar[after.x - 1][after.y] != '*')
						{
							after.x = after.x - 1;
							after.time++;
						}
					}
					if (after.sta == 3)
					{
						if (ar[after.x + 1][after.y] != '*')
						{
							after.x = after.x + 1;
							after.time++;
						}
					}
				}
			}
			if (ar[after.x][after.y] == '-')
			{
				if (now.time % 2 == 0)
				{
					if (after.sta == 0)
					{
						if (ar[after.x][after.y + 1] != '*')
							after.y = after.y + 1;
					}
					if (after.sta == 1)
					{
						if (ar[after.x][after.y - 1] != '*')
							after.y = after.y - 1;
					}
					if (after.sta == 2)
					{
						if (ar[after.x - 1][after.y] != '*')
						{
							after.x = after.x - 1;
							after.time++;
						}
					}
					if (after.sta == 3)
					{
						if (ar[after.x + 1][after.y] != '*')
						{
							after.x = after.x + 1;
							after.time++;
						}
					}
				}
				if (now.time % 2 != 0)
				{
					if (after.sta == 0)
						if (ar[after.x][after.y + 1] != '*')
						{
							after.y = after.y + 1;
							after.time++;
						}
					if (after.sta == 1)
						if (ar[after.x][after.y - 1] != '*')
						{
							after.y = after.y - 1;
							after.time++;
						}
					if (after.sta == 2)
					{
						if (ar[after.x - 1][after.y] != '*')
							after.x = after.x - 1;
					}
					if (after.sta == 3)
					{
						if (ar[after.x + 1][after.y] != '*')
							after.x = after.x + 1;
					}
				}
			}
			if ((ar[after.x][after.y] == '.' || ar[after.x][after.y] == 'T') && after.time < visit[after.x][after.y])
			{
				q.push(after);
				visit[after.x][after.y] = after.time;
			}
		}
	}
	return -1;
}
