#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 100;
int ar[maxn][maxn];
int all[maxn][maxn], some[maxn][maxn], none[maxn][maxn];
int N, M, RES, ANS;
void dfs(int dep, int an, int sn, int nn)
{
	int i, j, k;
	if (sn == 0 && nn == 0)
		RES++;
	if (RES > 1000)
		return;
	int u = some[dep][1];
	for (i = 1; i <= sn; i++)
	{
		int v = some[dep][i];
		int tsn = 0;
		int tnn = 0;
		if (ar[u][v])
			continue;
		for (j = 1; j <= dep; j++)
		{
			all[dep + 1][j] = all[dep][j];
		}
		all[dep + 1][an + 1] = v;
		for (j = 1; j <= sn; j++)
		{
			if (ar[some[dep][j]][v])
				some[dep + 1][++tsn] = some[dep][j];
		}
		for (j = 1; j <= nn; j++)
		{
			if (ar[none[dep][j]][v])
				none[dep + 1][++tnn] = none[dep][j];
		}
		dfs(dep + 1, an + 1, tsn, tnn);
		some[dep][i] = 0;
		none[dep][++nn] = v;
	}
}
int main()
{
	int i, j, k, a, b, n, m;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		for (m = 1; m <= M; m++)
		{
			scanf("%d %d", &a, &b);
			ar[a][b] = ar[b][a] = 1;
		}
		RES = 0;
		for (i = 1; i <= N; i++)
		{
			some[1][i] = i;
		}
		dfs(1, 0, N, 0);
		if (RES > 1000)
			printf("Too many maximal sets of friends.\n");
		else
			printf("%d\n", RES);
	}
	return 0;
}