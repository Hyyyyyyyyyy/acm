#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 100000000
using namespace std;
struct node
{
	int now;
	int val;
	int next;
};
struct node ar[20010];
typedef pair<int, int> P;
struct comp
{
	bool operator () (P a, P b)
	{
		return a.first > b.first;
	}
};
int dist[10010], head[10010], n, m, count;

void P_dijkstra();

int main()
{
	int i, j, k, u, a, b, c, count;
	while (scanf("%d %d", &n, &m) != EOF && (n || m))
	{
		count = 0;
		memset(head, -1, sizeof(head));
		for (i = 0; i <= n; i++)
			dist[i] = MAX;
		for (u = 1; u <= m; u++)
		{
			scanf("%d %d %d", &a, &b, &c);
			ar[count].now = b;
			ar[count].val = c;
			ar[count].next = head[a];
			head[a] = count;
			count++;
			ar[count].now = a;
			ar[count].val = c;
			ar[count].next = head[b];
			head[b] = count;
			count++;
		}
		P_dijkstra();
		printf("%d\n", dist[n]);
	}
	return 0;
}
void P_dijkstra()
{
	int i, j, k, u;
	priority_queue<P, vector<P>, comp>q;
	P temp, after;
	temp.first = 0;
	temp.second = 1;
	dist[1] = 0;
	q.push(temp);
	while (!q.empty())
	{
		temp = q.top();
		q.pop();

		if (dist[temp.second] < temp.first)
			continue;
		for (i = head[temp.second]; i != -1; i = ar[i].next)
		{
			after.first = ar[i].val;
			after.second = ar[i].now;
			if (dist[after.second] > dist[temp.second] + after.first)
			{
				dist[after.second] = dist[temp.second] + after.first;
				q.push(after);
			}
		}
	}
}
