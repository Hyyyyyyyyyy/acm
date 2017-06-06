#include <stdio.h>
#include <math.h>
int main()
{
	int n, i, x[120], y[120];
	double S;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
			scanf("%d", &y[i]);
		}
		S = 0;
		for (i = 1; i < n-1; i++)
		{
			S += (1.0 / 2.0) * (double)(x[0] * y[i] + x[i + 1] * y[0] + x[i] * y[i + 1] - x[i + 1] * y[i] - x[0] * y[i + 1] - x[i] * y[0]);
		}
		printf("%.1lf\n", fabs(S));
	}
	return 0;
}
