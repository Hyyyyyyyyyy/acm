#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <cmath>  
#include <algorithm>  
#include <deque>  
using namespace std;
typedef long long ll;
const ll INF = 2147483640;
const ll maxn = 400 + 100;
const ll MOD = 1e9 + 7;
bool visit[maxn][maxn];
int N;
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &N) != EOF)
	{
		memset(visit, false, sizeof(visit));
		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &a, &b);
			a += 100;
			b += 100;
			visit[a][b] = true;
		}
		int res = 0;
		for (i = 0; i <= 202; i++)
		{
			for (j = 0; j <= 202; j++)
			{
				if (visit[i][j])
				{
					for (u = i; u <= 202; u++)
					{
						for (k = j + 1; k <= 202; k++)
						{
							if (visit[u][k])
							{
								int xx = u - i;
								int yy = k - j;
								if (visit[i + yy + xx][j + yy - xx] && visit[i + yy][j - xx])
									res++;
							}
						}
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}