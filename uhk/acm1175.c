#include<cstdio>  
#include<queue> 
using namespace std;
struct node
{
	int x;
	int y;
	int corner;
	int sta;
};
queue<node>q;
int dir[4][2] = { { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };
int visit[1005][1005];
int ar[1005][1005];
int a, b;
bool bfs(int x1, int y1, int x2, int y2);
int main()
{
	int i, j, k, u, n, m, x1, x2, y1, y2;
	struct node after;
	while (scanf("%d %d", &a, &b) != EOF && (a || b))
	{

		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		scanf("%d", &n);
		for (u = 1; u <= n; u++)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if (ar[x1][y1] == 0 || ar[x2][y2] == 0 || ar[x1][y1] != ar[x2][y2] || (x1 == x2 && y1 == y2))
			{
				printf("NO\n");
				continue;
			}
			for (i = 1; i <= a; i++)
			{
				for (j = 1; j <= b; j++)
					visit[i][j] = 11;
			}
			visit[x1][y1] = 0;
			while (!q.empty())
				q.pop();
			for (i = 0; i < 4; i++)
			{
				after.sta = i;
				after.corner = 0;
				after.x = x1;
				after.y = y1;
				q.push(after);
			}
			if (bfs(x1, y1, x2, y2) == true)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
bool bfs(int x1, int y1, int x2, int y2)
{
	int i, j;
	struct node now, after;

	while (q.empty() == 0)
	{
		now = q.front();
		q.pop();

		if (now.x == x2 && now.y == y2 && now.corner <= 2)
			return true;

		for (i = 0; i < 4; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];

			if (after.x < 1 || after.x > a || after.y < 1 || after.y > b)
				continue;
			if (now.sta == i)
			{
				after.corner = now.corner;
				after.sta = now.sta;
			}
			else
			{
				after.corner = now.corner + 1;
				after.sta = i;
			}
			if (after.corner > 2)
				continue;
			if (((after.x == x2 && after.y == y2) || ar[after.x][after.y] == 0) && after.corner <= visit[after.x][after.y])
			{
				q.push(after);
				visit[after.x][after.y] = after.corner;
			}
		}
	}
	return false;
}
