#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#define MAX 100000000
using namespace std;

struct node
{
	int now;
	int val;
	int next;
};
struct node ar[40010];
int dist[1010], head[1010], n, m, d;
typedef pair <int, int> P;
struct comp
{
	bool operator () (P a, P b)
	{
		return a.first > b.first;
	}
};
void P_dijkstra();

int main()
{
	int i, j, k, u, count, a, b, c, min, begin;
	while (scanf("%d %d %d", &n, &m, &d) != EOF)
	{
		count = 0;
		memset(head, -1, sizeof(head));
		for (u = 1; u <= m; u++)
		{
			scanf("%d %d %d", &a, &b, &c);
			ar[count].now = a;
			ar[count].val = c;
			ar[count].next = head[b];
			head[b] = count++;
		}
		P_dijkstra();
		scanf("%d", &k);
		min = MAX;
		for (i = 1; i <= k; i++)
		{
			scanf("%d", &begin);
			if (min >= dist[begin])
			{
				min = dist[begin];
			}
		}
		if (min != MAX)
			printf("%d\n", min);
		else
			printf("-1\n");
	}
	return 0;
}
void P_dijkstra()
{
	int i, k, j, u;
	P temp, after;
	priority_queue<P, vector<P>, comp>q;
	for (i = 0; i <= n; i++)
		dist[i] = MAX;
	temp.first = 0;
	temp.second = d;
	dist[d] = 0;
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
