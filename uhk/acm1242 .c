#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	int x;
	int y;
	int time;
};
struct node now, after;
int visit[205][205], a, b;
int dir[4][2] = { 0, 1, 0, -1, -1, 0, 1, 0 }; //右左上下
char ar[205][205];
int bfs(int x1, int y1, int x2, int y2);
int main()
{
	int i, j, k, temp, min, x1, y1, x2, y2, n, m;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		getchar();
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				scanf("%c", &ar[i][j]);
				if (ar[i][j] == 'a')
				{
					x2 = i;
					y2 = j;
				}
			}
			getchar();
		}
		min = 100000000;
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				if (ar[i][j] == 'r')
				{
					x1 = i;
					y1 = j;
					for (n = 0; n <= a; n++)
					{
						for (m = 0; m <= b; m++)
							visit[n][m] = 1000000;
					}
					temp = bfs(x1, y1, x2, y2);
					if (temp != -1)
						min = (min <= temp) ? min : temp;
				}
			}
		}
		if (min != 100000000)
			printf("%d\n", min);
		else
			printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
	return 0;
}
int bfs(int x1, int y1, int x2, int y2)
{
	queue<node>q;
	int i, j;
	now.x = x1;
	now.y = y1;
	now.time = 0;
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (now.x == x2 && now.y == y2 && now.time == visit[x2][y2])
			return now.time;
		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			after.time = now.time + 1;
			if (after.x > a || after.x < 1 || after.y > b || after.y < 1)
				continue;
			if (ar[after.x][after.y] == '#')
				continue;
			if (ar[after.x][after.y] == 'x')
			{
				after.time++;
				/*ar[after.x][after.y] = '.';*/
			}
			if ((ar[after.x][after.y] == '.' || ar[after.x][after.y] == 'a' || ar[after.x][after.y] == 'r' || ar[after.x][after.y] == 'x') && after.time < visit[after.x][after.y])
			{
				q.push(after);
				visit[after.x][after.y] = after.time;
			}
		}
	}
	return -1;
}
