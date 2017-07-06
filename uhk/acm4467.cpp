#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 100;
struct Point
{
	int u;
	int v;
	ll w;
};
Point point[maxn];
struct Edge
{
	int v;
	int next;
	ll w;
};
Edge edge[maxn * 2];
int head[maxn * 2][2];
int ar[maxn], du[maxn], judge[maxn];
ll res[3], sum[maxn][2];
int tot,N, M;
bool comp(const Point& a, const Point& b)
{
	if (a.u != b.u)
		return a.u < b.u;
	else
		return a.v < b.v;
}
void addedge(int a, int b, ll c, int t)
{
	edge[tot].v = b;
	edge[tot].w = c;
	edge[tot].next = head[a][t];
	head[a][t] = tot++;
}
int main()
{
	int i, j, k, u, n, m, a, b, cas = 1;
	ll c;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(head, -1, sizeof(head));
		memset(du, 0, sizeof(du));
		memset(judge, 0, sizeof(judge));
		memset(res, 0, sizeof(res));
		memset(sum, 0, sizeof(sum));
		tot = 0;
		for (i = 1; i <= N; i++)
			scanf("%d", &ar[i]);
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d %lld", &point[i].u, &point[i].v, &point[i].w);
			if (point[i].u > point[i].v)
				swap(point[i].u, point[i].v);
		}
		int cnt = 0;
		sort(point + 1, point + 1 + M, comp);
		for (i = 1; i <= M; i = j)
		{
			point[++cnt] = point[i];
			for (j = i + 1; j <= M; j++)
			{
				if (!(point[i].u == point[j].u && point[i].v == point[j].v))
					break;
				point[cnt].w += point[j].w;
			}
		}
		for (i = 1; i <= cnt; i++)
		{
			du[point[i].u]++;
			du[point[i].v]++;
		}
		int limit = sqrt(cnt * 2);
		for (i = 1; i <= N; i++)
		{
			if (du[i] >= limit)
				judge[i] = 1;
		}
		for (i = 1; i <= cnt; i++)
		{
			if (judge[point[i].u])
			{
				addedge(point[i].v, point[i].u, point[i].w, 1);
			}
			else
			{
				addedge(point[i].u, point[i].v, point[i].w, 0);
			}
			if (judge[point[i].v])
			{
				addedge(point[i].u, point[i].v, point[i].w, 1);
			}
			else
			{
				addedge(point[i].v, point[i].u, point[i].w, 0);
			}
		}
		for (i = 1; i <= cnt; i++)
		{
			int u = point[i].u;
			int v = point[i].v;
			ll w = point[i].w;
			if (judge[u])
			{
				sum[u][ar[v]] += w;
			}
			if (judge[v])
			{
				sum[v][ar[u]] += w;
			}
			res[ar[u] + ar[v]] += w;
		}
		printf("Case %d:\n", cas++);
		int K;
		char s[20];
		scanf("%d", &K);
		for (k = 1; k <= K; k++)
		{
			scanf("%s", s);
			if (strcmp(s, "Asksum") == 0)
			{
				scanf("%d %d", &a, &b);
				printf("%lld\n", res[a + b]);
			}
			else
			{
				scanf("%d", &a);
				if (judge[a])
				{
					res[ar[a] + 0] -= sum[a][0];
					res[(ar[a] ^ 1) + 0] += sum[a][0];
					res[ar[a] + 1] -= sum[a][1];
					res[(ar[a] ^ 1) + 1] += sum[a][1];
				}
				else
				{
					for (i = head[a][0]; i != -1; i = edge[i].next)
					{
						int v = edge[i].v;
						ll w = edge[i].w;
						res[ar[a] + ar[v]] -= w;
						res[(ar[a] ^ 1) + ar[v]] += w;
					}
				}
				for (i = head[a][1]; i != -1; i = edge[i].next)
				{
					int v = edge[i].v;
					ll w = edge[i].w;
					sum[v][ar[a]] -= w;
					sum[v][ar[a] ^ 1] += w;
				}
				ar[a] ^= 1;
			}
		}
	}
	return 0;
}