#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 150;
const int INF = 1e9;
typedef long long ll;
int visit[maxn][maxn];
int ar[maxn][maxn];
struct Node
{
	int x;
	int h;
	int doudou;
};
Node now, after;
bool bfs()
{
	queue<Node>q;
	memset(visit, 0, sizeof(visit));
	now.x = 0;
	now.h = 0;
	now.doudou = 0;
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (now.x == 100 && now.h == 0)
			return true;
		if (!now.doudou)
		{
			after.x = now.x + 1;
			after.h = 0;
			after.doudou = 0;
			if (!visit[after.x][after.h] && !ar[after.x][after.h])
			{
				q.push(after);
				visit[after.x][after.h] = 1;
			}
			after.x = now.x + 1;
			after.h = 1;
			after.doudou = 1;
			if (!visit[after.x][after.h] && !ar[after.x][after.h] && !ar[after.x + 1][after.h + 1] && !ar[after.x + 2][after.h] && !ar[after.x + 3][after.h - 1])
			{
				q.push(after);
				visit[after.x][after.h] = 1;
			}
		}
		else
		{
			if (now.h == 1 && now.doudou == 1)
			{
				after.x = now.x + 1;
				after.h = now.h + 1;
				after.doudou = -1;
				q.push(after);
				visit[after.x][after.h] = 1;
			}
			else if (now.h == 2)
			{
				after.x = now.x + 1;
				after.h = now.h - 1;
				after.doudou = -1;
				q.push(after);
				visit[after.x][after.h] = 1;
			}
			else if (now.h == 1 && now.doudou == -1)
			{
				after.x = now.x + 1;
				after.h = now.h - 1;
				after.doudou = 0;
				q.push(after);
				visit[after.x][after.h] = 1;
			}
		}
	}
	return false;
}
int main()
{
	int i, j, k, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			ar[a][b] = 1;
		}
		if (ar[0][0])
		{
			printf("0\n");
			continue;
		}
		if (bfs())
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}