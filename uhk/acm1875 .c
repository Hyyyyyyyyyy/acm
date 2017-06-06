#include <stdio.h>
#include <math.h>
struct zu {
	int zheng[9999][2];
	double buzheng[9999];
};
int main()
{
	int m, n, i, j, u, k, r, count, set[105], key1, key2, a, b;
	double d, S, key3, ar[105][3];
	struct zu sa;
	while (scanf("%d", &m) != EOF)
	{
		for (i = 1; i <= m; i++)
		{
			scanf("%d", &n);
			for (u = 1; u <= n; u++)
			{
				scanf("%lf %lf", &ar[u][0], &ar[u][1]);
			}
			r = 1;
			for (u = 1; u <= n; u++)
			{
				for (j = u + 1; j <= n; j++)
				{
					d = pow(pow(ar[u][0] - ar[j][0], 2.0) + pow(ar[u][1] - ar[j][1], 2.0), 0.5);
					sa.zheng[r][0] = u;
					sa.zheng[r][1] = j;
					sa.buzheng[r] = d;
					key1 = u;
					key2 = j;
					key3 = d;
					k = r - 1;
					while (k > 0 && key3 < sa.buzheng[k])
					{
						sa.buzheng[k + 1] = sa.buzheng[k];
						sa.zheng[k + 1][1] = sa.zheng[k][1];
						sa.zheng[k + 1][0] = sa.zheng[k][0];
						k--;
					}
					sa.buzheng[k + 1] = key3;
					sa.zheng[k + 1][1] = key2;
					sa.zheng[k + 1][0] = key1;

					r++;
				}

			}
			for (u = 1; u <= 102; u++)
				set[u] = u;

			count = 0;
			S = 0.0;
			for (k = 1; k <= n*(n - 1) / 2; k++)
			{
                a = sa.zheng[k][0];
                b = sa.zheng[k][1];
				if (sa.buzheng[k] < 10.0 || sa.buzheng[k] > 1000.0)
					continue;
				while (set[sa.zheng[k][0]] != sa.zheng[k][0])
				{
					sa.zheng[k][0] = set[sa.zheng[k][0]];
				}
				while (set[sa.zheng[k][1]] != sa.zheng[k][1])
				{
					sa.zheng[k][1] = set[sa.zheng[k][1]];
				}
				if (sa.zheng[k][0] != sa.zheng[k][1])
				{
					set[sa.zheng[k][1]] = sa.zheng[k][0];
					count++;
					S += sa.buzheng[k];
					if (count == (n - 1))
						break;
				}
                while(a != sa.zheng[k][0])
                {
                    temp = set[a];
                    set[a] = sa.zheng[k][0];
                    a = temp;
                }
                while(b != sa.zheng[k][1])
                {
                    temp = set[b];
                    set[b] = sa.zheng[k][0];
                    b = temp;
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
