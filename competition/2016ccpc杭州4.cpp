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
const ll INF = 2147483640;
const ll maxn = 1000 + 100;
const ll maxm = 1000000 + 100;
struct Node
{
	ll r;
	ll x;
	ll y;
	ll c;
};
Node node[maxn];
struct TARJAN
{
	struct Edge
	{
		ll to;
		ll next;
	};
	Edge edge[maxm];
	ll tol;
	ll Index;
	ll top;
	ll Sccc;
	ll head[maxn];
	ll Low[maxn];
	ll DFN[maxn];
	ll Stack[maxn];
	bool Instack[maxn];
	ll Belong[maxn];
	ll num[maxn];
	void init()
	{
		tol = 0;
		memset(head, -1, sizeof(head));
	}
	void addedge(ll u, ll v)
	{
		edge[tol].to = v;
		edge[tol].next = head[u];
		head[u] = tol++;
	}
	void Tarjan(ll u)      //将一个环缩成一个点, 多个环相连只算一个环
	{
		ll v;
		Low[u] = DFN[u] = ++Index;
		Stack[++top] = u;
		Instack[u] = true;
		for (ll i = head[u]; i != -1; i = edge[i].next)
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
				num[Sccc] = min(num[Sccc], node[v].c);
			} while (v != u);
		}
	}
	ll IN[maxn];
	ll ar[maxn][maxn];
	ll solve(ll N)
	{
		ll i, j;
		memset(DFN, 0, sizeof(DFN));
		memset(Instack, false, sizeof(Instack));
		for (i = 0; i <= N; i++)
			num[i] = INF;
		Index = Sccc = top = 0;
		for (ll i = 1; i <= N; i++)
		{
			if (!DFN[i])
				Tarjan(i);
		}
		memset(ar, 0, sizeof(ar));
		memset(IN, 0, sizeof(IN));
		for (i = 1; i <= N; i++)
		{
			for (j = head[i]; j != -1; j = edge[j].next)
			{
				ll v = edge[j].to;
				if (Belong[i] != Belong[v] && !ar[Belong[i]][Belong[v]])
				{
					IN[Belong[v]]++;
					ar[Belong[i]][Belong[v]] = 1;
				}
			}
		}
		ll res = 0;
		for (i = 1; i <= Sccc; i++)
		{
			if (IN[i] == 0)
			{
				res += num[i];
			}
		}
		return res;
	}
};
TARJAN tarjan;
//tarjan.init()
//tarjan.solve(N);
//N  1~N
//Sccc  1~Sccc;
//solve()变化很多
bool DIS(ll n, ll m)
{
	if ((node[n].x - node[m].x) * (node[n].x - node[m].x) + (node[n].y - node[m].y) * (node[n].y - node[m].y) <= node[n].r*node[n].r)
		return true;
	return false;
}
int main()
{
	ll i, j, k, n, m, a, b, N;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			tarjan.init();
			for (i = 1; i <= N; i++)
			{
				scanf("%lld %lld %lld %lld", &node[i].x, &node[i].y, &node[i].r, &node[i].c);
			}
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= N; j++)
				{
					if (i != j)
					{
						if (DIS(i, j))
							tarjan.addedge(i, j);
					}
				}
			}
			printf("Case #%lld: %lld\n", m, tarjan.solve(N));

		}
	}
	return 0;
}