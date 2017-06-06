#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 100;
int bag[maxn][50];
int dp1[maxn];
int dp2[maxn];
int volume[maxn];
int val[maxn];
int N, V, K;
bool comp(const int a, const int b)
{
	return a > b;
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &N, &V, &K);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &val[i]);
			}
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &volume[i]);
			}
			memset(bag, 0, sizeof(bag));
			for (i = 1; i <= N; i++)
			{
				for (j = V; j >= volume[i]; j--)
				{
					for (k = 1; k <= K; k++)
					{
						dp1[k] = bag[j - volume[i]][k] + val[i];
						dp2[k] = bag[j][k];
					}
					dp1[k] = dp2[k] = -1;
					a = b = c = 1;
					while (c <= K && (dp1[a] != -1 || dp2[b] != -1))
					{
						if (dp1[a] > dp2[b])
						{
							bag[j][c] = dp1[a++];
						}
						else
						{
							bag[j][c] = dp2[b++];
						}
						if (bag[j][c] != bag[j][c - 1])
							c++;
					}
				}
			}
			printf("%d\n", bag[V][K]);
		}
	}
	return 0;
}
