#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
const int MAX = 100000000;
const int MIN = -100000000;
using namespace std;
struct node
{
	int x;
	int step;
	friend bool operator < (node a, node b)
	{
		return a.step > b.step;
	}
};
struct node now, after;
int n, m, visit[200100];
void bfs();
int main()
{
	int i, j, k;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		bfs();
		printf("%d\n", now.step);
	}
	return 0;
}
void bfs()
{
	priority_queue<node>q;

	int i, j, k;
	for (i = 0; i < 200100; i++)
		visit[i] = MAX;
	now.x = n;
	now.step = 0;
	visit[n] = 0;
	q.push(now);
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (now.x == m)
			return;
		after.x = now.x * 2;
		after.step = now.step + 1;
		if (visit[after.x] > after.step && after.x >= 0 && after.x < 200100)
		{
			q.push(after);
			visit[after.x] = after.step;
		}
		after.x = now.x + 1;
		after.step = now.step + 1;
		if (visit[after.x] > after.step && after.x >= 0 && after.x < 200100)
		{
			q.push(after);
			visit[after.x] = after.step;
		}
		after.x = now.x - 1;
		after.step = now.step + 1;
		if (visit[after.x] > after.step && after.x >= 0 && after.x < 200100)
		{
			q.push(after);
			visit[after.x] = after.step;
		}
	}
}
