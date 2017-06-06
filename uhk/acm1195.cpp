#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int MAX = 100000000;
struct node
{
	int x1;
	int x2;
	int x3;
	int x4;
	int step;
	friend bool operator < (node a, node b)
	{
		return a.step > b.step;
	}
};
node now, after;
int visit[11][11][11][11];
char ar[5], tar[5];
void bfs();
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s", ar + 1);
			scanf("%s", tar + 1);
			bfs();
			printf("%d\n", now.step);
		}
	}
	return 0;
}
void bfs()
{
	int i, j, k, u;
	memset(visit, 0, sizeof(visit));
	priority_queue<node>q;
	now.x1 = ar[1] - '0';
	now.x2 = ar[2] - '0';
	now.x3 = ar[3] - '0';
	now.x4 = ar[4] - '0';
	now.step = 0;
	visit[now.x1][now.x2][now.x3][now.x4] = 1;
	q.push(now);
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (now.x1 == tar[1] - '0' && now.x2 == tar[2] - '0' && now.x3 == tar[3] - '0' && now.x4 == tar[4] - '0')
			return;

		after = now;
		after.x1--;
		after.step = now.step + 1;
		if (after.x1 < '1' - '0')
			after.x1 = '9' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		after.x2--;
		after.step = now.step + 1;
		if (after.x2 < '1' - '0')
			after.x2 = '9' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		after.x3--;
		after.step = now.step + 1;
		if (after.x3 < '1' - '0')
			after.x3 = '9' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		after.x4--;
		after.step = now.step + 1;
		if (after.x4 < '1' - '0')
			after.x4 = '9' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		after.x1++;
		after.step = now.step + 1;
		if (after.x1 > '9' - '0')
			after.x1 = '1' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		after.x2++;
		after.step = now.step + 1;
		if (after.x2 > '9' - '0')
			after.x2 = '1' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		after.x3++;
		after.step = now.step + 1;
		if (after.x3 > '9' - '0')
			after.x3 = '1' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		after.x4++;
		after.step = now.step + 1;
		if (after.x4 > '9' - '0')
			after.x4 = '1' - '0';
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		u = after.x1;
		after.x1 = after.x2;
		after.x2 = u;
		after.step = now.step + 1;
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		u = after.x2;
		after.x2 = after.x3;
		after.x3 = u;
		after.step = now.step + 1;
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
		after = now;
		u = after.x3;
		after.x3 = after.x4;
		after.x4 = u;
		after.step = now.step + 1;
		if (!visit[after.x1][after.x2][after.x3][after.x4])
		{
			q.push(after);
			visit[after.x1][after.x2][after.x3][after.x4] = 1;
		}
	}
}