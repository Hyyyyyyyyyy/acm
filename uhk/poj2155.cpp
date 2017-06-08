#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int ar[maxn][maxn];
int c[maxn][maxn];
int N, T;
void update(int x, int y)
{
	int i, j;
	for (i = x; i <= N; i += (i & (-i)))
	{
		for (j = y; j <= N; j += (j & (-j)))
		{
			c[i][j]++;
		}
	}
}
int sum(int x, int y)
{
	int i, j;
	int res = 0;
	for (i = x; i; i -= (i & (-i)))
	{
		for (j = y; j; j -= (j & (-j)))
		{
			res += c[i][j];
		}
	}
	return res % 2;
}
int main()
{
	int i, j, k, u, n, m, x1, y1, x2, y2;
	char s[5];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &N, &T);
			memset(c, 0, sizeof(c));
			for (i = 1; i <= T; i++)
			{
				scanf("%s", s);
				if (strcmp(s, "C") == 0)
				{
					scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
					update(x1, y1);
					update(x1, y2 + 1);
					update(x2 + 1, y1);
					update(x2 + 1, y2 + 1);
				}
				else
				{
					scanf("%d %d", &x1, &y1);
					printf("%d\n", sum(x1, y1));
				}
			}
			putchar('\n');
		}
	}
	return 0;
}