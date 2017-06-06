#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1000000 + 10;
vector<int>G[maxn];
int ar[maxn];
int N, K;
int gcd(int x, int y)
{
	int t;
	while (y)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return  x;
}
int main()
{
	int i, j, k, u, n, m;
	//for (i = 1; i <= 1000001; i++)
	//	G[i].clear();
	for (i = 1; i <= 1000001; i++)
	{
		for (j = 1; i*j <= 1000001; j++)
		{
			G[j*i].push_back(i);
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &K);
			scanf("%d", &ar[1]);
			for (i = 2; i <= N; i++)
			{
				scanf("%d", &ar[i]);
				int t = gcd(ar[i - 1], ar[i]);
				if (i == 2)
					printf("Case %d: ", m);
				if (G[t].size() < K)
					printf("-1 ");
				else
					printf("%d ", G[t][G[t].size() - K]);
			}
			putchar('\n');
		}
	}
	return 0;
}