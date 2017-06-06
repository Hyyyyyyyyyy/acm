#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

struct node
{
	int now;
	int val;
	int next;
	int cost;
};
typedef pair <int, int> P;
struct comp
{
	bool operator () (P a, P b)
	{
		return a.first > b.first;
	}
};
struct node ar[200010];
int dist[1010], head[1010], cost[1010];
int n, m, s, t;
void P_dijkstra();

int main()
{
	int i, j, k, u, a, b, c, d, count;
	while (scanf("%d %d", &n, &m) != EOF && (n || m))
	{
		count = 0;
		memset(head, -1, sizeof(head));
		for (u = 1; u <= m; u++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			ar[count].now = b;
			ar[count].val = c;
			ar[count].cost = d;
			ar[count].next = head[a];
			head[a] = count++;
			ar[count].now = a;
			ar[count].val = c;
			ar[count].cost = d;
			ar[count].next = head[b];
			head[b] = count++;
		}
		scanf("%d %d", &s, &t);
		P_dijkstra();
		printf("%d %d\n", dist[t], cost[t]);
	}
	return 0;
}
void P_dijkstra()
{
	int i, j, k, u;
	P temp, after;
	priority_queue<P, vector<P>, comp>q;
	for (i = 0; i <= n; i++)
	{
		dist[i] = MAX;
		cost[i] = MAX;
	}
	dist[s] = 0;
	cost[s] = 0;
	temp.first = 0;
	temp.second = s;
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
				cost[after.second] = cost[temp.second] + ar[i].cost;
				q.push(after);
			}
			if (dist[after.second] == dist[temp.second] + after.first && cost[after.second] > cost[temp.second] + ar[i].cost)
			{
				dist[after.second] = dist[temp.second] + after.first;
				cost[after.second] = cost[temp.second] + ar[i].cost;
				q.push(after);
			}
		}
	}
}