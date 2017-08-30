#pragma comment(linker, "/STACK:1024000000,1024000000") 
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
const int maxn = 100005 + 100;
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
int N, M;
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
ll G[maxn * 4], E[maxn * 4];
int ar[maxn][2];
int main()
{
	int i, j, n, m, a, b, c;
	char s[10];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			init();
			for (i = 1; i <= N - 1; i++)
			{
				scanf("%d %d", &ar[i][0], &ar[i][1]);
				addedge(ar[i][0], ar[i][1]);
				addedge(ar[i][1], ar[i][0]);
			}
			dfs1(0, 1, 0);
			dfs2(1, 1);
			memset(G, 0, sizeof(G));
			memset(E, 0, sizeof(E));
			for (i = 1; i <= M; i++)
			{
				scanf("%s", s);
				scanf("%d %d %d", &a, &b, &c);
				if (s[3] == '1')
				{
					int f1 = top[a];
					int f2 = top[b];
					int tmp = 0;
					while (f1 != f2)
					{
						if (deep[f1] < deep[f2])
						{
							swap(f1, f2);
							swap(a, b);
						}
						G[pos[f1]] += c;
						G[pos[a] + 1] -= c;
						a = fa[f1];
						f1 = top[a];
					}
					if (deep[a] > deep[b])
						swap(a, b);
					G[pos[a]] += c;
					G[pos[b] + 1] -= c;
				}
				else
				{
					int f1 = top[a];
					int f2 = top[b];
					int tmp = 0;
					while (f1 != f2)
					{
						if (deep[f1] < deep[f2])
						{
							swap(f1, f2);
							swap(a, b);
						}
						E[pos[f1]] += c;
						E[pos[a] + 1] -= c;
						a = fa[f1];
						f1 = top[a];
					}
					if (deep[a] > deep[b])
						swap(a, b);
					E[pos[a] + 1] += c;
					E[pos[b] + 1] -= c;
				}
			}
			for (i = 2; i <= N; i++)
			{
				G[i] += G[i - 1];
				E[i] += E[i - 1];
			}
			printf("Case #%d:\n", m);

			for (i = 1; i <= N; i++)
			{
				if (i == 1)
					printf("%lld", G[pos[i]]);
				else
					printf(" %lld", G[pos[i]]);
			}
			putchar('\n');

			for (i = 1; i <= N - 1; i++)
			{
				if (deep[ar[i][0]] < deep[ar[i][1]])
					swap(ar[i][0], ar[i][1]);
				if (i == 1)
					printf("%lld", E[pos[ar[i][0]]]);
				else
					printf(" %lld", E[pos[ar[i][0]]]);
			}
			putchar('\n');
		}
	}
	return 0;
}
