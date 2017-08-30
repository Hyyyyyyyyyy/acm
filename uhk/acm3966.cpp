#pragma comment(linker,"/STACK:100000000,100000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 50000 + 100;
//轻重树链剖分就是把树的边进行dfs序然后建成线段树进行操作
int fa[maxn];   //fa[v]表示v的父亲结点
int sz[maxn];   //sz[v]表示以v为根的子树的结点个数
int son[maxn];  //son[v]表示v结点的重儿子
int pos[maxn];  //pos[v]表示v与其父亲结点所连的边在线段树中的位置
int deep[maxn]; //deep[v]表示结点v的深度
int top[maxn];  //top[v]表示v所在的重链的顶端节点
int P;
int tot;
int head[maxn];
int ar[maxn];
struct Edge
{
	int to;
	int next;
};
Edge edge[maxn * 2];
void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
	P = 1;
	memset(son, -1, sizeof(son));
}
void addedge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
//dfs序,找deep,fa,sz,son
void dfs1(int pre, int u, int dep)
{
	deep[u] = dep;
	fa[u] = pre;
	sz[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v != pre)
		{
			dfs1(u, v, dep + 1);
			sz[u] += sz[v];
			if (son[u] == -1 || sz[son[u]] < sz[v])
			{
				son[u] = v;
			}
		}
	}
}
//找top,pos;
void dfs2(int u, int first)
{
	top[u] = first;
	if (son[u] != -1)
	{
		pos[u] = P++;
		dfs2(son[u], first);
	}
	else
	{
		pos[u] = P++;
		return;
	}
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v != son[u] && v != fa[u])
		{
			dfs2(v, v);
		}
	}
}
//线段树
struct Node
{
	int l;
	int r;
	int mid;
	int res;
	int visit;
};
Node G[maxn * 4];
void pushup(int root)
{
	G[root].res = G[root * 2].res + G[root * 2 + 1].res;
}
void pushdown(int root)
{
	if (G[root].visit)
	{
		G[root * 2].visit += G[root].visit;
		G[root * 2 + 1].visit += G[root].visit;
		G[root * 2].res += G[root].visit * (G[root].mid - G[root].l + 1);
		G[root * 2 + 1].res += G[root].visit * (G[root].r - G[root].mid);
		G[root].visit = 0;
	}
}
void build(int root, int begin, int end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	G[root].res = 0;
	G[root].visit = 0;
	if (begin == end)
	{
		return;
	}
	build(root * 2, G[root].l, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, G[root].r);
}
void update2(int root, int index, int val)
{
	if (G[root].l == G[root].r && G[root].l == index)
	{
		G[root].res = val;
		return;
	}
	if (index <= G[root].mid)
		update2(root * 2, index, val);
	else
		update2(root * 2 + 1, index, val);
	pushup(root);
}
void update(int root, int b, int e, int val)
{
	if (b <= G[root].l && G[root].r <= e)
	{
		G[root].res += val * (G[root].r - G[root].l + 1);
		G[root].visit += val;
		return;
	}
	pushdown(root);
	if (b <= G[root].mid)
		update(root * 2, b, e, val);
	if (e > G[root].mid)
		update(root * 2 + 1, b, e, val);
	pushup(root);
}
int query(int root, int index)
{
	if (G[root].l == G[root].r && G[root].r == index)
	{
		return G[root].res;
	}
	pushdown(root);
	int res;
	if (index <= G[root].mid)
	{
		res = query(root * 2, index);
	}
	else
	{
		res = query(root * 2 + 1, index);
	}
	return res;
}
int main()
{
	int i, j, N, M, n, m, a, b, c, Q;
	while (scanf("%d %d %d", &N, &M, &Q) != EOF)
	{
		init();
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &a, &b);
			addedge(a, b);
			addedge(b, a);
		}
		dfs1(0, 1, 0);
		dfs2(1, 1);
		build(1, 1, P-1);
		//printf("%d %d\n", P, N);
		for (i = 1; i <= N; i++)
		{
			update2(1, pos[i], ar[i]);
		}
		char s[10];
		for (i = 1; i <= Q; i++)
		{
			scanf("%s", s);
			if (s[0] == 'I')
			{
				scanf("%d %d %d", &a, &b, &c);
				int f1 = top[a];
				int f2 = top[b];
				while (f1 != f2)
				{
					if (deep[f1] < deep[f2])
					{
						swap(f1, f2);
						swap(a, b);
					}
					update(1, pos[f1], pos[a], c);
					a = fa[f1];
					f1 = top[a];
				}
				if (deep[a] > deep[b])
					swap(a, b);
				update(1, pos[a], pos[b], c);
			}
			else if (s[0] == 'D')
			{
				scanf("%d %d %d", &a, &b, &c);
				c = -c;
				int f1 = top[a];
				int f2 = top[b];
				while (f1 != f2)
				{
					if (deep[f1] < deep[f2])
					{
						swap(f1, f2);
						swap(a, b);
					}
					update(1, pos[f1], pos[a], c);
					a = fa[f1];
					f1 = top[a];
				}
				if (deep[a] > deep[b])
					swap(a, b);
				update(1, pos[a], pos[b], c);
			}
			else
			{
				scanf("%d", &a);
				printf("%d\n", query(1, pos[a]));
			}
		}
	}
	return 0;
}