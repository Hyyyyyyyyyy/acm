#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int MAX = 100000 + 10;
struct node
{
	ll val;
	ll cost;
	ll minval;
	ll mincost;
};
node ar[100000 * 2];
ll cnt, N, M, K1, K2;
ll head[100000 * 2];
struct Edge
{
	int u;
	int v;
	int val;
	int next;
};
Edge edge[MAX];
void addedge(int x, int y, int z)
{
	edge[cnt].u = x;
	edge[cnt].v = y;
	edge[cnt].val = z;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}
void dfs(ll n)
{
	ll i, j, k;
	for (i = head[n]; i != -1; i = edge[i].next)
	{
		ll u = edge[i].u;
		ll v = edge[i].v;
		ll w = edge[i].val;
		ar[v].mincost = min(ar[u].minval, min(ar[u].mincost + ar[u].val, ar[u].mincost + w));
		ar[v].minval = min(ar[v].mincost + ar[v].val, ar[u].minval);
		dfs(v);
	}
}
int main()
{
	ll i, a, b, c;
	while (scanf("%lld", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%lld", &ar[i].val);
		}
		ar[1].mincost = 0;
		ar[1].minval = ar[1].val;
		ar[1].cost = 0;
		memset(head, -1, sizeof(head));
		cnt = 0;
		for (i = 2; i <= N; i++)
		{
			scanf("%lld %lld", &a, &b);
			addedge(a, i, b);
			ar[i].cost = b;
		}
		dfs(1);
		for (i = 1; i <= N; i++)
			printf("%lld ", ar[i].mincost);
		putchar('\n');
	}
	return 0;
}