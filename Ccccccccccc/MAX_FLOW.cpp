#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 30;
const int maxm = 1010;
const int INF = 1e10;
struct DINIC
{
	struct Edge
	{
		int to;
		int cap;
		int rev;
		Edge() {}
		Edge(int a, int b, int c) : to(a), cap(b), rev(c) {}
	};
	vector<Edge>G[maxm];
	int level[maxn];
	int iter[maxn];
	void clear(int n)
	{
		for (int i = 0; i <= n; i++)
			G[i].clear();
	}
	void addedge(int u, int v, int cap)
	{
		G[u].push_back(Edge(v, cap, G[v].size()));
		G[v].push_back(Edge(u, 0, G[u].size() - 1));
	}
	void bfs(int s)
	{
		int i, j;
		queue<int>q;
		memset(level, -1, sizeof(level));
		level[s] = 0;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (i = 0; i < G[u].size(); i++)
			{
				Edge &e = G[u][i];
				if (e.cap > 0 && level[e.to] == -1)
				{
					level[e.to] = level[u] + 1;
					q.push(e.to);
				}
			}
		}
	}
	int dfs(int st, int end, int flow)
	{
		if (st == end)
			return flow;
		int i, j;
		for (i = iter[st]; i < G[st].size(); i++)
		{
			Edge &e = G[st][i];
			if (e.cap > 0 && level[e.to] == level[st] + 1)
			{
				int d = dfs(e.to, end, min(flow, e.cap));
				if (d > 0)
				{
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					iter[st] = i;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int st, int end)
	{
		int flow = 0;
		while (1)
		{
			memset(iter, 0, sizeof(iter));
			bfs(st);
			if (level[end] == -1)
				return flow;
			int f;
			while ((f = dfs(st, end, INF)) > 0)
				flow += f;
		}
	}
};
DINIC dinic;
//不要忘了先clear()