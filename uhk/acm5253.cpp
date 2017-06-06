#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1000000 + 10;
const int MAX = 100000000;
int ar[1005][1005], F[maxn];
int cnt;
struct node
{
	int u;
	int v;
	int w;
};
node edge[4 * maxn];
bool comp(const node& a, const node& b)
{
	return a.w < b.w;
}
int find(int x)
{
	if (F[x] == -1)
		return x;
	else
		return F[x] = find(F[x]);
}
void addedge(int u, int v, int w)
{
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt++].w = w;
}
int dir[4][2] = { 1, 0, 0, 1 };
int kruskal(int n);
int main()
{
	int i, j, k, n, m, ux, uy, N, M;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					scanf("%d", &ar[i][j]);
				}
			}
			cnt = 0;
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= M; j++)
				{
					for (k = 0; k < 2; k++)
					{
						ux = i + dir[k][0];
						uy = j + dir[k][1];
						if (ux < 1 || uy < 1 || ux > N || uy > M)
							continue;
						addedge((i - 1)*M + j, (ux - 1)*M + uy, abs(ar[i][j] - ar[ux][uy]));
					}
				}
			}
			printf("Case #%d:\n%d\n", m, kruskal(N*M));
		}
	}
	return 0;
}
int kruskal(int n)
{
	memset(F, -1, sizeof(F));
	sort(edge, edge + cnt, comp);
	int i, j, k, ans = 0, count = 0;
	for (i = 0; i < cnt; i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int t1 = find(u);
		int t2 = find(v);
		if (t1 != t2)
		{
			F[t2] = t1;
			ans += w;
			count++;
		}
		if (count == n - 1)
			break;
	}
	if (count < n - 1)
		return 0;
	else
		return ans;
}
