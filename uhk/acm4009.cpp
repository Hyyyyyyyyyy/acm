#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
//时间复杂度O(NM);
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e10;
const ll INF = 1e18;
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 1000 + 100;
const int maxm = 1000000 + 100;
struct ZHULIU
{
	struct EDGE
	{
		int u;
		int v;
		int cost;
	};
	EDGE edge[maxm];
	int pre[maxn];
	int id[maxn];
	int visit[maxn];
	int in[maxn];
	int root, N, M;
	int tot;
	int pos;
	void init()
	{
		tot = 0;
	}
	void init(int r, int n, int m)
	{
		root = r;
		N = n;
		M = m;
		tot = 0;
	}
	void addedge(int u, int v, int w)
	{
		edge[tot].u = u;
		edge[tot].v = v;
		edge[tot++].cost = w;
	}
	int zhuliu()
	{
		int res = 0;
		int u, v;
		int i, j;
		while (1)
		{
			for (i = 0; i < N; i++)
				in[i] = inf;
			for (i = 0; i < M; i++)
			{
				u = edge[i].u;
				v = edge[i].v;
				if (u != v && edge[i].cost < in[v])
				{
					pre[v] = u;
					in[v] = edge[i].cost;
					// if(u == root)
					//     pos = i;
				}
			}
			for (i = 0; i < N; i++)
			{
				if (i != root && in[i] == inf)
					return -1;
			}
			int tn = 0;
			memset(visit, -1, sizeof(visit));
			memset(id, -1, sizeof(id));
			in[root] = 0;
			for (i = 0; i < N; i++)
			{
				res += in[i];
				v = i;
				while (visit[v] != i && id[v] == -1 && v != root)
				{
					visit[v] = i;
					v = pre[v];
				}
				if (v != root && id[v] == -1)
				{
					for (u = pre[v]; u != v; u = pre[u])
					{
						id[u] = tn;
					}
					id[v] = tn++;
				}
			}
			if (tn == 0)
				break;
			for (i = 0; i < N; i++)
			{
				if (id[i] == -1)
					id[i] = tn++;
			}
			for (i = 0; i < M; i++)
			{
				v = edge[i].v;
				u = edge[i].u;
				edge[i].u = id[edge[i].u];
				edge[i].v = id[edge[i].v];
				if (id[u] != id[v])
				{
					edge[i].cost -= in[v];
				}
			}
			N = tn;
			root = id[root];
		}
		return res;
	}
};
ZHULIU zhuliu;
//0~N-1, 0~M-1
//pos 用虚拟节点时记录的根
//zhuliu.init(root, N, M);
//构造虚拟节点
//sum为边权和
//for(i = 1; i <= N; i++)
//  addedge(0, i, sum+1);
//inin(0, N+1, N+M);
//if(zhuliu.zhuliu() - (sum+1) >= (sum+1) || zhuliu.zhuliu() == -1)
//  printf("impossible\n");
//else
//  printf("%d %d\n", zhuliu.zhuliu()-(sum+1), pos-M);
struct Node
{
	int x;
	int y;
	int z;
};
Node node[maxn];
int main()
{
	int i, j, k, n, m, a, b, c, X, Y, Z, N;
	while (scanf("%d %d %d %d", &N, &X, &Y, &Z) != EOF && X+Y+Z+N)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			node[i].x = a;
			node[i].y = b;
			node[i].z = c;
		}
		zhuliu.init();
		int sum = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &k);
			for (j = 1; j <= k; j++)
			{
				scanf("%d", &a);
				if (a != i)
				{
					c = abs(node[i].x - node[a].x) + abs(node[i].y - node[a].y) + abs(node[i].z - node[a].z);
					c *= Y;
					if (node[a].z > node[i].z)
						c += Z;
					zhuliu.addedge(i, a, c);
					sum += c;
				}
			}
		}
		zhuliu.root = 0;
		zhuliu.N = N + 1;
		for (i = 1; i <= N; i++)
		{
			zhuliu.addedge(0, i, X*node[i].z);
		}
		zhuliu.M = zhuliu.tot;
		int res = zhuliu.zhuliu();
		printf("%d\n", res);
	}
	return 0;
}