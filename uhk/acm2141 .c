#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int a[510], b[510], c[510], s, d = 1, temp, i, j, n, m, k, x, y, u, A, B, C, S, D, doudou, set[250010];
	while (scanf("%d %d %d", &A, &B, &C) != EOF)
	{
		for (i = 1; i <= A; i++)
			scanf("%d", &a[i]);
		for (i = 1; i <= B; i++)
			scanf("%d", &b[i]);
		for (i = 1; i <= C; i++)
			scanf("%d", &c[i]);
		u = 1;
		for (i = 1; i <= C; i++)
		{
			for (j = 1; j <= A; j++)
			{
				set[u++] = a[j] + c[i];
			}
		}
		sort(set + 1, set + A*C);
		scanf("%d", &S);
		printf("Case %d:\n", d);
		d++;
		for (n = 1; n <= S; n++)
		{
			scanf("%d", &s);
			doudou = 0;
			for (i = 1; i <= B; i++)
			{
				x = 1;
				y = A*C;
				while (y - x > 1)
				{
					if (s - b[i] < set[(x + y) / 2])
						y = (x + y) / 2;
					else if (s - b[i] > set[(x + y) / 2])
						x = (x + y) / 2;
					else
					{
						doudou = 1;
						break;
					}
				}
				if (doudou)
					break;
			}
			if (doudou)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
