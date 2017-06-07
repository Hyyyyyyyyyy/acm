#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1000000 + 100;
typedef long long ll;
struct Node
{
	ll s;
	int r;
	Node() {}
	Node(ll x, int y) : s(x), r(y) {}
	Node(const Node& p)
	{
		s = p.s;
		r = p.r;
	}
	bool operator < (const Node& a) const
	{
		return s > a.s;
	}
};
Node G[maxn], now;
priority_queue<Node>q;
struct Edge
{
	int l;
	int r;
	int mid;
	ll ml;
};
Edge edge[maxn * 4];
int N, K, top;
ll ar[maxn], sum[maxn], sa[maxn];
int stack[maxn];
 bool comp(const ll a, const ll b)
 {
 		return a < b;
 }
void pushup(int root)
{
	edge[root].ml = min(edge[root * 2].ml, edge[root * 2 + 1].ml, comp);
}
void build(int root, int begin, int end)
{
	edge[root].l = begin;
	edge[root].r = end;
	edge[root].mid = (begin + end) / 2;
	if (begin == end)
	{
		edge[root].ml = ar[begin];
		return;
	}
	build(root * 2, edge[root].l, edge[root].mid);
	build(root * 2 + 1, edge[root].mid + 1, edge[root].r);
	pushup(root);
}
int query(int root, int x, ll res)
{
	if (x <= edge[root].l)
	{
		if (edge[root].ml > res)
			return 0;
		if (edge[root].l == edge[root].r)
			return edge[root].l;
	}
	if (x <= edge[root].mid)
	{
		int t = query(root * 2, x, res);
		if (t)
			return t;
	}
	return query(root * 2 + 1, x, res);
}
void dfs(int x, ll res)
{
	int i;
	if (K == 0)
		return;
	if (res == 0)
	{
		K--;
		if (K == 0)
		{
			for (i = 1; i <= top; i++)
			{
				if (i != 1)
					putchar(' ');
				printf("%d", stack[i]);
			}
			putchar('\n');
		}
		return;
	}
	for (i = x + 1; i <= N; i++)
	{
		i = query(1, i, res);
		if (i)
		{
			stack[++top] = i;
			dfs(i, res - ar[i]);
			top--;
		}
		else
			return;
	}
}
int main()
{
	int i, j, k, u, n, m, a, b;
	//freopen("IN.txt", "r", stdin);
	while (scanf("%d %d", &N, &K) != EOF)
	{
		K--;
		if (K == 0)
		{
			printf("0\n");
			continue;
		}
		while (!q.empty())
			q.pop();
		for (i = 1; i <= N; i++)
		{
			scanf("%lld", &ar[i]);
			sa[i] = ar[i];
		}
		sort(sa + 1, sa + 1 + N);
		q.push(Node(sa[1], 1));
		for (i = 1; i <= K; i++)
		{
			now = q.top();
			q.pop();
			sum[i] = now.s;
			if (i < K && now.r < N)
			{
				q.push(Node(now.s + sa[now.r + 1], now.r + 1));
				q.push(Node(now.s - sa[now.r] + sa[now.r + 1], now.r + 1));
			}
		}
		ll res = sum[K];
		printf("%lld\n", sum[K]);
		for (i = K; sum[i] == sum[K]; i--)
			;
		K -= i;
		build(1, 1, N);
		top = 0;
		dfs(0, res);
	}
	return 0;
}

