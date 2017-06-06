#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int ar[20][20];
int before[20], flow[20];
int n, m, Begin, End;
int bfs();
int EK();
int main()
{
	int i, j, k, u, a, b, c, h, cas = 1;
	while (scanf("%d", &k) != EOF)
	{
		for (u = 1; u <= k; u++)
		{
			scanf("%d %d", &n, &m);
			memset(ar, 0, sizeof(ar));
			Begin = 1;
			End = n;
			for (h = 1; h <= m; h++)
			{
				scanf("%d %d %d", &a, &b, &c);
				ar[a][b] += c;
			}
			printf("Case %d: %d\n", cas++, EK());
		}
	}
	return 0;
}
int EK()
{
	int i, j, k, now, pre, maxflow = 0, temp;
	while ((temp = bfs()) != -1)
	{
		now = End;
		maxflow += temp;
		while (now != Begin)
		{
			pre = before[now];
			ar[pre][now] -= temp;
			ar[now][pre] += temp;
			now = pre;
		}
	}
	return maxflow;
}

int bfs()
{
	int i, j, k, t;
	queue<int>q;
	memset(before, -1, sizeof(before));
	before[Begin] = 0;
	flow[Begin] = MAX;
	q.push(Begin);
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (t == End)
			break;
		for (i = 1; i <= n; i++)
		{
			if (i != Begin && before[i] == -1 && ar[t][i])
			{
				before[i] = t;
				flow[i] = (flow[t] < ar[t][i]) ? flow[t] : ar[t][i];
				q.push(i);
			}
		}
	}
	return (before[End] == -1) ? -1 : flow[n];
}