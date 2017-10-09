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
typedef unsigned long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e18;
const int maxn = 1000 + 100;
ll B[maxn];
ll S[maxn][30];
// ll M[maxn][30];
// ll D[maxn][30];
int ar[30][30][30];
bool visit[1100];
int main()
{
	ll i, j, k, u, n, m, r, s, d, cnt, a, b;
	while (scanf("%llu %llu %llu %llu %llu", &r, &s, &m, &d, &n) != EOF)
	{
		for (i = 1; i <= r; i++)
		{
			scanf("%llu", &B[i]);
		}
		cnt = 0;
		for (i = 1; i <= s; i++)
		{
			scanf("%llu", &k);
			S[++cnt][0] = k;
			for (j = 1; j <= k; j++)
			{
				scanf("%llu", &S[cnt][j]);
			}
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%llu", &k);
			S[++cnt][0] = k;
			for (j = 1; j <= k; j++)
			{
				scanf("%llu", &S[cnt][j]);
			}
		}
		for (i = 1; i <= d; i++)
		{
			scanf("%llu", &k);
			S[++cnt][0] = k;
			for (j = 1; j <= k; j++)
			{
				scanf("%llu", &S[cnt][j]);
			}
		}
		ll res = 0;
		ll t = 1;
		memset(visit, false, sizeof(visit));
		memset(ar, 0, sizeof(ar));

		for (i = 1; i <= n; i++)
		{
			scanf("%llu %llu", &a, &b);
			if (a > b)
				swap(a, b);
			if (a <= s && b <= s + m && b > s)
			{
				b -= s;
				for (j = 1; j <= d; j++)
				{
					ar[a][b][j] = 1;
				}
			}
			else if (a <= s && b > s + m)
			{
				b -= s + m;
				for (j = 1; j <= m; j++)
				{
					ar[a][j][b] = 1;
				}
			}
			else
			{
				a -= s;
				b -= s + m;
				for (j = 1; j <= s; j++)
				{
					ar[j][a][b] = 1;
				}
			}
		}
		int doudou = 1;
		for (i = 1; i <= s; i++)
		{
			for (j = 1; j <= m; j++)
			{
				for (k = 1; k <= d; k++)
				{
					if (!ar[i][j][k])
					{
						t = 1;
						memset(visit, false, sizeof(visit));
						for (u = 1; u <= S[i][0]; u++)
						{
							if (!visit[S[i][u]])
							{
								
								if (t >= MOD / B[S[i][u]])
								{
									doudou = 0;
									break;
								}
								t *= B[S[i][u]];
								visit[S[i][u]] = true;
							}
						}
						for (u = 1; u <= S[j + s][0]; u++)
						{
							if (!visit[S[j + s][u]])
							{
								
								if (t >= MOD / B[S[j + s][u]])
								{
									doudou = 0;
									break;
								}
								t *= B[S[j + s][u]];
								visit[S[j + s][u]] = true;
							}
						}
						for (u = 1; u <= S[s + m + k][0]; u++)
						{
							if (!visit[S[s + m + k][u]])
							{
								
								if (t > MOD / B[S[s + m + k][u]])
								{
									doudou = 0;
									break;
								}
								t *= B[S[s + m + k][u]];
								visit[S[s + m + k][u]] = true;
							}
						}
						
						if (res > MOD - t)
						{
							doudou = 0;
							break;
						}
						res += t;
					}
				}
				if (!doudou)
					break;
			}
			if (!doudou)
				break;
		}
		if (!doudou)
			printf("too many\n");
		else
			printf("%llu\n", res);
	}
	return 0;
}