#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = 1e8;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 100000 + 100;
const int maxm = 400000 + 100;
struct Edge
{
	int to;
	int next;
	int cap;
	int flow;
};
Edge edge[maxm];
int tol;
int head[maxn];
int gap[maxn];
int dep[maxn];
int cur[maxn];
int S[maxn];
int start;
int End;
int N;
int M;
void init()
{
	tol = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0)
{
	edge[tol].to = v;
	edge[tol].cap = w;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = rw;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}
void bfs()
{
	int i, j;
	queue<int>q;
	memset(dep, -1, sizeof(dep));
	memset(gap, 0, sizeof(gap));
	gap[0] = 1;
	dep[End] = 0;
	q.push(End);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dep[v] != -1)
				continue;
			dep[v] = dep[u] + 1;
			gap[dep[v]]++;
			q.push(v);
		}
	}
}
int max_flow()
{
	int i, j;
	bfs();
	memcpy(cur, head, sizeof(head));
	int top = 0;
	int u = start;
	int ans = 0;
	while (dep[start] < N)
	{
		if (u == End)
		{
			int Min = inf;
			int inser;
			for (i = 0; i < top; i++)
			{
				if (Min > edge[S[i]].cap - edge[S[i]].flow)
				{
					Min = edge[S[i]].cap - edge[S[i]].flow;
					inser = i;
				}
			}
			for (i = 0; i < top; i++)
			{
				edge[S[i]].flow += Min;
				edge[S[i] ^ 1].flow -= Min;
			}
			ans += Min;
			top = inser;
			u = edge[S[top] ^ 1].to;
			continue;
		}
		bool flag = false;
		int v;
		for (i = cur[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (edge[i].cap - edge[i].flow && dep[v] == dep[u] - 1)
			{
				flag = true;
				cur[u] = i;
				break;
			}
		}
		if (flag)
		{
			S[top++] = cur[u];
			u = v;
			continue;
		}
		int Min = N;
		for (i = head[u]; i != -1; i = edge[i].next)
		{
			if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
			{
				Min = dep[edge[i].to];
				cur[u] = i;
			}
		}
		gap[dep[u]]--;
		if (!gap[dep[u]])
			return ans;
		dep[u] = Min + 1;
		gap[dep[u]]++;
		if (u != start)
			u = edge[S[--top] ^ 1].to;
	}
	return ans;
}
int ar[maxn];
int main()
{
	int i, j, a, b;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		init();
		scanf("%d %d", &start, &End);
		End += N;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			addedge(i, i + N, ar[i]);
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &a, &b);
			addedge(a + N, b, inf);
			addedge(b + N, a, inf);
		}
        N *= 2;
		printf("%d\n", max_flow());
	}
	return 0;
}
//4289        拆点表示点权+isap