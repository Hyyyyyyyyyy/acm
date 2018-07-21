#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
#define retrun return
const int inf = 1e8;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 10000 + 100;
const int maxm = 1000000 + 100;
int N, K;
struct Node
{
	int r;
	int c;
	int id;
};
Node ar[maxn];

bool comp1(Node a, Node b)
{
	return a.r < b.r;
}
bool comp2(Node a, Node b)
{
	return a.c < b.c;
}
int fa[maxn];
int Find(int u)
{
	if (fa[u] != -1)
		return (fa[u] = Find(fa[u]));
	return u;
}
void Union(int u, int v)
{
	int a = Find(u);
	int b = Find(v);
	if (a != b)
	{
		fa[b] = a;
	}
}
int main()
{
	int i, j, k, cas, CAS;
	while (scanf("%d", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%d %d", &N, &K);
			memset(fa, -1, sizeof(fa));
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &ar[i].r, &ar[i].c);
				ar[i].id = i;
			}
			sort(ar + 1, ar + 1 + N, comp1);
			for (i = 2; i <= N; i++)
			{
				if (ar[i].r - ar[i - 1].r <= K)
				{
					Union(ar[i-1].id, ar[i].id);
				}
			}
			sort(ar + 1, ar + 1 + N, comp2);
			for (i = 2; i <= N; i++)
			{
				if (ar[i].c - ar[i - 1].c <= K)
				{
					Union(ar[i - 1].id, ar[i].id);
				}
			}
			int res = 0;
			for (i = 1; i <= N; i++)
			{
				if (fa[i] == -1)
					res++;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
//像这种相隔多远可以连接的问题，要想到并查集！