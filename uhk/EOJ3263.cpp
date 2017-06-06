#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1000 + 10;
int ar[maxn];
int N, M, K;
struct Node
{
	int x;
	int y;
	int num;
};
Node edge[maxn];
bool comp(const Node a, const Node b)
{
	return a.y < b.y;
}
int solve()
{
	int i, j, k, sum = 0;
	for (i = 1; i <= M; i++)
	{
		int t = edge[i].num;
		for (j = edge[i].x; j <= edge[i].y; j++)
			if (ar[j])
				t--;
		if (t <= 0)
			continue;
		for (j = edge[i].y; j >= edge[i].x; j--)
		{
			if (!ar[j])
			{
				sum++;
				ar[j]++;
				t--;
			}
			if (t <= 0)
				break;
		}
		if (t > 0)
			return -1;
	}
	return sum;
}
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &N, &M, &K);
			memset(ar, 0, sizeof(ar));
			for (i = 1; i <= K; i++)
			{
				scanf("%d", &a);
				ar[a]++;
			}
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].num);
			}
			sort(edge + 1, edge + 1 + M, comp);
			printf("Case %d: %d\n", m, solve());
		}
	}
	return 0;
}







