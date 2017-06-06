#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <deque>
using namespace std;
const int MIN = -100000000;
const int MAX = 100000000;
typedef long long ll;
vector<int>G[100010];
int pre[100010], node[100010][7];
void dfs(int *fa, int n);
int main()
{
	int i, j, k, u, n, m, a, b, c, res, doudou;
	while(scanf("%d", &n) != EOF)
	{
		for(m = 1; m <= n; m++)
		{
			memset(node, 0, sizeof(node));
			scanf("%d", &k);
			for(i = 0; i <= k; i++)
			{
				G[i].clear();
				node[i][0] = 1;
			}
			for(i = 1; i < k; i++)
			{
				scanf("%d %d", &a, &b);
				G[a].push_back(b);
				G[b].push_back(a);
			}
			int fa[] = {0, 0, 0, 0, 0, 0};
			dfs(fa, 1);
			res = 0;
			for(i = 1; i <= k; i++)
			{
				res = 0;
				for(j = 1; j <= 6; j++)
					res += node[i][j];
				c = i;
				for(u = 1; u <= 6; u++)
				{
					b = c;
					c = pre[c];
					if(c == 0)
						break;
					for(j = 0; j <= 6-u; j++)
						res += node[c][j];
					for(j = 0; j <= 6-u-1; j++)
						res -= node[b][j];
				}
				if(i == 1)
					printf("Case #%d:\n", m);
				printf("%d\n", res);
			}
		}
	}
	return 0;
}
void dfs(int *fa, int n)
{
	int i, j, k;
	pre[n] = fa[5];
	for(i = 0; i <= 5; i++)
	{
		node[fa[i]][6-i]++;
	}
	int f[] = {fa[1], fa[2], fa[3], fa[4], fa[5], n};
	for(i = 0; i < G[n].size(); i++)
	{
		if(G[n][i] != fa[5])
		{
			dfs(f, G[n][i]);
		}
	}
}
