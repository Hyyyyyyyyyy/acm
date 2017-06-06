#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 999999999
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
int dist[110], head[110], n, m;
void P_dijkstra();
int main()
{
	int t, cas, i, j, k, u, a, b, c, count, sum, S, power[110], bag[10010];
	while (scanf("%d", &t) != EOF)
	{
		for (cas = 1; cas <= t; cas++)
		{
			scanf("%d %d", &n, &m);
			count = 0;
			memset(head, -1, sizeof(head));
			for (i = 1; i <= m; i++)
			{
				scanf("%d %d %d", &a, &b, &c);
				ar[count].now = b;
				ar[count].val = c;
				ar[count].next = head[a];
				head[a] = count++;
				ar[count].now = a;
				ar[count].val = c;
				ar[count].next = head[b];
				head[b] = count++;
			}
			sum = 0;
			for (i = 1; i <= n; i++)
			{
				scanf("%d", &power[i]);
				sum += power[i];
			}
			P_dijkstra();
			memset(bag, 0, sizeof(bag));
			S = 0;
			for (i = 0; i <= n; i++)
				if (dist[i] != MAX)
					S += dist[i];
			for (i = 1; i <= n; i++)
			{
				for (j = S; j >= dist[i]; j--)
				{
					bag[j] = (bag[j] > bag[j - dist[i]] + power[i]) ? bag[j] : (bag[j - dist[i]] + power[i]);
				}
			}
			for (i = 0; i < S; i++)
			{
				if (bag[i] > sum / 2)
				{
					printf("%d\n", i);
					break;
				}
			}
			if (i == S)
				printf("impossible\n");
		}
	}
	return 0;
}
void P_dijkstra()
{
	int i, j, k;
	P temp, after;
	priority_queue<P, vector<P>, comp>q;
	for (i = 0; i <= n; i++)
		dist[i] = MAX;
	dist[0] = 0;
	temp.first = 0;
	temp.second = 0;
	q.push(temp);
	while (!q.empty())
	{
		temp = q.top();
		q.pop();
		if (dist[temp.second] < temp.first)
			continue;
		for (i = head[temp.second]; i != -1; i = ar[i].next)
		{
			after.second = ar[i].now;
			after.first = ar[i].val;
			if (dist[after.second] > dist[temp.second] + after.first)
			{
				dist[after.second] = dist[temp.second] + after.first;
				q.push(after);
			}
		}
	}
}
