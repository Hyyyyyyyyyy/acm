#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
using namespace std;
const int maxn = 12;
typedef long long ll;
struct Node
{
	int x;
	int y;
	int step;
	bool operator < (const Node& a) const
	{
		return step > a.step;
	}
};
Node now, after;
int dir[12][2] = { 1, 0,    -1,0,    0, -1,   0, 1,   2,1,   1, 2,   2,-1,   1,-2,    -2,-1,   -1,-2,   -1, 2,    -2,1 };
int ar[maxn][maxn];
int visit[maxn][maxn];
int ba, ea, bb, eb, bc, ec;
int bfs(int bx, int by, int ex, int ey)
{
	int i, j;
	memset(visit, 0, sizeof(visit));
	priority_queue<Node>q;
	now.x = bx;
	now.y = by;
	now.step = 0;
	q.push(now);
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (now.x == ex && now.y == ey)
			return now.step;
		for (i = 0; i < 12; i++)
		{
			after.x = now.x + dir[i][0];
			after.y = now.y + dir[i][1];
			if (i < 4)
				after.step = now.step + 1;
			else
				after.step = now.step + 1;
			if (after.x < 1 || after.x > 8 || after.y < 1 || after.y > 8 || visit[after.x][after.y])
				continue;
			visit[after.x][after.y] = 1;
			q.push(after);
		}
	}
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &ba, &ea);
			scanf("%d %d", &bb, &eb);
			scanf("%d %d", &bc, &ec);
			printf("%d\n", bfs(ba, ea, bb, eb) + bfs(bb, eb, bc, ec));
		}
	}
	return 0;
}
