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
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 998244353ll;
const int maxn = 100000 + 100;
const int maxm = 200000 + 100;
int M, RES;
vector<int> G[maxn];
struct TARJAN
{
	struct Edge
	{
		int u;
		int to;
		int next;
	};
	Edge edge[maxm];
	int tol;
	int Index;
	int top;
	int Sccc;
	int head[maxn];
	int Low[maxn];
	int DFN[maxn];
	int Stack[maxn];
	bool Instack[maxn];
	int Belong[maxn];
	int num[maxn];
	int IN[maxn];
	void init()
	{
		tol = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v)
	{
		edge[tol].u = u;
		edge[tol].to = v;
		edge[tol].next = head[u];
		head[u] = tol++;
	}
	void Tarjan(int u)      
	{
		int v;
		Low[u] = DFN[u] = ++Index;
		Stack[++top] = u;
		Instack[u] = true;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (!DFN[v])
			{
				Tarjan(v);
				Low[u] = min(Low[u], Low[v]);
			}
			else if (Instack[v] && Low[u] > DFN[v])
			{
				Low[u] = DFN[v];
			}
		}
		if (Low[u] == DFN[u])
		{
			Sccc++;
			do
			{
				v = Stack[top--];
				Instack[v] = false;
				Belong[v] = Sccc;
				num[Sccc]++;
			} while (v != u);
		}
	}
	void dfs(int u, int fa, int cnt)
	{
		if (RES < cnt)
		{
			RES = cnt;
		}
		int i, j;
		for (i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (v == fa)
				continue;
			dfs(v, u, cnt + num[v]);
		}
	}
	void solve(int N)
	{
		memset(DFN, 0, sizeof(DFN));
		memset(Instack, false, sizeof(Instack));
		memset(num, 0, sizeof(num));
		memset(IN, 0, sizeof(IN));
		for (int i = 0; i <= N; i++)
			G[i].clear();
		Index = Sccc = top = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!DFN[i])
				Tarjan(i);
		}
		for (int i = 0; i < tol; i++)
		{
			if (Belong[edge[i].u] != Belong[edge[i].to])
			{
				int u = Belong[edge[i].u];
				int v = Belong[edge[i].to];
				G[u].push_back(v);
				IN[v]++;
			}
		}
		RES = 0;
		for (int i = 1; i <= Sccc; i++)
		{
			if(!IN[i])
			dfs(i, 0, num[i]);
		}
	}
};
TARJAN tarjan;
int main()
{
	int i, j, k, a, b, c, m, N;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		tarjan.init();
		for (m = 1; m <= M; m++)
		{
			scanf("%d %d", &a, &b);
			tarjan.addedge(a, b);
		}
		tarjan.solve(N);
		printf("%d\n", RES);
	}
	return 0;
}