#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 300000 + 100;
int N, M, tot, cnt;
int ar[maxn], sta[maxn];
int MAX_UP[maxn];
vector<int>G[maxn];
void dfs(int cur, int pre, int num)
{
	int i, j, u, v;
	int maxup = -1;
	int farmiss = ar[cur] - 1;
	for (i = 0; i < G[cur].size(); i++)
	{
		v = G[cur][i];
		if (v == pre)
			continue;
		dfs(v, cur, num);
	}
	for (i = 0; i < G[cur].size(); i++)
	{
		v = G[cur][i];
		if (v == pre)
			continue;
		if (sta[v] == 1)
		{
			maxup = max(maxup, MAX_UP[v] - 1);
		}
		if (sta[v] == 0)
		{
			farmiss = max(farmiss, MAX_UP[v] + 1);
		}
	}
	if (maxup < farmiss)
	{
		if (farmiss == num)
		{
			tot++;
			MAX_UP[cur] = num;
			sta[cur] = 1;
		}
		else
		{
			MAX_UP[cur] = farmiss;
			sta[cur] = 0;
		}
	}
	else if (maxup >= farmiss)
	{
		MAX_UP[cur] = maxup;
		sta[cur] = 1;
	}
	else
	{
		MAX_UP[cur] = 0;
		sta[cur] = 2;
	}
}
bool check(int num)
{
	int i, j;
	tot = 0;
	dfs(1, -1, num);
	if (sta[1] == 0)
		tot++;
	return tot <= M;
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			G[i].clear();
		}
		for (i = 1; i < N; i++)
		{
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int l = 0;
		int r = N + 1;
		int mid;
		while (r >= l)
		{
			mid = (l + r) / 2;
			if (check(mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
