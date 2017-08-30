#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
const int INF = 2147483640;
const int maxn = 1000 + 100;
const int maxm = 6000 + 100;
struct TARJAN
{
	struct Edge
	{
		int to;
		int next;
	};
	Edge edge[maxm];
	int ar[maxn][maxn];
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
	void init()
	{
		tol = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v)
	{
		edge[tol].to = v;
		edge[tol].next = head[u];
		head[u] = tol++;
	}
	void Tarjan(int u)      //?????????, ??????????
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
	void solve(int N)
	{
		int i, j, k, u;
		memset(DFN, 0, sizeof(DFN));
		memset(Instack, false, sizeof(Instack));
		memset(num, 0, sizeof(num));
		Index = Sccc = top = 0;
		for (i = 1; i <= N; i++)
		{
			if (!DFN[i])
				Tarjan(i);
		}
		memset(ar, 0, sizeof(ar));
		for (i = 1; i <= N; i++)
		{
			for (j = head[i]; j != -1; j = edge[j].next)
			{
				int t = edge[j].to;
				if (Belong[i] == Belong[t])
					continue;
				ar[Belong[i]][Belong[t]] = 1;
			}
		}
		for (i = 1; i <= Sccc; i++)
		{
			for (j = 1; j <= Sccc; j++)
			{
				for (k = 1; k <= Sccc; k++)
				{
					if (ar[i][k] && ar[k][j])
						ar[i][j] = 1;
				}
			}
		}
		int doudou = 1;
		for (i = 1; i <= Sccc; i++)
		{
			for (j = i + 1; j <= Sccc; j++)
			{
				if (!ar[i][j] && !ar[j][i])
				{
					doudou = 0;
					break;
				}
			}
			if (!doudou)
				break;
		}
		if (doudou)
			printf("I love you my love and our love save us!\n");
		else
			printf("Light my fire!\n");
	}
};
TARJAN tarjan;

int main()
{
	int i, j, k, u, n, m, N, M, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			tarjan.init();
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d", &a, &b);
				tarjan.addedge(a, b);
			}
			tarjan.solve(N);
		}
	}
	return 0;
}