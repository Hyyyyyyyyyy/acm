#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
int N, M, L, cnt;
int F[10010], sum[10010];
struct node
{
	int u;
	int v;
	int w;
};
node edge[50010];
struct que
{
	int l;
	int index;
	int res;
};
que q[10010];
bool comp1(const node& a, const node& b)
{
	return a.w < b.w;
}
bool comp2(const que& a, const que& b)
{
	return a.l < b.l;
}
bool comp3(const que& a, const que& b)
{
	return a.index < b.index;
}
int ans[50010];
int find(int x)
{
	if (F[x] == -1)
		return x;
	else
		return F[x] = find(F[x]);
}
int UNION(int u, int v)
{
	int t1 = find(u);
	int t2 = find(v);
	int t;
	if (t1 == t2)
		return 0;
	else if (sum[t1] > sum[t2])
	{
		F[t2] = t1;
		t = sum[t1] * sum[t2];
		sum[t1] += sum[t2];
		return t;
	}
	else
	{
		F[t1] = t2;
		t = sum[t1] * sum[t2];
		sum[t2] += sum[t1];
		return t;
	}
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		for (i = 0; i <= n; i++)
		{
			sum[i] = 1;
		}
		memset(F, -1, sizeof(F));
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		}
		for (i = 1; i <= k; i++)
		{
			scanf("%d", &q[i].l);
			q[i].res = 0;
			q[i].index = i;
		}
		sort(edge + 1, edge + 1 + m, comp1);
		sort(q + 1, q + 1 + k, comp2);
		int cnt = 1;
		for (i = 1; i <= k; i++)
		{
			while (edge[cnt].w <= q[i].l && cnt <= m)
			{
				q[i].res += UNION(edge[cnt].u, edge[cnt].v);
				cnt++;
			}
			if (i > 1)
				q[i].res += q[i - 1].res;
		}
		sort(q + 1, q + 1 + k, comp3);
		for (i = 1; i <= k; i++)
		{
			printf("%d\n", q[i].res);
		}
	}
	return 0;
}
