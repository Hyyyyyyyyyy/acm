#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 10000 + 100;
const int maxm = 40000 + 100;
struct ZKW
{
	struct Edge
	{
		int to;
		int next;
		int cap;        //该边的最大流量
		int flow;       //该边的流量
		int cost;       //单位流量，单价为1m/元的路程花费（即距离）
	};
	Edge edge[maxm];
	int head[maxn];
	int pre[maxn];
	int dist[maxn];
	bool vis[maxn];
	int tol;
	int start;
	int end;
	int N;          //节点总个数，节点编号0~N-1
	void init()
	{
		tol = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v, int cap, int cost)
	{
		edge[tol].to = v;
		edge[tol].cap = cap;
		edge[tol].cost = cost;
		edge[tol].flow = 0;
		edge[tol].next = head[u];
		head[u] = tol++;
		edge[tol].to = u;
		edge[tol].cap = 0;
		edge[tol].cost = -cost;
		edge[tol].flow = 0;
		edge[tol].next = head[v];
		head[v] = tol++;
	}
	bool spfa()
	{
		queue<int>q;
		for (int i = 0; i < N; i++)
		{
			dist[i] = INF;
			vis[i] = false;
			pre[i] = -1;
		}
		dist[start] = 0;
		vis[start] = true;
		q.push(start);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			vis[u] = false;
			for (int i = head[u]; i != -1; i = edge[i].next)
			{
				int v = edge[i].to;
				if (edge[i].cap > edge[i].flow && dist[v] > dist[u] + edge[i].cost)
				{
					dist[v] = dist[u] + edge[i].cost;
					pre[v] = i;
					if (!vis[v])
					{
						vis[v] = true;
						q.push(v);
					}
				}
			}
		}
		if (pre[end] == -1)
			return false;
		else
			return true;
	}
	//返回的是最大流，&cost存的是最小费用
	int minCostMaxFlow(int &cost)
	{
		int flow = 0;
		cost = 0;
		while (spfa())
		{
			int Min = INF;
			for (int i = pre[end]; i != -1; i = pre[edge[i ^ 1].to])
			{
				if (Min > edge[i].cap - edge[i].flow)
					Min = edge[i].cap - edge[i].flow;
			}
			for (int i = pre[end]; i != -1; i = pre[edge[i ^ 1].to])
			{
				edge[i].flow += Min;
				edge[i ^ 1].flow -= Min;
				cost += edge[i].cost * Min;
			}
			flow += Min;
		}
		return flow;
	}
};
ZKW zkw;
//别忘了改maxn，maxm
//别忘了给 zkw.start, zkw.end, zkw.N 赋值 和 zkw.init() 初始化
//zkw.N为节点总个数，编号0~N-1
//cost为单位流量，单价为1m/元的路程花费（即为距离）
//要给minCostMaxFlow(int &cost) 那个cost的参数，带出来就是最小花费

struct Node
{
	int x;
	int y;
};
Node np[110], nh[110];
char s[200];
int N, M;
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d", &N, &M) != EOF && N + M)
	{
		zkw.init();
		int cntp = 0;
		int cnth = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%s", s);
			for (j = 0; j < M; j++)
			{
				if (s[j] == 'H')
				{
					nh[++cnth].x = i;
					nh[cnth].y = j;
				}
				if (s[j] == 'm')
				{
					np[++cntp].x = i;
					np[cntp].y = j;
				}
			}
		}
		zkw.start = 0;
		zkw.end = cntp + cnth + 1;
		zkw.N = cntp + cnth + 2;
		for (i = 1; i <= cntp; i++)
		{
			for (j = 1; j <= cnth; j++)
			{
				int t = abs(np[i].x - nh[j].x) + abs(np[i].y - nh[j].y);
				zkw.addedge(i, cntp + j, 1, t);
			}
		}
		for (i = 1; i <= cntp; i++)
		{
			zkw.addedge(0, i, 1, 0);
		}
		for (i = 1; i <= cnth; i++)
		{
			zkw.addedge(cntp + i, zkw.end, 1, 0);
		}
		int res = 0;
		zkw.minCostMaxFlow(res);
		printf("%d\n", res);
	}
	return 0;
}