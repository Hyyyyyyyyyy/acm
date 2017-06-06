#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &a, &b, &k);
			printf("%.3lf\n", 1.0 * b / (1.0 * (a+b)));
		}
	}
	return 0;
}
