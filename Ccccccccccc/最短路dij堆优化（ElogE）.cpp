#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
const int INF = 1000000000;
const int maxn = 205;
const int maxm = 1000;
struct P_DIJ
{
	struct Edge
	{
		int to;
		int val;
		int next;
	};
	Edge edge[maxm];
	typedef pair<int, int> P;
	struct comp
	{
		bool operator () (const P &a, const P &b)
		{
			return a.second > b.second;
		}
	};
	int head[maxn];
	int dist[maxn];
	int tol;
	int start;
	int N;
	void init()
	{
		tol = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v, int w)
	{
		edge[tol].to = v;
		edge[tol].val = w;
		edge[tol].next = head[u];
		head[u] = tol++;
	}
	void P_dijkstra()
	{
		int i, j, k;
		priority_queue<P, vector<P>, comp>Q;
		P now, after;
		for (i = 0; i <= N; i++)
			dist[i] = INF;
		now.first = start;
		now.second = 0;
		dist[start] = 0;
		Q.push(now);
		while (!Q.empty())
		{
			now = Q.top();
			Q.pop();
			if (dist[now.first] < now.second)
				continue;
			for (i = head[now.first]; i != -1; i = edge[i].next)
			{
				after.first = edge[i].to;
				after.second = edge[i].val;
				if (dist[after.first] > dist[now.first] + after.second)
				{
					dist[after.first] = dist[now.first] + after.second;
					Q.push(after);
				}
			}
		}
	}
};
P_DIJ dij;
//先给dij.start, dij.N赋值
//初始化dij.init()