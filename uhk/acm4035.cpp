#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 10000 + 100;
vector<int>G[maxn];
double A[maxn], B[maxn], C[maxn], E[maxn], K[maxn];
const double eps = 1.0e-9;
int N, M;
bool dfs(int cur, int pre)
{
	int i, j;
	int num = G[cur].size();
	A[cur] = K[cur];
	B[cur] = (1.0 - K[cur] - E[cur]) / (double)num;
	C[cur] = 1.0 - K[cur] - E[cur];
	double t = 0.0;
	for (i = 0; i < num; i++)
	{
		if (G[cur][i] == pre)
			continue;
		if (!dfs(G[cur][i], cur))
		{
			return false;
		}
		A[cur] += (1.0 - K[cur] - E[cur]) / num * A[G[cur][i]];
		C[cur] += (1.0 - K[cur] - E[cur]) / num * C[G[cur][i]];
		t += (1.0 - K[cur] - E[cur]) / num * B[G[cur][i]];
	}
	if (fabs(t - 1.0) < eps)
	{
		return false;
	}
	A[cur] /= (1.0 - t);
	B[cur] /= (1.0 - t);
	C[cur] /= (1.0 - t);
	return true;
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 0; i <= N; i++)
				G[i].clear();
			for (i = 1; i < N; i++)
			{
				scanf("%d %d", &a, &b);
				G[a].push_back(b);
				G[b].push_back(a);
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%lf %lf", &K[i], &E[i]);
				K[i] /= 100.0;
				E[i] /= 100.0;
			}
			if (dfs(1, -1) && fabs(1.0 - A[1]) > eps)
			{
				printf("Case %d: %.6f\n", m, C[1] / (1.0 - A[1]));
			}
			else
			{
				printf("Case %d: impossible\n", m);
			}
		}
	}
	return 0;
}