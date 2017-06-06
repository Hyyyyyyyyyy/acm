#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
struct node
{
	int x;
	int y;
	int time;
	int key;
	friend bool operator < (node a, node b)
	{
		return a.time > b.time;
	}
};
node now, after;
int visit[25][25][1050], keys[15];
char ar[25][25];
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int a, b, T, xb, yb;
void bfs();
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d %d", &a, &b, &T) != EOF)
	{
		xb = yb = MAX;
		for (i = 1; i <= a; i++)
		{
			scanf("%s", ar[i] + 1);
			if (xb == MAX && yb == MAX)
			{
				for (j = 1; j <= b; j++)
				{
					if (ar[i][j] == '@')
					{
						xb = i;
						yb = j;
					}
				}
			}
		}
		for (i = 0; i <= 11; i++)
			keys[i] = 1 << i;
		bfs();
		if (now.time < T && ar[now.x][now.y] == '^')
			printf("%d\n", now.time);
		else
			printf("-1\n");
	}
	return 0;
}
void bfs()
{
	int i, j, k, u;
	priority_queue<node>q;
	memset(visit, 0, sizeof(visit));
	now.x = xb;
	now.y = yb;
	now.time = 0;
	now.key = 0;
	visit[xb][yb][0] = 1;
	q.push(now);
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (ar[now.x][now.y] == '^' && now.time < T)
			return;
		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			after.time = now.time + 1;
			after.key = now.key;
			if (after.x > a || after.y > b || after.x < 1 || after.y < 1 || ar[after.x][after.y] == '*')
				continue;
			if (after.time == T && ar[after.x][after.y] != '^')
				continue;
			if (ar[after.x][after.y] == '^' && after.time >= T)
				continue;
			if (ar[after.x][after.y] >= 'a' && ar[after.x][after.y] <= 'z')
			{
				k = ar[after.x][after.y] - 'a';
				if (!visit[after.x][after.y][after.key | keys[k]])
				{
					after.key = after.key | keys[k];
					q.push(after);
					visit[after.x][after.y][after.key] = 1;
				}
			}
			if (ar[after.x][after.y] >= 'A' && ar[after.x][after.y] <= 'Z')
			{
				k = ar[after.x][after.y] - 'A';
				if (!visit[after.x][after.y][after.key] && after.key & keys[k])
				{
					q.push(after);
					visit[after.x][after.y][after.key] = 1;
				}
			}
			if ((ar[after.x][after.y] == '.' || ar[after.x][after.y] == '^' || ar[after.x][after.y] == '@') && !visit[after.x][after.y][after.key])
			{
				q.push(after);
				visit[after.x][after.y][after.key] = 1;
			}
		}
	}
	now.time = MAX;
}
