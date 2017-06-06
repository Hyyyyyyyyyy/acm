#include <stdio.h>
int main()
{
	int n, m, ar[9999], sum;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		ar[0] = 0;
		sum = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &ar[m]);
			if (ar[m] >= ar[m - 1])
			{
				sum += 6 * (ar[m] - ar[m - 1]) + 5;
			}
			else
				sum += 4 * (ar[m - 1] - ar[m]) + 5;
		}
		printf("%d\n", sum);
	}
	return 0;
}

