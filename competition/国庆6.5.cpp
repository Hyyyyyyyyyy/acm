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
const ll MOD = 1e18;
const int maxn = 200000 + 100;
const int maxm = 1000000 + 100;
vector<int>G[maxn];
vector<int>F[maxn];
set<int>S;
char s[maxn][5];
int deep[maxn];
void dfs(int u, int dep)
{
	int i, j;
	S.erase(u);
	deep[u] = dep;
	if (s[u][0] == 'C')
	{
		for (i = 0; i < G[u].size(); i++)
		{
			if (S.find(G[u][i]) != S.end())
			{
				dfs(G[u][i], dep + 1);
			}
		}
	}
	else
	{
		set<int>::iterator it = S.begin();
		while (it != S.end())
		{
			int t = *it;
			for (i = 0; i < F[u].size() && F[u][i] < t; i++);
			if (i < F[u].size() && F[u][i] == t)
			{
				it++;
				continue;
			}
			dfs(t, dep + 1);
			it = S.upper_bound(t);
		}
	}
}
int main()
{
	int i, j, k, n, m, a, b, N, doudou;
	while (scanf("%d", &N) != EOF)
	{
		if (N <= 1)
		{
			doudou = 0;
		}
		doudou = 1;
		for (i = 0; i <= N; i++)
		{
			G[i].clear();
			F[i].clear();
		}
		for (m = 1; m <= N; m++)
		{
			scanf("%s", s[m]);
			if (s[m][0] == 'C')
			{
				scanf("%d", &k);
				if (k == 0)
					doudou = 0;
				for (i = 1; i <= k; i++)
				{
					scanf("%d", &a);
					G[m].push_back(a);
				}
			}
			else
			{
				scanf("%d", &k);
				if (k == N - 1)
					doudou = 0;
				for (i = 1; i <= k; i++)
				{
					scanf("%d", &a);
					F[m].push_back(a);
				}
				sort(F[m].begin(), F[m].end());
			}
		}
		if (!doudou)
		{
			printf("Impossible\n");
			continue;
		}
		for (i = 1; i <= N; i++)
			S.insert(i);
		for (i = 1; i <= N; i++)
		{
			if (S.find(i) != S.end())
			{
				dfs(i, 1);
			}
		}
		for (i = 1; i <= N; i++)
		{
			if (deep[i] & 1)
				printf("S");
			else
				printf("V");
		}
		putchar('\n');
	}
	return 0;
}