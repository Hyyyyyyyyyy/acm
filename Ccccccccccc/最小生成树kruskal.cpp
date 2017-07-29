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
const int maxn = 105;
const int maxm = 10000;
struct KRUSKAL
{
	struct Edge
	{
		int u;
		int v;
		int w;
	};
	Edge edge[maxm];
	int tol;
	int F[maxn];
	void init()
	{
		tol = 0;
	}
	struct comp
	{
		bool operator () (Edge& a, Edge& b)
		{
			return a.w < b.w;
		}
	};
	void addedge(int a, int b, int c)
	{
		edge[tol].u = a;
		edge[tol].v = b;
		edge[tol++].w = c;
	}
	int find(int x)
	{
		if (F[x] == -1)
			return x;
		else
			return F[x] = find(F[x]);
	}
	int kruskal(int n)
	{
		memset(F, -1, sizeof(F));
		sort(edge, edge + tol, comp());
		int cnt = 0;
		int ans = 0;
		for (int i = 0; i < tol; i++)
		{
			int u = edge[i].u;
			int v = edge[i].v;
			int w = edge[i].w;
			int t1 = find(u);
			int t2 = find(v);
			if (t1 != t2)
			{
				ans += w;
				F[t1] = t2;
				cnt++;
			}
			if (cnt == n - 1)
				break;
		}
		if (cnt < n - 1)
			return -1;
		else
			return ans;
	}
};
KRUSKAL kruskal;
//kruskal.krusal(n),  n为点数
//kruskal.init()