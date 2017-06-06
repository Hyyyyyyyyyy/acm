#include <cstdio>
#include <cstring>
const int MIN = -10000000;
using namespace std;

int main()
{
	int i, j, k, u, n, m, ar[10010], sum[10010], begin, end, max, doudou, tbegin, tend;
	while (scanf("%d", &n) != EOF && n)
	{
		doudou = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
			if (ar[i] >= 0)
				doudou = 1;
		}
		if (!doudou)
		{
			printf("0 %d %d\n", ar[1], ar[n]);
			continue;
		}
		max = MIN;
		sum[0] = MIN;
		begin = tbegin = tend = end = ar[1];
		for (i = 1; i <= n; i++)
		{
			if (sum[i - 1] < 0)
			{
				tbegin = ar[i];
				tend = ar[i];
				sum[i] = ar[i];
			}
			else
			{
				tend = ar[i];
				sum[i] = sum[i - 1] + ar[i];
			}
			if (sum[i] > max)
			{
				begin = tbegin;
				end = tend;
				max = sum[i];
			}
		}
		printf("%d %d %d\n", max, begin, end);
	}
	return 0;
}
