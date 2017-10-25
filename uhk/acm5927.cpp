#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 2147483647;
const ll INF = 9223372036854775807;
const double eps = 1e-8;
const int maxn = 100000 + 100;
int son[maxn], fa[maxn], dep[maxn], sonn[maxn];
vector<int>G[maxn];
int unim[maxn];
void dfs(int u, int f, int depth)
{
	dep[u] = depth;
	son[u] = 0;
	fa[u] = f;
	for (int i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != f)
		{
			son[u]++;
			dfs(G[u][i], u, depth + 1);
		}
	}
}
bool comp(int a, int b)
{
	return dep[a] > dep[b];
}
int main()
{
	int i, j, k, n, m, a, b, q, N, Q;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &Q);
			for (i = 0; i <= N; i++)
				G[i].clear();
			memset(unim, 0, sizeof(unim));
			for (i = 1; i <= N - 1; i++)
			{
				scanf("%d %d", &a, &b);
				G[a].push_back(b);
				G[b].push_back(a);
			}
			dfs(1, 0, 0);
			printf("Case #%d:\n", m);
			for (q = 1; q <= Q; q++)
			{
				scanf("%d", &k);
				for (i = 1; i <= k; i++)
				{
					scanf("%d", &a);
					unim[i] = a;
                }
                sort(unim + 1, unim + 1 + k, comp);
				for (i = 1; i <= k; i++)
				{
					sonn[unim[i]] = son[unim[i]];
				}
				
				int res = 0;
				for (i = 1; i <= k; i++)
				{
					if (sonn[unim[i]] >= 2)
						res++;
					else if (sonn[unim[i]] == 0)
						sonn[fa[unim[i]]]--;
				}
				printf("%d\n", res + N - k);
			}
		}
	}
	return 0;
}