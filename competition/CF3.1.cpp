#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1000 + 100;
int ar[maxn], sa[maxn];
struct Edge
{
	int l;
	int r;
	int len;
};
Edge edge[maxn];
int visit[100010];
int N, M;
bool comp(const Edge& a, const Edge& b)
{
	return a.r < b.l;
}
int main()
{
	int i, j, k, u, n, m, a, b, Max;
	while (scanf("%d", &N) != EOF)
	{
		int sum = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			sum += ar[i];
		}
		scanf("%d", &M);
		memset(visit, 0, sizeof(visit));
		Max = -1;
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d", &edge[i].l, &edge[i].r);
			edge[i].len = edge[i].r - edge[i].l + 1;
			visit[edge[i].l]++;
			visit[edge[i].r + 1]--;
			if (Max < edge[i].r)
				Max = edge[i].r;
		}
		for (i = 1; i <= Max; i++)
		{
			visit[i] += visit[i - 1];
			if (i >= sum && visit[i])
				break;
		}
		if (i <= Max)
			printf("%d\n", i);
		else
			printf("-1\n");
	}
	return 0;
}