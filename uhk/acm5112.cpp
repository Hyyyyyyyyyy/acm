#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 10000 + 100;
const int maxm = 5000000 + 100;
struct Node
{
	int t;
	int s;
};
Node node[maxn];
bool comp(const Node& a, const Node& b)
{
	return a.t < b.t;
}
int main()
{
	int i, j, k, u, n, m, a, b, N;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d", &node[i].t, &node[i].s);
			}
			sort(node + 1, node + 1 + N, comp);
			double Max = -100000000.0;
			for (i = 2; i <= N; i++)
			{
				double tt = (double)(node[i].s - node[i - 1].s) / (double)(node[i].t - node[i - 1].t);
				tt = fabs(tt);
				Max = max(Max, tt);
			}
			printf("Case #%d: %.2f\n", m, Max);
		}
	}
	return 0;
}