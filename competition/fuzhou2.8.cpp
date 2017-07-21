#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cctype>
#include <set>
using namespace std;
const int INF = 1e10;
const double eps = 1e-8;
typedef long long ll;
const int maxn = 1000;
int ar[maxn][maxn], visit[maxn][maxn], path[maxn][maxn], Set[maxn][maxn];
int res;
int N, M;
void floyd()
{
	int i, j, k;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (i == j)
			{
				continue;
			}
			for (k = 1; k <= N; k++)
			{
				if (ar[k][j] != INF && ar[i][k] != INF && ar[i][k] + ar[k][j] < ar[i][j])
				{
					ar[i][j] = ar[i][k] + ar[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &M);
			for (i = 0; i <= N; i++)
			{
				for (j = 0; j <= N; j++)
				{
					ar[i][j] = INF;
                    if(i == j)
                        ar[i][j] = 0;
					path[i][j] = j;
				}
			}
			memset(visit, 0, sizeof(visit));
            memset(Set, 0, sizeof(Set));
			res = 0;
			for (i = 1; i <= M; i++)
			{
				scanf("%d %d %d", &a, &b, &c);
				if (ar[a][b] > c)
				{
					ar[a][b] = ar[b][a] = c;
				}
			}
			floyd();
			for (i = 1; i <= N; i++)
			{
				for (j = 1; j <= N; j++)
				{
					if (i != j && ar[i][j] != INF && !Set[i][j])
					{
                        int u = i;
                        int v = j;
                        Set[i][j] = 1;
						while(u != v)
                        {
                            if(!visit[u][path[u][v]])
                                res++;
                            visit[u][path[u][v]] = 1;
                            Set[u][path[u][v]] = 1;
                            u = path[u][v];
                        }
					}
				}
			}
			printf("Case %d: %d\n", m, M - res);
		}
	}
	return 0;
}