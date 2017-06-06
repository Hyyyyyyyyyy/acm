#include <stdio.h>
struct time
{
	long long int high;
	long long int low;
};
int main()
{
	int n, m, i, u;
	struct time point[35];
	point[1].high = 3;
	point[1].low = 1;
	while (scanf("%d", &n) != EOF && n != -1)
	{
		if (n == 0)
			printf("1, 0\n");
		else if (n == 1)
			printf("3, 1\n");
		else
		{
			for (i = 2; i <= n; i++)
			{
				point[i].high = 3 * point[i - 1].high + 2 * point[i - 1].low;
				point[i].low = point[i - 1].high + point[i - 1].low;
			}
			printf("%lld, %lld\n", point[n].high, point[n].low);
		}
	}
	return 0;
}
s