#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const int MAX = 100000000;
using namespace std;
int dir[4][2] = { 0, -1, 0, 1, -1, 0, 1, 0 };
struct Point
{
	int x, y;
	Point() {}
	Point(int a, int b) :x(a), y(b) {}
	Point go(int direction_id) { return Point(x + dir[direction_id][0], y + dir[direction_id][1]); }
};
struct Point start, nextp;
bool visit[10][10];
bool doudou;	//标记；
char ar[10][10];
int T, a, b, x1, Y1, x2, y2;
void dfs(int x, int y, int time);
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d %d", &a, &b, &T) != EOF && (a || b || T))
	{
		x1 = Y1 = x2 = y2 = MAX;
		for (i = 1; i <= a; i++)
		{
			scanf("%s", ar[i] + 1);
			if (x1 != MAX && x2 != MAX && Y1 != MAX && y2 != MAX)
				continue;
			for (j = 1; j <= b; j++)
			{
				if (ar[i][j] == 'S')
				{
					x1 = i;
					Y1 = j;
				}
				if (ar[i][j] == 'D')
				{
					x2 = i;
					y2 = j;
				}
			}
		}
		
		if (T < abs(x1 - x2) + abs(Y1 - y2) || (x1 + Y1 + x2 + y2 + T) % 2 != 0)
		{
			printf("NO\n");
			continue;
		}
		doudou = false;
		memset(visit, false, sizeof(visit));
		visit[x1][Y1] = true;
		dfs(x1, Y1, 0);
		if (doudou)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}
void dfs(int x, int y, int time)
{
	int i, temp;
	Point start(x, y);
	if (doudou)
		return;
	if (start.x == x2 && start.y == y2 && time == T)
	{
		doudou = true;
		return;
	}
	if (start.x == x2 && start.y == y2 && time != T)
		return;
	if (start.x < 1 || start.y < 1 || start.x > a || start.y > b || ar[start.x][start.y] == 'X')
		return;
	if ((start.x != x2 || start.y != y2) && time == T)
		return;
	if (visit[start.x][start.y] && time != 0)
		return;
	temp = T - time - abs(start.x - x2) - abs(start.y - y2);
	if (temp < 0 || temp % 2 != 0)
		return;
	for (i = 0; i < 4; i++)
	{
		nextp = start.go(i);
		visit[start.x][start.y] = true;
		dfs(nextp.x, nextp.y, time + 1);
		visit[start.x][start.y] = false;
		if (doudou)
			return;
	}
}
