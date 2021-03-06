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
const int maxn = 10010 + 100;
//轻重树链剖分就是把树的边进行dfs序然后建成线段树进行操作
struct TREE_P
{
	int fa[maxn];   //fa[v]表示v的父亲结点
	int sz[maxn];   //sz[v]表示以v为根的子树的结点个数
	int son[maxn];  //son[v]表示v结点的重儿子
	int pos[maxn];  //pos[v]表示v与其父亲结点所连的边在线段树中的位置
	int deep[maxn]; //deep[v]表示结点v的深度
	int top[maxn];  //top[v]表示v所在的重链的顶端节点
	int P;
	int tot;
	int head[maxn];
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
		int Max;
	};
	Node G[maxn * 4];
	void build(int root, int begin, int end)
	{
		G[root].l = begin;
		G[root].r = end;
		G[root].mid = (begin + end) / 2;
		G[root].Max = 0;
		if (begin == end)
		{
			return;
		}
		build(root * 2, G[root].l, G[root].mid);
		build(root * 2 + 1, G[root].mid + 1, G[root].r);
	}
	void pushup(int root)
	{
		G[root].Max = max(G[root * 2].Max, G[root * 2 + 1].Max);
	}
	void update(int root, int index, int val)
	{
		if (G[root].l == G[root].r && G[root].l == index)
		{
			G[root].Max = val;
			return;
		}
		if (index <= G[root].mid)
			update(root * 2, index, val);
		else
			update(root * 2 + 1, index, val);
		pushup(root);
	}
	int query(int root, int b, int e)
	{
		if (b <= G[root].l && G[root].r <= e)
		{
			return G[root].Max;
		}
		int res = -INF;
		if (b <= G[root].mid)
		{
			res = max(res, query(root * 2, b, e));
		}
		if (e > G[root].mid)
		{
			res = max(res, query(root * 2 + 1, b, e));
		}
		return res;
	}
	int Find(int u, int v)
	{
		int f1 = top[u];
		int f2 = top[v];
		int tmp = 0;
		while (f1 != f2)
		{
			if (deep[f1] < deep[f2])
			{
				swap(f1, f2);
				swap(u, v);
			}
			tmp = max(tmp, query(1, pos[f1], pos[u]));
			u = fa[f1];
			f1 = top[u];
		}
		if (u == v)
			return tmp;
		if (deep[u] > deep[v])
			swap(u, v);
		return max(tmp, query(1, pos[son[u]], pos[v]));
	}
};
TREE_P tree_p;
//tree_p.init()
//以P作为树的结点数
//加双向边
//模板是找区间最大值，单点修改区间查询
int e[maxn][3];
int main()
{
	int i, j, n, m, N, M;
	scanf("%d", &n);
	{
		for (m = 1; m <= n; m++)
		{
			tree_p.init();
			scanf("%d", &N);
			for (i = 0; i < N-1; i++)
			{
				scanf("%d %d %d", &e[i][0], &e[i][1], &e[i][2]);
				tree_p.addedge(e[i][0], e[i][1]);
				tree_p.addedge(e[i][1], e[i][0]);
			}
			tree_p.dfs1(0, 1, 0);
			tree_p.dfs2(1, 1);
			tree_p.build(1, 1, tree_p.P - 1);
			for (i = 0; i < N - 1; i++)
			{
				if (tree_p.deep[e[i][0]] > tree_p.deep[e[i][1]])
				{
					swap(e[i][0], e[i][1]);
				}
				tree_p.update(1, tree_p.pos[e[i][1]], e[i][2]);
			}
			char op[10];
			int u, v;
			while (scanf("%s", op) == 1)
			{
				if (op[0] == 'D')
					break;
				scanf("%d %d", &u, &v);
				if (op[0] == 'Q')
					printf("%d\n", tree_p.Find(u, v));
				else
					tree_p.update(1, tree_p.pos[e[u - 1][1]], v);
			}
		}
	}
	return 0;
}