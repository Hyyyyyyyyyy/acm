#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int main()
{
	int i, j, k, n, m, u, a, b, bag[30][510], ar[30][510], max, min;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		max = MIN;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf("%d", &a);
				ar[i][a] = 1;
				max = (max < a) ? a : max;
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= max; j++)
			{
				if (i == 1)
					bag[i][j] = 0;
				else
					bag[i][j] = MAX;
			}
		}
		min = MAX;
		for (i = 2; i <= n; i++)
		{
			for (j = 1; j <= max; j++)
			{
				if (!ar[i][j])
					continue;
				for (k = 1; k <= max; k++)
				{
					if (!ar[i - 1][k])
						continue;
					bag[i][j] = (bag[i][j] > bag[i - 1][k] + abs(k - j)) ? (bag[i - 1][k] + abs(k - j)) : bag[i][j];
				}
			}
		}
		for (i = 1; i <= max; i++)
			if (min > bag[n][i])
				min = bag[n][i];
		printf("%d\n", min);
	}
	return 0;
}
