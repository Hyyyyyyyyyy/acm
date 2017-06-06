#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int F[100010];
struct node
{
	int u;
	int v;
	int w;
	int sta;
	double cost;
};
node edge[100010];
int tot;
long long M;
void addedge(int x, int y, int z, int f)
{
	edge[tot].u = x;
	edge[tot].v = y;
	edge[tot].sta = f;
	edge[tot++].w = z;
}
bool comp(node a, node b)
{
	return a.cost < b.cost;
}
int find(int x)
{
	if (F[x] == -1)
		return x;
	else
		return F[x] = find(F[x]);
}
double kruskal(int n)
{
	int i;
	memset(F, -1, sizeof(F));
	sort(edge, edge + tot, comp);
	int cnt = 0;
	double ans = 0;
	for (i = 0; i < tot; i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		double w = edge[i].cost;
		int t1 = find(u);
		int t2 = find(v);
		if (t1 != t2)
		{
			ans += w;
			F[t1] = t2;
			cnt++;
		}
		if (cnt == n - 1)
			break;
	}
	if (cnt < n - 1 || ans > M)
		return -1.0;
	else
		return ans;
}
int main()
{
	int i, j, k, u, n, m, a, b, c, d;
	while (scanf("%d %d %lld", &n, &m, &M) != EOF)
	{
		tot = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			addedge(a, b, c, d);
			//addedge(b, a, c, d);
		}
		double l = 1.0;
		double r = (double)M;
		double mid = (l + r) / 2.0;
		while (r - l >= 1.0e-8)
		{
			for (i = 0; i < tot; i++)
			{
				if (edge[i].sta == 1)
				{
					edge[i].cost = 1.0 * edge[i].w*mid;
				}
				else
				{
					edge[i].cost = 1.0*edge[i].w;
				}
			}
			if (kruskal(n) + 1 < 1.0e-8)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
			mid = (l + r) / 2.0;
		}
		printf("%.6f\n", mid);
	}
	return 0;
}
