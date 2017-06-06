#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 200000 + 100;
const int INF = 1000000000;
int N, X;
vector<int>G[maxn * 2], F[maxn * 2];
int dep[maxn], head[maxn];
int dfs(int cur, int pre, int num)
{
	int i, j;
	int m = 0;
	if (F[cur].size() == 0)
		return num;
	for (i = 0; i < F[cur].size(); i++)
	{
		int t = dfs(F[cur][i], cur, num + 1);
		if (m < t)
		{
			m = t;
		}
	}
	return m;
}
void dfs1(int cur, int pre, int de)
{
	int i, j;
	dep[cur] = de;
	head[cur] = pre;
	for (i = 0; i < G[cur].size(); i++)
	{
		if (G[cur][i] == pre)
			continue;
		F[cur].push_back(G[cur][i]);
		dfs1(G[cur][i], cur, de + 1);
	}
	return;
}
int main()
{
	int i, j, k, a, b, n, m;
	while (scanf("%d %d", &N, &X) != EOF)
	{
		for (i = 0; i <= N; i++)
		{
			G[i].clear();
			F[i].clear();
		}
		for (i = 1; i < N; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		if (X == 1)
		{
			printf("0\n");
			continue;
		}
		dfs1(1, 0, 0);
		int l = 0;
		int r = X;
		int doudou = 0;
		while (dep[head[r]] > ++l)
		{
			r = head[r];
		}
		int t = dfs(r, head[r], 0);
		if (l < dep[r])
			l++;
		printf("%d\n", 2 * (t + l));
	}
	return 0;
}