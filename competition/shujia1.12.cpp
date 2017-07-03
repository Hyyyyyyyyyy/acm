#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 15;
int ar[maxn], sa[maxn], visit[maxn];
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int res = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d", &sa[i]);
		}
		memset(visit, 0, sizeof(visit));
		if (n >= m)
		{
			for (i = 1; i <= n; i++)
			{
				res += ar[i];
			}
			for (i = 1; i <= m; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (ar[j] == sa[i] && !visit[j])
					{
						visit[j] = 1;
						break;
					}
				}
				if (j > n)
				{
					res += sa[i];
				}
			}
		}
		else
		{
			for (i = 1; i <= m; i++)
			{
				res += sa[i];
			}
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= m; j++)
				{
					if (ar[i] == sa[j] && !visit[j])
					{
						visit[j] = 1;
						break;
					}
				}
				if (j > m)
					res += ar[i];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}