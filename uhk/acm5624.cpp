#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 15000 + 10;
const int MAX = 100000000;
struct node
{
	int u;
	int v;
	ll w;
};
node edge[maxn];
int N, M, cnt;
ll res;
int F[maxn];
bool comp(const node& a, const node& b)
{
	return a.w < b.w;
}
void addedge(int u, int v, ll w)
{
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt++].w = w;
}
int find(int x)
{
	if (F[x] == -1)
		return x;
	else
		return F[x] = find(F[x]);
}
ll kruskal(int f)
{
	int i, j, k, count = 0;
	ll ans = 0;
	memset(F, -1, sizeof(F));
	for (i = f; i < cnt; i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		ll w = edge[i].w;
		int t1 = find(u);
		int t2 = find(v);
		if (t1 != t2)
		{
			F[t2] = t1;
			ans += w;
			count++;
		}
		if (count == N - 1)
			break;
	}
	if (count < N - 1)
		return -1;
	else
		return edge[i].w - edge[f].w;
}
int main()
{
	int i, j, k, n, m, a, b;
	ll c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			cnt = 0;
			res = MAX;
			scanf("%d %d", &N, &M);
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d %lld", &a, &b, &c);
				addedge(a, b, c);
			}
			sort(edge, edge + cnt, comp);
			res = kruskal(0);
			if (res == -1)
			{
				printf("-1\n");
				continue;
			}
			for (i = 1; i <= cnt-N+1; i++)
			{
				ll t = kruskal(i);
				if (t < 0)
					continue;
				if (res > t)
					res = t;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
