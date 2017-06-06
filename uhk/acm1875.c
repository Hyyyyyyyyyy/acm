#include <stdio.h>
#include <math.h>
int main()
{
	int m, n, i, j, u, k, r, count, set[105];
	double  ar[105][3], d, sa[105][3], S, key1, key2, key3;
	while (scanf("%d", &m) != EOF)
	{
		for (i = 1; i <= m; i++)
		{
			scanf("%d", &n);
			for (u = 1; u <= 102; u++)
				set[u] = u;
			for (u = 1; u <= n; u++)
			{
				scanf("%d %d", &ar[u][0], &ar[u][1]);
			}
			r = 1;
			for (u = 1; u <= n; u++)
			{
				for (j = u; j <= n; j++)
				{
					d = pow(pow(ar[u][0] - ar[j][0], 2.0) + pow(ar[u][1] - ar[j][1], 2.0), 1.0 / 2.0);
					sa[r][0] = u;
					sa[r][1] = j;
					sa[r][2] = d;
					key1 = u;
					key2 = j;
					key3 = d;
					k = r - 1;
					while (k > 0 && key3 < sa[k][2])
					{
						sa[k + 1][2] = sa[k][2];
						sa[k + 1][1] = sa[k][1];
						sa[k + 1][0] = sa[k][0];
						k--;
					}
					sa[k + 1][2] = key3;
					sa[k + 1][1] = key2;
					sa[k + 1][0] = key1;

					r++;
				}


			}
			count = 0;
			S = 0.0;
			for (k = 1; k < r; k++)
			{
				if (sa[k][2] < 10 || sa[k][2] > 1000)
					continue;
				while (set[(int)sa[k][0]] != (int)sa[k][0])
					sa[k][0] = set[(int)sa[k][0]];
				while (set[(int)sa[k][1]] != (int)sa[k][1])
					sa[k][1] = set[(int)sa[k][0]];
				if ((int)sa[k][0] != (int)sa[k][1])
				{
					set[(int)sa[k][1]] = (int)sa[k][0];
					count++;
					S += sa[k][2];
					if (count == (n - 1))
						break;
				}
			}
			if (count == (n - 1))
				printf("%.1lf\n", S * 100.0);
			else
				printf("oh!\n");
		}
	}
	return 0;
}
