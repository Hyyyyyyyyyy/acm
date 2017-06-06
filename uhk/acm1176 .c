#include <stdio.h>
#include <string.h>
int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}
}
int main()
{
	int n, m, i, j, x, t, mtime, msum, k, u, ar[13][100010], s[13][100010];
	while (scanf("%d", &n) != EOF && n != 0)
	{
		memset(ar, 0, sizeof(int) * 13 * 100010);
		mtime = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &x, &t);
			mtime = (mtime > t) ? mtime : t;
			ar[x][t]++;
		}
		for (x = 0; x <= 11; x++)
			s[x][mtime+1] = 0;

		for (t = mtime; t > 0; t--)
		{
			for (x = 0; x <= 10; x++)
			{
				if (x == 0)
				{
					s[x][t] = ((s[x][t + 1] + ar[x][t]) > (s[x + 1][t + 1] + ar[x + 1][t])) ? (s[x][t + 1] + ar[x][t]) : (s[x + 1][t + 1] + ar[x + 1][t]);
					continue;
				}
				s[x][t] = max((ar[x - 1][t] + s[x - 1][t +1]), (ar[x][t] + s[x][t + 1]), (ar[x + 1][t] + s[x + 1][t + 1]));
			}
		}

		printf("%d\n", s[5][1]);
	}
	return 0;
}
