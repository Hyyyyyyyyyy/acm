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
};
struct node ar[20010];
int dist[200], head[200], n, m, countt;
char sa[200][80], a[80], b[80];
typedef pair<int, int>P;
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
	int i, j, k, u, x1, x2, cnt, c;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		countt = 0;
		scanf("%s %s", sa[countt], sa[countt + 1]);
		countt += 2;
		cnt = 0;
		memset(head, -1, sizeof(head));
		for (m = 1; m <= n; m++)
		{
			scanf("%s %s %d", a, b, &c);
			x1 = MAX;
			x2 = MAX;
			for (j = 0; j < countt; j++)
			{
				if (strcmp(a, sa[j]) == 0)
				{
					x1 = j;
					break;
				}
			}
			if (x1 == MAX)
			{
				strcpy(sa[countt], a);
				x1 = countt;
				countt++;
			}
			for (j = 0; j < countt; j++)
			{
				if (strcmp(b, sa[j]) == 0)
				{
					x2 = j;
					break;
				}
			}
			if (x2 == MAX)
			{
				strcpy(sa[countt], b);
				x2 = countt;
				countt++;
			}
			ar[cnt].now = x2;
			ar[cnt].val = c;
			ar[cnt].next = head[x1];
			head[x1] = cnt++;
			ar[cnt].now = x1;
			ar[cnt].val = c;
			ar[cnt].next = head[x2];
			head[x2] = cnt++;
		}
		if (strcmp(sa[0], sa[1]) == 0)
		{
			printf("0\n");
			continue;
		}
		P_dijkstra();
		if (dist[1] != MAX)
			printf("%d\n", dist[1]);
		else
			printf("-1\n");
	}
	return 0;
}
void P_dijkstra()
{
	int i, j, k, u;
	P temp, after;
	for (i = 0; i <= countt; i++)
		dist[i] = MAX;
	dist[0] = 0;
	priority_queue<P, vector<P>, comp>q;
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
