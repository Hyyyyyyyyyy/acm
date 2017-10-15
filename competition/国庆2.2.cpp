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
const int maxn = 10 + 200;
int tot, cnt, N, M;
int vis[maxn];
int id[maxn][maxn];
char s[maxn][maxn];
struct Node
{
	int x;
	int y;
};
Node ar[20];
int main()
{
	int i, j, k, n, m, u;
	while (scanf("%d %d", &N, &M) != EOF && N + M)
	{
		memset(s, '.', sizeof(s));
		cnt = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%s", s[i] + 1);
			for (j = 1; j <= M; j++)
			{
				if (s[i][j] == '.')
				{
					ar[cnt].x = i;
					ar[cnt].y = j;
					id[i][j] = cnt++;
				}
			}
		}
		if (cnt == 0)
		{
			printf("0\n");
			continue;
		}
		int res = INF;
		tot = (1 << cnt);
		for (i = 0; i < tot; i++)
		{
			for (j = 0; j < cnt; j++)
			{
				if (i & (1 << j))
				{
					for (k = 0; k < 4; k++)
					{
						memset(vis, 0, sizeof(vis));
						bool flag = true;
						for (u = 0; u < cnt; u++)
						{
							if (i & (1 << u))
							{
								if (u != j)
								{
									int x = ar[u].x;
									int y = ar[u].y;
									vis[id[x][y]] = 1;
									if (s[x - 1][y] == '#')
										flag = false;
									else
									{
										if (x - 1 >= 1)
											vis[id[x - 1][y]] = 1;
									}
									if (s[x][y + 1] == '#')
										flag = false;
									else
									{
										if (y + 1 <= M)
											vis[id[x][y + 1]] = 1;
									}
									if (!flag)
										break;
								}
							}
						}
						if (!flag)
							continue;
						int x = ar[j].x;
						int y = ar[j].y;
						vis[id[x][y]] = 1;
						if (k == 0)
						{
							if (s[x + 1][y] == '#')
								flag = false;
							else
							{
								if (x + 1 <= N)
									vis[id[x + 1][y]] = 1;
							}
							if (s[x][y + 1] == '#')
								flag = false;
							else
							{
								if (y + 1 <= M)
									vis[id[x][y + 1]] = 1;
							}
						}
						else if (k == 1)
						{
							if (s[x + 1][y] == '#')
								flag = false;
							else
							{
								if (x + 1 <= N)
									vis[id[x + 1][y]] = 1;
							}
							if (s[x][y - 1] == '#')
								flag = false;
							else
							{
								if (y - 1 >= 1)
									vis[id[x][y - 1]] = 1;
							}
						}
						else if (k == 2)
						{
							if (s[x - 1][y] == '#')
								flag = false;
							else
							{
								if (x - 1 >= 1)
									vis[id[x - 1][y]] = 1;
							}
							if (s[x][y - 1] == '#')
								flag = false;
							else
							{
								if (y - 1 >= 1)
									vis[id[x][y - 1]] = 1;
							}
						}
						else
						{
							if (s[x - 1][y] == '#')
								flag = false;
							else
							{
								if (x - 1 >= 1)
									vis[id[x - 1][y]] = 1;
							}
							if (s[x][y + 1] == '#')
								flag = false;
							else
							{
								if (y + 1 <= M)
									vis[id[x][y + 1]] = 1;
							}
						}
						if (!flag)
							continue;
						for (u = 0; u < cnt; u++)
						{
							if (!vis[u])
								flag = false;
						}
						if (!flag)
							continue;
						int count = 0;
						for (u = 0; u < cnt; u++)
							if (i & (1 << u))
								count++;
						res = min(res, count);
					}
				}
			}
		}
		if (res != INF)
			printf("%d\n", res);
		else
			printf("-1\n");
	}
	return 0;
}